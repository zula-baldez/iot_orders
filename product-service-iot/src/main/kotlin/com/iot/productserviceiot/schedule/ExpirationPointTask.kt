package com.iot.productserviceiot.schedule

import com.iot.productserviceiot.data.ProductRepository
import com.iot.productserviceiot.data.SelectRequest
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.data.domain.Sort
import org.springframework.scheduling.annotation.Scheduled
import org.springframework.stereotype.Component

@Component
class ExpirationPointsTask(
    @Autowired private val productRepository: ProductRepository
) {
    @Scheduled(fixedRate = 1000*60*60)
    fun renewProductExpirationPoints() {
        var offset = 0L
        val limit = 10
        val sort = Sort.unsorted()
        var selected = productRepository.findAll(SelectRequest(offset, limit, sort)).content
        while (selected.isNotEmpty()) {
            selected.forEach { it.expirationPoints -= it.expirationPointsDecreaseSpeed }
            productRepository.saveAll(
                selected
            )
            selected = productRepository.findAll(SelectRequest(offset, limit, sort)).content
            offset += limit
        }
    }
}
