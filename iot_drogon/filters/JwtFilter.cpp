//
// Created by root on 30.03.24.
//

#include "JwtFilter.h"
#include <jwt/jwt_JwtService.h>

void JwtFilter::doFilter(const drogon::HttpRequestPtr &req, drogon::FilterCallback &&fcb,
                         drogon::FilterChainCallback &&fccb) {
    std::optional<long> userId = util::JwtService::getCurrentUserIdFromRequest(req);
    if (userId.has_value())
    {
        fccb();
        return;
    }

    auto res = drogon::HttpResponse::newHttpResponse();
    res->setStatusCode(drogon::k401Unauthorized);
    fcb(res);
}
