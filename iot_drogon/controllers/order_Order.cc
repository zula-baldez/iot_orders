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
    if (presentOrder.empty()) {
        auto json = Json::Value();
        auto price = ProductClient::getCurrentPrice(addItemRequest.itemId);
        json["price"] = price;
        json["is_approved"] = true;
        json["order_id"] = *orderList.getId();
        json["id"] = addItemRequest.itemId;
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
    ProductClient::getProductsByType(type, [callback, this](const drogon::HttpResponsePtr &response) {
        auto products = DtoMapper::fromResponse(*response);
        products = filter(products);
        this->filter(products);
        auto json = DtoMapper::toResponse(products);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        resp->setStatusCode(HttpStatusCode::k200OK);
        callback(resp);
    });
}

auto Order::getProductsByTitle(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback,
                               struct GetProductsByTitleRequest &&request) -> void {
    ProductClient::getProductsByTitle(request.title, [callback, this](const drogon::HttpResponsePtr &response) {
        auto products = DtoMapper::fromResponse(*response);
        products = filter(products);
        this->filter(products);
        auto json = DtoMapper::toResponse(products);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        resp->setStatusCode(HttpStatusCode::k200OK);
        callback(resp);
    });
}


auto Order::buyRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) -> void {
    auto uid = util::JwtService::getCurrentUserIdFromRequest(req).value();
    drogon_model::test::OrderList orderList;
    try {
        orderList = orderListMapper.findOne(drogon::orm::Criteria("uid", drogon::orm::CompareOperator::EQ, uid));
    } catch (drogon::orm::UnexpectedRows &e) {
        auto json = Json::Value();
        auto resp = HttpResponse::newHttpJsonResponse(json);
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
        resp->setBody("order not found");
        callback(resp);
    }

    auto orders = orderItemMapper.findBy(
            drogon::orm::Criteria("order_id", drogon::orm::CompareOperator::EQ, *orderList.getId()));
    std::vector<long> ids;
    for (const auto &order: orders) {
        ids.push_back(*order.getId());
    }
    ProductClient::deleteProducts(ids);
    orderItemMapper.deleteBy(
            drogon::orm::Criteria("order_id", drogon::orm::CompareOperator::EQ, *orderList.getId()));
    orderListMapper.deleteBy(drogon::orm::Criteria("uid", drogon::orm::CompareOperator::EQ, uid));
    auto json = Json::Value();
    auto resp = HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(HttpStatusCode::k200OK);
    callback(resp);
}


auto Order::getProducts(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) -> void {
    ProductClient::getProducts([callback, this](const drogon::HttpResponsePtr &response) {
        callback(response);
    });
}

std::vector<Product> Order::filter(const std::vector<Product> &products) {
    auto db = orderItemMapper.findAll();
    std::unordered_set<long> s;
    for (const auto &product: db) {
        s.insert(*product.getId());
    }
    std::vector<Product> nProducts{};
    for (const auto &product: products) {
        if (!s.contains(product.id)) {
            nProducts.push_back(product);
        }
    }
    return nProducts;
}

