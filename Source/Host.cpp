#include "Host.h"
#include "Exception.h"
#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

Host::Host(int host_socket, string ping, string portNumber)
{
    this->host_socket = host_socket;
    inet_pton(AF_INET, ping.c_str(), &this->host_address.sin_addr.s_addr);
    this->host_address.sin_port = htons(atoi(portNumber.c_str()));
    this->host_address.sin_family = AF_INET;
    sock_leng = sizeof(this->host_address);
}

int Host::getHostSocket()
{
    return host_socket;
}

void Host::bindHost(){
    int stat = bind(host_socket, (struct sockaddr*) &host_address, sock_leng);
    if (stat < 0)
    {
        throw(BindException());
    }
    else
    {
        fprintf(stdout, "Host is binding\n");
    }
}

void Host::listening(){
    int stat = listen(host_socket, 5);
    if (stat < 0) throw(ListenException());
}

int Host::acceptClient()
{
    struct sockaddr_in client_address;
    socklen_t client_leng = sizeof(client_address);
    int client_socket = accept(host_socket, (struct sockaddr*) &client_address, &client_leng);
    if (client_socket < 0) cout << "error" << endl;
    cout << "find client" << endl;
    return client_socket;
}

void Host::sendBytes(int client_socket, string message)
{
    size_t message_len = strlen(message.c_str());
    send(client_socket, message.c_str(), message_len+1, 0);
}

void Host::recieveBytes(int client_socket)
{
    using namespace std;
    char buffer[256];
    while(true)
    {
        memset(buffer, 0, 256);
        ssize_t byte_recieve = recv(client_socket, buffer, 256, 0);
        if (byte_recieve <= 0) throw(RecieveException());
        else
        {
            cout << "Recived message  =  " << string(buffer, 0, byte_recieve);
            sendBytes(client_socket, string(buffer, 0, byte_recieve));
        }

    }
}
