#include "Host.h"
#ifndef CLIENT_H
#define CLIENT_H
using namespace std;
class Client:public Host
{
    public:
        Client(string ip, string portNumber, uint8_t type);
        int requestServer(string server_ip, string serverPort);
        void tcp_recieveBytes(int client_socket) override;
        void udp_recieveBytes() override;


    protected:

    private:
        typedef Host super;

};

#endif // CLIENT_H
