package com.iot.productserviceiot.data

import com.iot.productserviceiot.model.ProductType
import jakarta.persistence.*

@Entity
@Table(name = "product-sample")
open class ProductSampleEntity(
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id", nullable = false)
    open var id: Long? = null,

    @Column(name = "currentPrice", nullable = false)
    open var initialPrice: Double,

    @Column(name = "title", nullable = false)
    open var title: String,

    @Column(name = "expirationPointsDecreaseSpeed", nullable = false)
    open var expirationPointsDecreaseSpeed: Int,

    @Column(name = "productType", nullable = false)
    open var productType: ProductType
)