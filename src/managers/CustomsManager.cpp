#include "CustomsManager.h"

void CustomsManager::addCustoms(const Customs& customs) {
    customsList.push_back(customs);
}

void CustomsManager::removeCustoms(const std::string& countryCode) {
    for (auto it = customsList.begin(); it != customsList.end(); ++it) {
        if (it->getCountryCode() == countryCode) {
            customsList.erase(it);
            break;
        }
    }
}

Customs* CustomsManager::findCustoms(const std::string& countryCode) {
    for (auto& customs : customsList) {
        if (customs.getCountryCode() == countryCode) {
            return &customs;
        }
    }
    return nullptr;
}

std::vector<Customs> CustomsManager::getAllCustoms() const {
    return customsList;
}
