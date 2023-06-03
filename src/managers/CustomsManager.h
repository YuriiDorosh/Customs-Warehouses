#ifndef CUSTOMSMANAGER_H
#define CUSTOMSMANAGER_H

#include <vector>
#include "Customs.h"

class CustomsManager {
private:
    std::vector<Customs> customsList;

public:
    void addCustoms(const Customs& customs);
    void removeCustoms(const std::string& countryCode);
    Customs* findCustoms(const std::string& countryCode);
    std::vector<Customs> getAllCustoms() const;
};

#endif
