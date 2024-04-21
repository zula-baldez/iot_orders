#ifndef IOT_DROGON_JWTFILTER_H
#define IOT_DROGON_JWTFILTER_H

#include <drogon/HttpFilter.h>

class JwtFilter : public drogon::HttpFilter<JwtFilter> {
public:
    void doFilter(const drogon::HttpRequestPtr &req,
                  drogon::FilterCallback &&fcb,
                  drogon::FilterChainCallback &&fccb) override;
};


#endif //IOT_DROGON_JWTFILTER_H
