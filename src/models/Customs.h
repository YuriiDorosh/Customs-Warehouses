#ifndef CUSTOMS_H
#define CUSTOMS_H

#include <string>

class Customs {
private:
    std::string countryCode;

public:
    Customs(std::string countryCode);

    std::string getCountryCode() const;
};

#endif
