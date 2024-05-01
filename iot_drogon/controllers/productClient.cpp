//
// Created by root on 20.04.24.
//

#include "ProductClient.h"
#include "../dto/mapper.h"

void ProductClient::getProductsByType(ProductType type, std::function<void(const drogon::HttpResponsePtr &)> callback) {
    drogon::HttpClientPtr client = drogon::HttpClient::newHttpClient("http://127.0.0.1:8081/");

    auto req = drogon::HttpRequest::newHttpRequest();
    req->setParameter("productType", ProductMapper::map(type));
    req->setPath("/product/type");
    req->setMethod(drogon::Get);
    client->sendRequest(req, [callback](drogon::ReqResult result, const drogon::HttpResponsePtr &response) {
        response->removeHeader("Content-Length");
        callback(response);
    });
}

void ProductClient::findSale(int productId, std::function<void(const drogon::HttpResponsePtr &)> callback) {
    drogon::HttpClientPtr client = drogon::HttpClient::newHttpClient("http://127.0.0.1:8081/");
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setParameter("productId", std::to_string(productId));
    req->setPath("/product/sale");
    req->setMethod(drogon::Get);
    client->sendRequest(req, [callback](drogon::ReqResult result, const drogon::HttpResponsePtr &response) {
        response->removeHeader("Content-Length");
        callback(response);
    });
}

void ProductClient::getProducts(std::function<void(const drogon::HttpResponsePtr &)> callback) {
    drogon::HttpClientPtr client = drogon::HttpClient::newHttpClient("http://127.0.0.1:8081/");
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setPath("/products");
    req->setMethod(drogon::Get);
    client->sendRequest(req, [callback](drogon::ReqResult result, const drogon::HttpResponsePtr &response) {
        response->removeHeader("Content-Length");
        callback(response);
    });
}

void ProductClient::getProductsByTitle(std::string title, std::function<void(const drogon::HttpResponsePtr &)> callback) {
    drogon::HttpClientPtr client = drogon::HttpClient::newHttpClient("http://127.0.0.1:8081/");
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setPath("/products/title");
    req->setParameter("title", title);
    req->setMethod(drogon::Get);
    client->sendRequest(req, [callback](drogon::ReqResult result, const drogon::HttpResponsePtr &response) {
        response->removeHeader("Content-Length");
        callback(response);
    });
}

int ProductClient::getCurrentPrice(long productId) {
    drogon::HttpClientPtr client = drogon::HttpClient::newHttpClient("http://127.0.0.1:8081/");
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setPath("/products/info");
    req->setParameter("productId", std::to_string(productId));
    req->setMethod(drogon::Get);
    std::promise<int> valid;
    client->sendRequest(req, [&](drogon::ReqResult result, const drogon::HttpResponsePtr &response) {
        const auto &json = (*response).getJsonObject();
        auto price = (*json)["currentPrice"].asDouble();
        valid.set_value((int)price);

    });
    return valid.get_future().get();
}

void ProductClient::deleteProducts(const std::vector<long>& productIds) {
    drogon::HttpClientPtr client = drogon::HttpClient::newHttpClient("http://127.0.0.1:8081/");
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setPath("/product/delete");
    req->setContentTypeCode(drogon::ContentType::CT_APPLICATION_JSON);
    req->setMethod(drogon::Delete);
    auto jsonP = Json::Value();
    for(auto id : productIds) {
        jsonP.append(id);
    }
    auto json = Json::Value();
    json["productIds"] = jsonP;
    req->setBody(json.toStyledString());
    auto test = json.toStyledString();
    client->sendRequest(req, [&](drogon::ReqResult result, const drogon::HttpResponsePtr &response) {});
}
