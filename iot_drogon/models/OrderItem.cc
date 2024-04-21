/**
 *
 *  OrderItem.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "OrderItem.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::test;

const std::string OrderItem::Cols::_id = "id";
const std::string OrderItem::Cols::_price = "price";
const std::string OrderItem::Cols::_order_id = "order_id";
const std::string OrderItem::Cols::_is_approved = "is_approved";
const std::string OrderItem::primaryKeyName = "id";
const bool OrderItem::hasPrimaryKey = true;
const std::string OrderItem::tableName = "order_item";

const std::vector<typename OrderItem::MetaData> OrderItem::metaData_={
{"id","int32_t","int(11)",4,1,1,1},
{"price","double","double",8,0,0,0},
{"order_id","int32_t","int(11)",4,0,0,0},
{"is_approved","int8_t","tinyint(1)",1,0,0,0}
};
const std::string &OrderItem::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
OrderItem::OrderItem(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["price"].isNull())
        {
            price_=std::make_shared<double>(r["price"].as<double>());
        }
        if(!r["order_id"].isNull())
        {
            orderId_=std::make_shared<int32_t>(r["order_id"].as<int32_t>());
        }
        if(!r["is_approved"].isNull())
        {
            isApproved_=std::make_shared<int8_t>(r["is_approved"].as<int8_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            price_=std::make_shared<double>(r[index].as<double>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            orderId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            isApproved_=std::make_shared<int8_t>(r[index].as<int8_t>());
        }
    }

}

OrderItem::OrderItem(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            price_=std::make_shared<double>(pJson[pMasqueradingVector[1]].asDouble());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            orderId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            isApproved_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

OrderItem::OrderItem(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("price"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["price"].isNull())
        {
            price_=std::make_shared<double>(pJson["price"].asDouble());
        }
    }
    if(pJson.isMember("order_id"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["order_id"].isNull())
        {
            orderId_=std::make_shared<int32_t>((int32_t)pJson["order_id"].asInt64());
        }
    }
    if(pJson.isMember("is_approved"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["is_approved"].isNull())
        {
            isApproved_=std::make_shared<int8_t>((int8_t)pJson["is_approved"].asInt64());
        }
    }
}

void OrderItem::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            price_=std::make_shared<double>(pJson[pMasqueradingVector[1]].asDouble());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            orderId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            isApproved_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

void OrderItem::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("price"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["price"].isNull())
        {
            price_=std::make_shared<double>(pJson["price"].asDouble());
        }
    }
    if(pJson.isMember("order_id"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["order_id"].isNull())
        {
            orderId_=std::make_shared<int32_t>((int32_t)pJson["order_id"].asInt64());
        }
    }
    if(pJson.isMember("is_approved"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["is_approved"].isNull())
        {
            isApproved_=std::make_shared<int8_t>((int8_t)pJson["is_approved"].asInt64());
        }
    }
}

const int32_t &OrderItem::getValueOfId() const noexcept
{
    static const int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &OrderItem::getId() const noexcept
{
    return id_;
}
void OrderItem::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}
const typename OrderItem::PrimaryKeyType & OrderItem::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const double &OrderItem::getValueOfPrice() const noexcept
{
    static const double defaultValue = double();
    if(price_)
        return *price_;
    return defaultValue;
}
const std::shared_ptr<double> &OrderItem::getPrice() const noexcept
{
    return price_;
}
void OrderItem::setPrice(const double &pPrice) noexcept
{
    price_ = std::make_shared<double>(pPrice);
    dirtyFlag_[1] = true;
}
void OrderItem::setPriceToNull() noexcept
{
    price_.reset();
    dirtyFlag_[1] = true;
}

const int32_t &OrderItem::getValueOfOrderId() const noexcept
{
    static const int32_t defaultValue = int32_t();
    if(orderId_)
        return *orderId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &OrderItem::getOrderId() const noexcept
{
    return orderId_;
}
void OrderItem::setOrderId(const int32_t &pOrderId) noexcept
{
    orderId_ = std::make_shared<int32_t>(pOrderId);
    dirtyFlag_[2] = true;
}
void OrderItem::setOrderIdToNull() noexcept
{
    orderId_.reset();
    dirtyFlag_[2] = true;
}

const int8_t &OrderItem::getValueOfIsApproved() const noexcept
{
    static const int8_t defaultValue = int8_t();
    if(isApproved_)
        return *isApproved_;
    return defaultValue;
}
const std::shared_ptr<int8_t> &OrderItem::getIsApproved() const noexcept
{
    return isApproved_;
}
void OrderItem::setIsApproved(const int8_t &pIsApproved) noexcept
{
    isApproved_ = std::make_shared<int8_t>(pIsApproved);
    dirtyFlag_[3] = true;
}
void OrderItem::setIsApprovedToNull() noexcept
{
    isApproved_.reset();
    dirtyFlag_[3] = true;
}

void OrderItem::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &OrderItem::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "price",
        "order_id",
        "is_approved"
    };
    return inCols;
}

void OrderItem::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getPrice())
        {
            binder << getValueOfPrice();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getOrderId())
        {
            binder << getValueOfOrderId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getIsApproved())
        {
            binder << getValueOfIsApproved();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> OrderItem::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    return ret;
}

void OrderItem::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getPrice())
        {
            binder << getValueOfPrice();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getOrderId())
        {
            binder << getValueOfOrderId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getIsApproved())
        {
            binder << getValueOfIsApproved();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value OrderItem::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getPrice())
    {
        ret["price"]=getValueOfPrice();
    }
    else
    {
        ret["price"]=Json::Value();
    }
    if(getOrderId())
    {
        ret["order_id"]=getValueOfOrderId();
    }
    else
    {
        ret["order_id"]=Json::Value();
    }
    if(getIsApproved())
    {
        ret["is_approved"]=getValueOfIsApproved();
    }
    else
    {
        ret["is_approved"]=Json::Value();
    }
    return ret;
}

Json::Value OrderItem::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getPrice())
            {
                ret[pMasqueradingVector[1]]=getValueOfPrice();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getOrderId())
            {
                ret[pMasqueradingVector[2]]=getValueOfOrderId();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getIsApproved())
            {
                ret[pMasqueradingVector[3]]=getValueOfIsApproved();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getPrice())
    {
        ret["price"]=getValueOfPrice();
    }
    else
    {
        ret["price"]=Json::Value();
    }
    if(getOrderId())
    {
        ret["order_id"]=getValueOfOrderId();
    }
    else
    {
        ret["order_id"]=Json::Value();
    }
    if(getIsApproved())
    {
        ret["is_approved"]=getValueOfIsApproved();
    }
    else
    {
        ret["is_approved"]=Json::Value();
    }
    return ret;
}

bool OrderItem::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("price"))
    {
        if(!validJsonOfField(1, "price", pJson["price"], err, true))
            return false;
    }
    if(pJson.isMember("order_id"))
    {
        if(!validJsonOfField(2, "order_id", pJson["order_id"], err, true))
            return false;
    }
    if(pJson.isMember("is_approved"))
    {
        if(!validJsonOfField(3, "is_approved", pJson["is_approved"], err, true))
            return false;
    }
    return true;
}
bool OrderItem::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                   const std::vector<std::string> &pMasqueradingVector,
                                                   std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool OrderItem::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("price"))
    {
        if(!validJsonOfField(1, "price", pJson["price"], err, false))
            return false;
    }
    if(pJson.isMember("order_id"))
    {
        if(!validJsonOfField(2, "order_id", pJson["order_id"], err, false))
            return false;
    }
    if(pJson.isMember("is_approved"))
    {
        if(!validJsonOfField(3, "is_approved", pJson["is_approved"], err, false))
            return false;
    }
    return true;
}
bool OrderItem::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                 const std::vector<std::string> &pMasqueradingVector,
                                                 std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool OrderItem::validJsonOfField(size_t index,
                                 const std::string &fieldName,
                                 const Json::Value &pJson,
                                 std::string &err,
                                 bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isNumeric())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
