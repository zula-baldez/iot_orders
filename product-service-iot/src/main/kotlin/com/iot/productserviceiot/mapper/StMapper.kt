package com.iot.productserviceiot.mapper

import com.iot.productserviceiot.data.SaleStrategyEntity
import com.iot.productserviceiot.service.SalesStrategy
import java.util.*

class StMapper {
    companion object {
        fun map(saleStrategyEntity: SaleStrategyEntity): SalesStrategy {
            require(saleStrategyEntity.borderList.size == saleStrategyEntity.salesList.size) {
                "Border list and sales list must have the same size."
            }
            println(saleStrategyEntity.borderList)
            println(saleStrategyEntity.salesList)

            val borderSalesMap = TreeMap<Int, Int>().apply {
                saleStrategyEntity.borderList.zip(saleStrategyEntity.salesList).forEach { (border, sales) ->
                    put(border, sales)
                }
            }
            println(borderSalesMap)
            return SalesStrategy(saleStrategyEntity.productType, borderSalesMap)
        }
    }
}