#include "Exception.h"

const char* BindException::what() const throw()
{
    return "Binding Exception";
}

const char* RecieveException::what() const throw()
{
    return "Recieving Exception";
}

const char* ListenException::what() const throw()
{
    return "Listening Exception";
}

const char* RequestServerException::what() const throw()
{
    return "Request Exception";
}



