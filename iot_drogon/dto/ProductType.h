//
// Created by root on 20.04.24.
//

#ifndef IOT_DROGON_PRODUCTTYPE_H
#define IOT_DROGON_PRODUCTTYPE_H

#include <unordered_map>
#include <string>
#include <stdexcept>
enum ProductType {
    DRINK, MILK_PRODUCT, COMMON
};

class ProductMapper {
public:
    static ProductType map(const std::string& type) {
        static std::unordered_map<std::string,ProductType> const table = { {"DRINK",DRINK},  {"MILK_PRODUCT",MILK_PRODUCT},  {"COMMON",COMMON}};
        auto it = table.find(type);
        if (it != table.end()) {
            return it->second;
        } else {
            throw std::invalid_argument("No such type");
        }
    }

    static std::string map(const ProductType& type) {
        static std::unordered_map<ProductType,std::string> const table = { {DRINK,"DRINK"},  {MILK_PRODUCT,"MILK_PRODUCT"},  {COMMON,"COMMON"}};
        auto it = table.find(type);
        if (it != table.end()) {
            return it->second;
        } else {
            throw std::invalid_argument("No such type");
        }
    }

};

#endif //IOT_DROGON_PRODUCTTYPE_H
