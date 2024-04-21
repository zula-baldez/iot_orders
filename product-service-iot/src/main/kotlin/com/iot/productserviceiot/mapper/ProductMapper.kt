package com.iot.productserviceiot.mapper

import com.iot.productserviceiot.data.ProductEntity
import com.iot.productserviceiot.data.ProductSampleEntity
import com.iot.productserviceiot.data.SaleStrategyEntity
import com.iot.productserviceiot.model.Product
import com.iot.productserviceiot.model.ProductSample
import com.iot.productserviceiot.service.SalesStrategy
import org.mapstruct.Mapper
import org.mapstruct.factory.Mappers
import java.util.*

@Mapper
interface ProductMapper {
    companion object {
        val MAPPER: ProductMapper by lazy {
            Mappers.getMapper(ProductMapper::class.java)
        }
    }

    fun map(productEntity: ProductEntity): Product

    fun map(productSampleEntity: ProductSampleEntity): ProductSample

}
