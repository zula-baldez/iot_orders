package com.iot.productserviceiot.controller

import com.iot.productserviceiot.data.ProductSampleEntity
import com.iot.productserviceiot.data.ProductSampleRepository
import com.iot.productserviceiot.dto.ProductSampleDto
import org.springframework.web.bind.annotation.PostMapping
import org.springframework.web.bind.annotation.RequestBody
import org.springframework.web.bind.annotation.RestController

@RestController
class SampleController(
    private val sampleRepository: ProductSampleRepository
) {
    @PostMapping("/sample/create")
    fun createSample(@RequestBody sampleDto: ProductSampleDto) {
        sampleRepository.save(
            ProductSampleEntity(
                null,
                sampleDto.initialPrice,
                sampleDto.title,
                sampleDto.expirationPointsDecreaseSpeed,
                sampleDto.productType,
            )
        )
    }
}