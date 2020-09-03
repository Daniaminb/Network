#include <iostream>
#include "Server.h"
#include "Exception.h"
using namespace std;
int main(int argc, char* argv[])
{
    if (argc < 2){
        cout << "not enough argument" << endl;
        return 0;
    }
    else if (argc < 4){
        Server* server_host = new Server(argv[1], argv[2],1);
        try
        {
            server_host->bindHost();
        }
        catch(BindException e)
        {
            cout << e.what() << endl;
        }
        try
        {
            server_host->udp_recieveBytes();
        }
        catch(RecieveException e)
        {
            cout << e.what() << endl;
        }
    }
    else
    {
       cout << "So many argument" << endl;
       return 0;
    }
    cout << "finish" << endl;

}
