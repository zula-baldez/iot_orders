package com.iot.productserviceiot.model

class Product (
    var id: Long,
    val expirationPoints: Int,
    val expirationPointsDecreaseSpeed: Int,
    var currentPrice: Double,
    var title: String,
    var productType: ProductType
)