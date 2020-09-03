#include "Host.h"
#ifndef CLIENT_H
#define CLIENT_H
using namespace std;
class Client:public Host
{
    public:
        Client(string ip, string portNumber);
        int requestServer(string server_ip, string serverPort);
        void recieveBytes(int client_socket);


    protected:

    private:
        typedef Host super;

};

#endif // CLIENT_H
