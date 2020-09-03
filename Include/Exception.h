#include <exception>
using namespace std;
#ifndef Exception_H
#define Exception_H
class BindException:public exception
{
    public:
        const char* what() const throw();
};

class RecieveException:public exception
{
    public:
        const char* what() const throw();
};

class ListenException:public exception
{
    public:
        const char* what() const throw();
};

class RequestServerException:public exception
{
    public:
        const char* what() const throw();
};


#endif // Exception_H
