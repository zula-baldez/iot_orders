package com.iot.productserviceiot

import org.springframework.boot.autoconfigure.SpringBootApplication
import org.springframework.boot.runApplication
import org.springframework.scheduling.annotation.EnableScheduling

@SpringBootApplication
@EnableScheduling
class ProductServiceIotApplication

fun main(args: Array<String>) {
	runApplication<ProductServiceIotApplication>(*args)
}
