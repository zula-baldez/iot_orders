#pragma once

#include <drogon/HttpController.h>
#include <dto/FindSaleRequest.h>
#include "dto/FindSaleResponse.h"
#include "ProductClient.h"
#include <dto/mapper.h>
#include <models/OrderList.h>
#include <models/OrderItem.h>

#include <jwt/jwt_JwtService.h>

using namespace drogon;


namespace order {
    class Order : public drogon::HttpController<Order> {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Order::addItemRequest, "/add-item-request", Post, "JwtFilter");
            METHOD_ADD(Order::findSaleRequest, "/find-sale-request", Get, "JwtFilter");
            METHOD_ADD(Order::getProductsByType, "/get-products-by-type", Get, "JwtFilter");
            METHOD_ADD(Order::getProducts, "/get-products", Get, "JwtFilter");
            METHOD_ADD(Order::getProductsByTitle, "/get-products-by-title", Get, "JwtFilter");
            METHOD_ADD(Order::buyRequest, "/submit-order", Get, "JwtFilter");
        METHOD_LIST_END

        auto findSaleRequest(const HttpRequestPtr &req,
                             std::function<void(const HttpResponsePtr &)> &&callback,
                             struct FindSaleRequest &&) -> void;

        auto addItemRequest(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback,
                            struct AddItemRequest &&) -> void;

        auto buyRequest(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback) -> void;

        auto getProductsByTitle(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback,
                            struct GetProductsByTitleRequest &&) -> void;

        auto getProductsByType(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback,
                            enum ProductType &&) -> void;

        auto getProducts(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback) -> void;



    private:
        drogon::orm::Mapper<drogon_model::test::OrderList> orderListMapper = drogon::orm::Mapper<drogon_model::test::OrderList>(
                app().getDbClient()
        );
        drogon::orm::Mapper<drogon_model::test::OrderItem> orderItemMapper = drogon::orm::Mapper<drogon_model::test::OrderItem>(
                app().getDbClient()
        );
        std::vector<Product> filter(const std::vector<Product>& products);
    };
};

