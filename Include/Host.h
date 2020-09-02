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
        Host(int host_socket, string ping, string portNumber);
        int getHostSocket();
        void bindHost();
        int acceptClient();
        void sendBytes(int client_socket, string message);
        void recieveBytes(int client_socket);
        void closeSocket(int socket_id);
        void listening();

    protected:

    private:
        int host_socket;
        struct sockaddr_in host_address;
        socklen_t sock_leng;
};

#endif // HOST_H
