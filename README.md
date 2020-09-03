# Echo client/server
Simple echo clinet/server with C++

## Use with telent
Use below command lines:

    `g++ -o telnet -I ./Include/ ./Source/Host.cpp ./Source/Exception.cpp ./Main/telnet_main.cpp`
    `./main arg1 arg2`

* arg 1 is ip of machine (for example localhost - "127.0.0.1")
* arg 2 is port of machine (for example 4500)

After that, use telnet to connect to server

## Use client/server

    `g++  -o client -I ./Include/ ./Source/Host.cpp ./Source/Exception.cpp ./Source/Client.cpp  ./Source/client_main.cpp`
    'g++ -o server -I ./Include/ ./Source/Host.cpp  ./Source/Exception.cpp ./Source/Server.cpp ./Source/server_main.cpp'
    './server arg1 arg2'
    './client arg3 arg4 arg5 arg6'
* arg1 is ip of server (for example localhost - "127.0.0.1")
* arg2 is port of server (for example 4500)
* arg3 is ip of client (for further implementation)
* arg4 is port of client (for further implementation)
* arg5 is server's ip
* arg6 is server's port
