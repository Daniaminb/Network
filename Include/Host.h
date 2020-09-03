#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <string.h>
#include <netinet/in.h>
#ifndef HOST_H
#define HOST_H
using namespace std;
class Host
{
    public:
        Host(string ip, string portNumber, uint8_t type);
        int getHostSocket();
        void bindHost();
        int acceptClient();
        void tcp_sendBytes(int client_socket, string message);
        virtual void tcp_recieveBytes(int client_socket);
        void udp_sendBytes(string message, sockaddr_in des_address);
        virtual void udp_recieveBytes();
        void closeSocket(int socket_id);
        void listening();
        

    protected:

    private:
        int host_socket;
        struct sockaddr_in host_address;
        socklen_t sock_leng;
};

#endif // HOST_H
