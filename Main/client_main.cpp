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
        Client* client_host = new Client(argv[1], argv[2]);
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
        cin >> message;
        message.append("\n");
        while(!message.empty())
        {
            client_host->sendBytes(session_sock, message);
            client_host->recieveBytes(session_sock);
            cout << "Please enter message " << endl;
            cin >> message;
            message.append("\n");
        }
    }
    else
    {
        cout << "To many argument" << endl;
        return 0;
    }
    cout << "finish" << endl;

}