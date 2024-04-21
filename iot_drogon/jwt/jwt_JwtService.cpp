#include "jwt_JwtService.h"

const std::string util::JwtService::_secret = drogon::app().getCustomConfig()["jwt-secret"].asString();
const jwt::verifier<jwt::default_clock, jwt::traits::kazuho_picojson> util::JwtService::_verifier = jwt::verify()
        .allow_algorithm(jwt::algorithm::hs256{util::JwtService::_secret});

auto util::JwtService::getUserIdFromJwt(const std::string &token) -> std::optional<long> {
    auto decoded = jwt::decode(token);
    try {
        //_verifier.verify(decoded);
    } catch (const std::runtime_error &e) {
        LOG_ERROR << e.what();
        return std::nullopt;
    }
    return std::stol(decoded.get_payload_claim("uid").as_string());
}

auto util::JwtService::getCurrentUserIdFromRequest(const drogon::HttpRequestPtr &req) -> std::optional<long> {
    if(req->getHeader("Authorization").size() >= 6) {
        auto token = req->getHeader("Authorization").substr(6);
        return getUserIdFromJwt(token);
    } else {
        return std::nullopt;
    }
}
