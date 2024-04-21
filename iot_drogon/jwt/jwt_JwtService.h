//
// Created by root on 30.03.24.
//

#ifndef IOT_DROGON_JWT_JWTSERVICE_H
#define IOT_DROGON_JWT_JWTSERVICE_H
#include <drogon/drogon.h>
#include <jwt-cpp/jwt.h>

namespace util {
    class JwtService {
    public:
        static auto getUserIdFromJwt(const std::string& token) -> std::optional<long>;
        static auto getCurrentUserIdFromRequest(const drogon::HttpRequestPtr &req) -> std::optional<long>;
    private:
        static const std::string _secret;
        static const jwt::verifier<jwt::default_clock, jwt::traits::kazuho_picojson> _verifier;
    };
}


#endif //IOT_DROGON_JWT_JWTSERVICE_H
