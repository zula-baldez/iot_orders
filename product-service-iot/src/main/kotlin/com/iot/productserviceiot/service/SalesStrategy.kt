package com.iot.productserviceiot.service

import com.iot.productserviceiot.model.ProductType
import java.util.TreeMap

class SalesStrategy(
    private val productType: ProductType,
    private val highestBorderToSaleSize: TreeMap<Int, Int>
) {
    fun getSale(expirationPoints: Int): Int {
        return highestBorderToSaleSize.ceilingEntry(expirationPoints).value
    }
}