package com.iot.productserviceiot.data

import org.springframework.data.domain.Pageable
import org.springframework.data.domain.Sort

class SelectRequest(private val offset: Long, private val limit: Int, private val sort: Sort) : Pageable {

    override fun getPageNumber(): Int {
        return (offset / limit).toInt()
    }

    override fun getPageSize(): Int {
        return limit
    }

    override fun getOffset(): Long {
        return offset
    }

    override fun getSort(): Sort {
        return sort
    }

    override fun next(): Pageable {
        return SelectRequest(offset + limit, limit, sort)
    }

    override fun previousOrFirst(): Pageable {
        val newOffset = if (offset - limit < 0) 0 else offset - limit
        return SelectRequest(newOffset, limit, sort)
    }

    override fun first(): Pageable {
        return SelectRequest(0, limit, sort)
    }

    override fun withPage(pageNumber: Int): Pageable {
        return SelectRequest((pageNumber * limit).toLong(), limit, sort)
    }

    override fun hasPrevious(): Boolean {
        return offset > 0
    }
}