package com.iot.productserviceiot.schedule

import com.iot.productserviceiot.data.ProductRepository
import com.iot.productserviceiot.data.ProductSampleRepository
import com.iot.productserviceiot.data.SelectRequest
import com.iot.productserviceiot.service.SalesService
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.data.domain.Sort
import org.springframework.scheduling.annotation.Scheduled
import org.springframework.stereotype.Component

@Component
class ExpirationPointsTask(
    @Autowired private val productRepository: ProductRepository,
    @Autowired private val sampleRepository: ProductSampleRepository,
    @Autowired private val salesService: SalesService
) {
    @Scheduled(fixedRate = 1000*60*60)
    fun renewProductExpirationPoints() {
        var offset = 0L
        val limit = 10
        val sort = Sort.unsorted()
        var selected = productRepository.findAll(SelectRequest(offset, limit, sort)).content
        while (selected.isNotEmpty()) {
            selected.forEach { println(it.productType) }
            selected.forEach { println(it.title) }

            selected.forEach { it.expirationPoints -= it.expirationPointsDecreaseSpeed; }
            selected.forEach {
                val sample = sampleRepository.findAllByTitle(it.title).first()
                val initialPrice = sample.initialPrice
                val sale = salesService.getSale(it.id!!)
                println(sale)
                it.currentPrice  =  initialPrice - (sale * 1.0) / 100 * initialPrice
            }
            productRepository.saveAllAndFlush(
                selected
            )
            selected = productRepository.findAll(SelectRequest(offset, limit, sort)).content
            offset += limit
        }
    }
}
