package com.iot.productserviceiot.data

import com.iot.productserviceiot.model.ProductType
import jakarta.persistence.*

@Entity
@Table(name = "sales_strategy")
open class SaleStrategyEntity (
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id", nullable = false)
    open var id: Int? = null,

    @Column
    open var productType: ProductType,

    @Column
    @ElementCollection
    @CollectionTable(name = "border_list", joinColumns = [JoinColumn(name = "id")])
    open var borderList: List<Int>,

    @Column
    @ElementCollection
    @CollectionTable(name = "sales_list", joinColumns = [JoinColumn(name = "id")])
    open var salesList: List<Int>
) {}