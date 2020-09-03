#include "Client.h"
#include "Exception.h"
#include <arpa/inet.h>
#include <iostream>

Client::Client(string ip, string portNumber, uint8_t type): super(ip, portNumber, type){
}

int Client::requestServer(string server_ip, string serverPort)
{
    using namespace std;
    int session_sock = socket(AF_INET, SOCK_STREAM, 0);
    int port = atoi(serverPort.c_str());
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr.s_addr);
    socklen_t server_len = sizeof(server_address);
    int status = connect(session_sock,(struct sockaddr*) &server_address, server_len);
    if (status < 0){
        throw(RequestServerException());
    }
    else
    {
        cout << "Request sent" << endl;
    }
    return session_sock;
}

void Client::tcp_recieveBytes(int client_socket) 
{
    using namespace std;
    char buffer[256];
    memset(buffer, 0, 256);
    ssize_t byte_recieve = recv(client_socket, buffer, 256, 0);
    if (byte_recieve <= 0) throw(RecieveException());
    else
    {
        cout << "Client recived message =  " << string(buffer, 0, byte_recieve);
    }
}

void Client::udp_recieveBytes()
{
    char buffer[256];
    memset(buffer, 0, 256);
    struct sockaddr_in src_address;
    socklen_t src_address_len = sizeof(src_address);
    ssize_t byte_recieve;
    byte_recieve = recvfrom(getHostSocket(), buffer, 256, 0, (struct sockaddr *)&src_address, &src_address_len);
    if (byte_recieve <= 0)
    {
        throw(RecieveException());
    }
    else
    {
         cout << "Client recived message  =  " << string(buffer, 0, byte_recieve);
    }

}