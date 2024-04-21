package com.iot.productserviceiot.dto

import com.iot.productserviceiot.model.ProductType

data class ProductSampleDto(
    var initialPrice: Double,
    var title: String,
    var productType: ProductType,
    var expirationPointsDecreaseSpeed: Int
)