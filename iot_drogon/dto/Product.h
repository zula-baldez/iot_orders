//
// Created by root on 20.04.24.
//

#ifndef IOT_DROGON_PRODUCT_H
#define IOT_DROGON_PRODUCT_H

#include <string>
#include <utility>

class Product {
public:
    Product(long id, int expirationPoints, double currentPrice, std::string title): id(id), expirationPoints(expirationPoints), currentPrice(currentPrice), title(std::move(title)) {};
    long id;
    int expirationPoints;
    double currentPrice;
    std::string title;
};

#endif //IOT_DROGON_PRODUCT_H
