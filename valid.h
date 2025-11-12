#ifndef VALID_H
#define VALID_H

#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

class Valid
{
public:
    Valid();

    static bool isValidIp(const std::string &ipAddressp);
};

#endif // VALID_H
