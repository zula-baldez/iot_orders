package com.iot.productserviceiot.data

import com.iot.productserviceiot.model.ProductType
import org.springframework.data.repository.CrudRepository

interface SalesStrategyRepository : CrudRepository<SaleStrategyEntity, Long> {
    fun findSaleStrategyEntitiesByProductType(productType: ProductType) : SaleStrategyEntity?
}