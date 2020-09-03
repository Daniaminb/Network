#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Client.h"
#include "Exception.h"

using namespace std;
int main(int argc, char* argv[])
{
    if (argc < 4){
        cout << "not enough argument" << endl;
        return 0;
    }
    else if (argc < 6)
    {
        Client* client_host = new Client(argv[1], argv[2], 1);
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(atoi(argv[4]));
        inet_pton(AF_INET, argv[3], &server_address.sin_addr.s_addr);
        string message;
        cout << "Please enter message " << endl;
        getline(cin, message);
        while(!message.empty())
        {
            message.append("\n");
            client_host->udp_sendBytes(message, server_address);
            client_host->udp_recieveBytes();
            cout << "Please enter message " << endl;
            getline(cin, message);
            
        }
         client_host->udp_sendBytes("", server_address);
    }
    else
    {
        cout << "To many argument" << endl;
        return 0;
    }
    cout << "finish" << endl;

}