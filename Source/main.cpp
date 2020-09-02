#include <iostream>
#include <sys/socket.h>
#include "Host.h"
#include "Exception.h"
using namespace std;
int main(int argc, char* argv[])
{
    int host_socket = socket(AF_INET, SOCK_STREAM, 0);
    Host* host = new Host(host_socket, argv[1], argv[2]);
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
        host->recieveBytes(client);
    }
    catch(RecieveException e)
    {
        cout << e.what() << endl;
    }
    cout << "finish" << endl;

}
