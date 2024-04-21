package com.iot.productserviceiot.controller

import com.iot.productserviceiot.data.ProductEntity
import com.iot.productserviceiot.data.ProductRepository
import com.iot.productserviceiot.data.ProductSampleRepository
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.web.bind.annotation.PostMapping
import org.springframework.web.bind.annotation.RequestParam
import org.springframework.web.bind.annotation.RestController


@RestController
class ProductController(
    @Autowired private val productRepository: ProductRepository,
    @Autowired private val productSampleRepository: ProductSampleRepository
) {
    @PostMapping("/product/from-sample")
    fun createFromSample(@RequestParam title: String) {
        val sample = productSampleRepository.findAllByTitle(title).first()
        productRepository.save(
            ProductEntity(
                null,
                sample.initialPrice,
                sample.title, 100,
                sample.expirationPointsDecreaseSpeed, sample.productType
            )
        )
    }
}