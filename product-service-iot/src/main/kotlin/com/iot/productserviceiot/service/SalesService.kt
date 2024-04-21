package com.iot.productserviceiot.service

import com.iot.productserviceiot.data.ProductRepository
import com.iot.productserviceiot.data.SalesStrategyRepository
import com.iot.productserviceiot.mapper.ProductMapper
import com.iot.productserviceiot.mapper.StMapper
import com.iot.productserviceiot.model.Product
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.stereotype.Service

@Service
class SalesService(
    @Autowired private val salesStrategyRepository: SalesStrategyRepository,
    @Autowired private val productRepository: ProductRepository
) {
    fun getSale(productId: Long): Int {
        val product = productRepository.findById(productId).orElse(null) ?: throw IllegalArgumentException("Not found")
        val strategy = salesStrategyRepository.findSaleStrategyEntitiesByProductType(product.productType)?.let {
            StMapper.map(it)
        }
        return strategy?.getSale(product.expirationPoints) ?: 0
    }
}