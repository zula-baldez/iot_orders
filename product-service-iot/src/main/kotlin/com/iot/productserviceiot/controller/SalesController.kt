package com.iot.productserviceiot.controller

import com.iot.productserviceiot.data.SaleStrategyEntity
import com.iot.productserviceiot.data.SalesStrategyRepository
import com.iot.productserviceiot.dto.SalesResponse
import com.iot.productserviceiot.dto.SalesStrategyDto
import com.iot.productserviceiot.service.SalesService
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.*

@RestController
class SalesController(
    @Autowired private val salesService: SalesService,
    @Autowired private val salesStrategyRepository: SalesStrategyRepository
) {
    @GetMapping("product/sale")
    fun getSale(@RequestParam productId: Long) : ResponseEntity<SalesResponse> {
        return try {
            ResponseEntity.ok(SalesResponse(salesService.getSale(productId)))
        } catch (e: IllegalArgumentException) {
            ResponseEntity.notFound().build()
        }
    }

    @PostMapping("product/sale/create")
    fun createSale(@RequestBody sale: SalesStrategyDto)  {
        salesStrategyRepository.save(
            SaleStrategyEntity(
                null,
                sale.productType,
                sale.sales.keys.toList(),
                sale.sales.values.toList()
            )
        )
    }
}