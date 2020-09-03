#include <Host.h>
#ifndef SERVER_H
#define SERVER_H

class Server:public Host
{
    public:
        Server(string ip, string portNumber, uint8_t type);
    private:
        typedef Host super;
};


#endif // SERVER_H