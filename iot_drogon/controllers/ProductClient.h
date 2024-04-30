//
// Created by root on 20.04.24.
//

#ifndef IOT_DROGON_PRODUCTCLIENT_H
#define IOT_DROGON_PRODUCTCLIENT_H

#include <drogon/HttpClient.h>
#include <../dto/Product.h>
#include <../dto/ProductType.h>
#include <coroutine>
class ProductClient {
public:
    static void getProductsByType(ProductType type, std::function<void(const drogon::HttpResponsePtr &)> callback);

    static void findSale(int productId, std::function<void(const drogon::HttpResponsePtr &)> callback);

    static void getProductsByTitle(std::string title, std::function<void(const drogon::HttpResponsePtr &)> callback);

    static void getProducts(std::function<void(const drogon::HttpResponsePtr &)> callback);

    static int getCurrentPrice(long productId);


private:
    //const drogon::HttpClientPtr client;
};


#endif //IOT_DROGON_PRODUCTCLIENT_H
