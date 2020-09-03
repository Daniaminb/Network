#include <iostream>
#include "Host.h"
#include "Exception.h"
using namespace std;
int main(int argc, char* argv[])
{
    if (argc < 2){
        cout << "not enough argument" << endl;
        return 0;
    }
    else if (argc < 4){
        Host* host = new Host(argv[1], argv[2], 0);
        try
        {
            host->bindHost();
        }
        catch(BindException e)
        {
            cout << e.what() << endl;
        }
        try
        {
            host->listening();
        }
        catch(ListenException e)
        {
            cout << e.what() << endl;
        }
        int client = host->acceptClient();
        try
        {
            host->tcp_recieveBytes(client);
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
