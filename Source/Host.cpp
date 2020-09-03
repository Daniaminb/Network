#include "Host.h"
#include "Exception.h"
#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

Host::Host(string ip, string portNumber, uint8_t type)
{
    // 0 as tcp socket
    if (type == 0)
    {   
        this->host_socket = socket(AF_INET, SOCK_STREAM, 0);
    }
    // 1 as udp socket
    else if (type == 1)
    {
        this -> host_socket = socket(AF_INET, SOCK_DGRAM, 0);
    }
    inet_pton(AF_INET, ip.c_str(), &this->host_address.sin_addr.s_addr);
    this->host_address.sin_port = htons(atoi(portNumber.c_str()));
    this->host_address.sin_family = AF_INET;
    this -> sock_leng = sizeof(this->host_address);
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

void Host::tcp_sendBytes(int client_socket, string message)
{
    size_t message_len = strlen(message.c_str());
    send(client_socket, message.c_str(), message_len+1, 0);
}

void Host::tcp_recieveBytes(int client_socket)
{
    using namespace std;
    char buffer[256];
    while(true)
    {
        cout << "Server is wating for recieving message" << endl;
        memset(buffer, 0, 256);
        ssize_t byte_recieve = recv(client_socket, buffer, 256, 0);
        if (byte_recieve <= 1) throw(RecieveException());
        else
        {
            cout << "Server recived message  =  " << string(buffer, 0, byte_recieve);
            tcp_sendBytes(client_socket, string(buffer, 0, byte_recieve));
        }

    }
}

void Host::udp_sendBytes(string message, sockaddr_in des_address)
{
    size_t message_len = strlen(message.c_str());
    socklen_t des_address_len = sizeof(des_address);
    sendto(host_socket, message.c_str(), message_len+1, 0, (const struct sockaddr *)&des_address, des_address_len);
}

void Host::udp_recieveBytes()
{
    char buffer[256];
    memset(buffer, 0, 256);
    struct sockaddr_in src_address;
    socklen_t src_address_len = sizeof(src_address);
    ssize_t byte_recieve;
    while(true)
    {
        byte_recieve = recvfrom(host_socket, buffer, 256, 0, (struct sockaddr *)&src_address, &src_address_len);
        cout << "byte recieve is = " << byte_recieve << endl;
        if (byte_recieve <= 1)
        {
            throw(RecieveException());
        }
        else
        {
            cout << "Server recived message  =  " << string(buffer, 0, byte_recieve);
            udp_sendBytes(string(buffer, 0, byte_recieve), src_address);
        }
        

    }

}