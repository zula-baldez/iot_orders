#include "order_Order.h"

using namespace order;

void Order::findSaleRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                            struct FindSaleRequest &&findSaleRequest) {
    ProductClient::findSale(findSaleRequest.productId, [callback](const drogon::HttpResponsePtr &response)  {
        callback(response);
    });
}

auto Order::addItemRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                           struct AddItemRequest &&addItemRequest) -> void {
    auto uid = util::JwtService::getCurrentUserIdFromRequest(req).value();

    try {
        auto orderList = orderListMapper.findOne(drogon::orm::Criteria("uid", drogon::orm::CompareOperator::EQ, uid));
        orderList.getId();
        auto json = Json::Value();
        auto price = ProductClient::getCurrentPrice(addItemRequest.itemId);
        json["price"] = price;
        json["is_approved"] = true;
        json["order_id"] = orderList.getId().get();
        auto orderItem = drogon_model::test::OrderItem(json);
        orderItemMapper.insert(orderItem);
    } catch (drogon::orm::UnexpectedRows &e) {
        auto json = Json::Value();
        json["uid"] = uid;
        auto orderList = drogon_model::test::OrderList(json);
        orderListMapper.insert(orderList);

    }
    auto json = Json::Value();
    auto resp = HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(HttpStatusCode::k201Created);
    callback(resp);
}

auto Order::getProductsByType(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                              ProductType && type) -> void {

    ProductClient::getProductsByType(type, [callback](const drogon::HttpResponsePtr &response)  {
        callback(response);
    });
}

auto Order::getProductsByTitle(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback,
                    struct GetProductsByTitleRequest && request) -> void {
    ProductClient::getProductsByTitle(request.title, [callback](const drogon::HttpResponsePtr &response)  {
        callback(response);
    });
}


auto Order::buyRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                       AddItemRequest &&) -> void {

}

auto Order::getProducts(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) -> void {
    ProductClient::getProducts([callback](const drogon::HttpResponsePtr &response)  {
        callback(response);
    });
}
