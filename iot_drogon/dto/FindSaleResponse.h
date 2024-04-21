//
// Created by root on 30.03.24.
//

#ifndef IOT_DROGON_FINDSALERESPONSE_H
#define IOT_DROGON_FINDSALERESPONSE_H

#include <optional>
#include <string>

struct FindSaleResponse {
    std::optional<double> salePrice;
    std::optional<std::string> saleReasonMessage;
};

#endif //IOT_DROGON_FINDSALERESPONSE_H
