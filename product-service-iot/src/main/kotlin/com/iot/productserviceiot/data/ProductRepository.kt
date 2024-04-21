package com.iot.productserviceiot.data

import com.iot.productserviceiot.model.ProductType
import org.springframework.data.domain.Page
import org.springframework.data.domain.Pageable
import org.springframework.data.jpa.repository.JpaRepository
import org.springframework.stereotype.Repository

@Repository
interface ProductRepository : JpaRepository<ProductEntity, Long> {
    fun findAllByProductType(productType: ProductType): List<ProductEntity>

    fun findAllByTitle(title: String): List<ProductEntity>

    override fun findAll(pageable: Pageable): Page<ProductEntity>

}