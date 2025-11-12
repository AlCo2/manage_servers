#include "valid.h"

Valid::Valid() {}

bool Valid::isValidIp(const std::string &ipAddressp) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddressp.c_str(), &(sa.sin_addr));
    return result != 0;
}
