package com.iot.productserviceiot.data

import com.iot.productserviceiot.model.ProductType
import org.springframework.data.repository.CrudRepository
import org.springframework.stereotype.Repository

@Repository
interface ProductSampleRepository : CrudRepository<ProductSampleEntity, Long> {
    fun findAllByProductType(productType: ProductType): List<ProductSampleEntity>

    fun findAllByTitle(title: String): List<ProductSampleEntity>
}