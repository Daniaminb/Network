#include <iostream>
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
        Client* client_host = new Client(argv[1], argv[2], 0);
        int session_sock;
        try
        {
                session_sock = client_host->requestServer(argv[3], argv[4]);
        }
        catch(RequestServerException e){
            cout << e.what() << endl;
            return 0;
        }
        string message;
        cout << "Please enter message " << endl;
        getline(cin, message);
        while(!message.empty())
        {
            message.append("\n");
            client_host->tcp_sendBytes(session_sock, message);
            client_host->tcp_recieveBytes(session_sock);
            cout << "Please enter message " << endl;
            getline(cin, message);
        }
    }
    else
    {
        cout << "To many argument" << endl;
        return 0;
    }
    cout << "finish" << endl;

}