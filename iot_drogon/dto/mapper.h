//
// Created by root on 30.03.24.
//

#ifndef IOT_DROGON_MAPPER_H
#define IOT_DROGON_MAPPER_H

#include <drogon/HttpController.h>
#include <dto/FindSaleRequest.h>
#include <drogon/drogon.h>
#include "AddItemRequest.h"
#include "ProductType.h"
#include "Product.h"
#include "GetProductsByTitleRequest.h"

namespace drogon {
    template<>
    inline FindSaleRequest fromRequest(const HttpRequest &req) {
        const auto& json = req.getJsonObject();
        auto productId = (req.getParameter("productId"));
        auto findSaleRequest = FindSaleRequest{std::stol(productId)};
        return findSaleRequest;
    }
    template<>
    inline AddItemRequest fromRequest(const HttpRequest &req) {
        const auto& json = req.getJsonObject();
        auto itemId = (*json)["itemId"].asInt();
        auto findSaleRequest = AddItemRequest{itemId};
        return findSaleRequest;
    }
    template<>
    inline ProductType fromRequest(const HttpRequest &req) {
        auto typeStr = (req.getParameter("productType"));
        auto productType = ProductMapper::map(typeStr);
        return productType;
    }
    template<>
    inline GetProductsByTitleRequest fromRequest(const HttpRequest &req) {
        auto title = req.getParameter("title");
        return GetProductsByTitleRequest{title};
    }

}
class DtoMapper {
public:
    static std::vector<Product> fromResponse(const drogon::HttpResponse & resp) {
        const auto& products = resp.getJsonObject();
        std::vector<Product> productsV;
        for(auto json: *products) {

            auto itemId = (json)["id"].asInt();
            auto expirationPoints = (json)["expirationPoints"].asInt();
            auto currentPrice = (json)["currentPrice"].asDouble();
            auto title = (json)["title"].asString();
            productsV.emplace_back(itemId, expirationPoints, currentPrice, title);
        }
        return productsV;
    }

    static Json::Value toResponse(const std::vector<Product> & resp) {
        auto json = Json::Value();
        for(const auto& product: resp) {
            auto jsonP = Json::Value();
            jsonP["id"] = product.id;
            jsonP["expirationPoints"] = product.expirationPoints;
            jsonP["currentPrice"] = product.currentPrice;
            jsonP["title"] = product.title;
            json.append(jsonP);
        }
        return json;
    }
};



#endif //IOT_DROGON_MAPPER_H
