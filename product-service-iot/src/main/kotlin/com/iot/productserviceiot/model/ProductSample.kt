package com.iot.productserviceiot.model

class ProductSample(
    var id: Long,
    var initialPrice: Double,
    var title: String,
    var productType: ProductType,
    var expirationPointsDecreaseSpeed: Int
)