package com.iot.productserviceiot.data

import com.iot.productserviceiot.model.ProductType
import jakarta.persistence.*

@Entity
@Table(name = "product")
open class ProductEntity(
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id", nullable = false)
    open var id: Long? = null,

    @Column(name = "currentPrice", nullable = false)
    open var currentPrice: Double,

    @Column(name = "title", nullable = false)
    open var title: String,

    @Column(name = "expirationPoints", nullable = false)
    open var expirationPoints: Int,

    @Column(name = "expirationPointsDecreaseSpeed", nullable = false)
    open var expirationPointsDecreaseSpeed: Int,

    @Column(name = "productType", nullable = false)
    open var productType: ProductType
)