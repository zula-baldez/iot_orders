package com.iot.productserviceiot.dto

import com.iot.productserviceiot.model.ProductType

data class SalesStrategyDto (
    val productType: ProductType,
    val sales: Map<Int, Int>
)