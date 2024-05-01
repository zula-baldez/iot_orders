package com.iot.productserviceiot.dto

import com.fasterxml.jackson.annotation.JsonProperty

data class DeleteProductDto(@JsonProperty("productIds") var productIds: List<Long>);