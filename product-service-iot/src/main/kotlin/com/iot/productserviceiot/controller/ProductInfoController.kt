package com.iot.productserviceiot.controller

import com.iot.productserviceiot.data.ProductRepository
import com.iot.productserviceiot.data.ProductSampleRepository
import com.iot.productserviceiot.dto.DeleteProductDto
import com.iot.productserviceiot.mapper.ProductMapper
import com.iot.productserviceiot.model.Product
import com.iot.productserviceiot.model.ProductSample
import com.iot.productserviceiot.model.ProductType
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.async
import kotlinx.coroutines.awaitAll
import kotlinx.coroutines.coroutineScope
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.context.annotation.ComponentScan
import org.springframework.http.HttpStatus
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.DeleteMapping
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RequestBody
import org.springframework.web.bind.annotation.RequestParam
import org.springframework.web.bind.annotation.RestController

@RestController
@ComponentScan
class ProductInfoController(
    @Autowired private val productRepository: ProductRepository,
    @Autowired private val productSampleRepository: ProductSampleRepository
) {

    @GetMapping("product/info")
    fun getProduct(@RequestParam productId: Long): ResponseEntity<Product> {
        return productRepository.findById(productId)
            .map { ResponseEntity.ok(ProductMapper.MAPPER.map(it)) }
            .orElseGet { ResponseEntity.notFound().build() }
    }

    @DeleteMapping("product/delete")
    suspend fun addToOrderList(@RequestBody deleteList: DeleteProductDto): ResponseEntity<Unit> {
        val deletions = deleteList.productIds.map { id ->
            coroutineScope {
                async(Dispatchers.IO) {
                    productRepository.deleteById(id)
                }
            }
        }
        deletions.awaitAll()
        return ResponseEntity(HttpStatus.OK)
    }

    @GetMapping("product/type")
    fun getProductByType(@RequestParam productType: ProductType): ResponseEntity<List<ProductSample>> {
        val productsByType =
            productSampleRepository.findAllByProductType(productType).map { ProductMapper.MAPPER.map(it) }
                .distinctBy { it.title }
                .toList()
        return ResponseEntity.ok(productsByType)
    }

    @GetMapping("products")
    fun getDistinctProducts(): ResponseEntity<List<ProductSample>> {
        val productsByType = productSampleRepository.findAll().map { ProductMapper.MAPPER.map(it) }
            .toList()
        return ResponseEntity.ok(productsByType)
    }

    @GetMapping("product/name")
    fun getProductByType(@RequestParam productName: String): ResponseEntity<List<Product>> {
        val productsByType = productRepository.findAllByTitle(productName).map { ProductMapper.MAPPER.map(it) }
            .sortedBy { it.expirationPoints }
            .toList()
        return ResponseEntity.ok(productsByType)
    }
}