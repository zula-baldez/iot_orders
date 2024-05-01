#include "order_Order.h"

using namespace order;

void Order::findSaleRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                            struct FindSaleRequest &&findSaleRequest) {
    ProductClient::findSale(findSaleRequest.productId, [callback](const drogon::HttpResponsePtr &response) {
        callback(response);
    });
}

auto Order::addItemRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                           struct AddItemRequest &&addItemRequest) -> void {
    auto uid = util::JwtService::getCurrentUserIdFromRequest(req).value();
    drogon_model::test::OrderList orderList;
    try {
        orderList = orderListMapper.findOne(drogon::orm::Criteria("uid", drogon::orm::CompareOperator::EQ, uid));
    } catch (drogon::orm::UnexpectedRows &e) {
        auto json = Json::Value();
        json["uid"] = uid;
        auto orderList1 = drogon_model::test::OrderList(json);
        orderListMapper.insert(orderList1);
        orderList = orderListMapper.findOne(drogon::orm::Criteria("uid", drogon::orm::CompareOperator::EQ, uid));
    }

    auto presentOrder = orderItemMapper.findBy(
            drogon::orm::Criteria("id", drogon::orm::CompareOperator::EQ, addItemRequest.itemId));
    if (presentOrder.size() == 0) {
        auto json = Json::Value();
        auto price = ProductClient::getCurrentPrice(addItemRequest.itemId);
        json["price"] = price;
        json["is_approved"] = true;
        json["order_id"] = orderList.getId().get();
        auto orderItem = drogon_model::test::OrderItem(json);
        orderItemMapper.insert(orderItem);
        json = Json::Value();
        auto resp = HttpResponse::newHttpJsonResponse(json);
        resp->setStatusCode(HttpStatusCode::k201Created);
        callback(resp);
        return;

    } else {
        auto json = Json::Value();
        auto resp = HttpResponse::newHttpJsonResponse(json);
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("item already consumed");
        callback(resp);
    }
}


auto Order::getProductsByType(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                              ProductType &&type) -> void {
    ProductClient::getProductsByType(type, [callback](const drogon::HttpResponsePtr &response) {
        callback(response);
    });
}

auto Order::getProductsByTitle(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback,
                               struct GetProductsByTitleRequest &&request) -> void {
    ProductClient::getProductsByTitle(request.title, [callback](const drogon::HttpResponsePtr &response) {
        callback(response);
    });
}


auto Order::buyRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) -> void {
//    auto uid = util::JwtService::getCurrentUserIdFromRequest(req).value();
//    auto orderListId = orderListMapper.findOne(drogon::orm::Criteria("uid", drogon::orm::CompareOperator::EQ, uid)).getId().get();
//    auto orderItemIds
}

auto Order::getProducts(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) -> void {
    ProductClient::getProducts([callback](const drogon::HttpResponsePtr &response) {
        callback(response);
    });
}

