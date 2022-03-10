
//Program that uses the COM IPC Object Mechanisms
//Program will run on any machine with Windows 2000 or later.

#include <windows.h>
#include <combaseapi.h>
#include <iostream>
#include <objbase.h>
#include <unknwn.h>
#include <wtypesbase.h>
#include <winerror.h>
#include <rpcdce.h>
using namespace std;

int main(int argc, char const *argv[])
{

    HRESULT hr;
    DWORD dwClass = COINIT_MULTITHREADED;
    // LPVOID **ppv;

    hr = CoInitializeEx( NULL, dwClass ); 

    if (SUCCEEDED(hr)){
        cout << "COM Thread Established" << endl;
        
        DWORD     dwClsContext = CLSCTX_INPROC_SERVER;
        IClassFactory *ppv = 0;
        GUID *pGuid = 0x00;
        pGuid = new GUID;

        hr = CoCreateGuid(pGuid);

        if(SUCCEEDED(hr)){
            cout << "Attempting to create COM Object." << endl;

            hr = CoCreateInstance( *pGuid, NULL, dwClsContext, IID_PPV_ARGS(&ppv) );
            
            if (SUCCEEDED(hr)){
                cout << "COM Object Created" <<  endl;
            



            } else {
                cout << "Object creation did not work correctly.\t"  << endl;

            }

        }else{
            cout << "GUID Creation failed" << endl;
        }



        cout << "COM thread will be uninitialized now." << endl;
        CoUninitialize();




    }else{
        cout << "COM thread could not be created. Please try again." << endl;
        return 0;
    }


    return 0;
}

