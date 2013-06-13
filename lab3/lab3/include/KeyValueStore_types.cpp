/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "KeyValueStore_types.h"

#include <algorithm>

namespace KeyValueStore {

int _kKVStoreStatusValues[] = {
  KVStoreStatus::OK,
  KVStoreStatus::EKEYNOTFOUND,
  KVStoreStatus::EITEMNOTFOUND,
  KVStoreStatus::EPUTFAILED,
  KVStoreStatus::EITEMEXISTS,
  KVStoreStatus::INTERNAL_FAILURE,
  KVStoreStatus::NOT_IMPLEMENTED
};
const char* _kKVStoreStatusNames[] = {
  "OK",
  "EKEYNOTFOUND",
  "EITEMNOTFOUND",
  "EPUTFAILED",
  "EITEMEXISTS",
  "INTERNAL_FAILURE",
  "NOT_IMPLEMENTED"
};
const std::map<int, const char*> _KVStoreStatus_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kKVStoreStatusValues, _kKVStoreStatusNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

const char* GetResponse::ascii_fingerprint = "19B5240589E680301A7E32DF3971EFBE";
const uint8_t GetResponse::binary_fingerprint[16] = {0x19,0xB5,0x24,0x05,0x89,0xE6,0x80,0x30,0x1A,0x7E,0x32,0xDF,0x39,0x71,0xEF,0xBE};

uint32_t GetResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->status = (KVStoreStatus::type)ecast0;
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t GetResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("GetResponse");

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(GetResponse &a, GetResponse &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

const char* GetListResponse::ascii_fingerprint = "A22BE3E84688C9DA4E00CC902B4EE818";
const uint8_t GetListResponse::binary_fingerprint[16] = {0xA2,0x2B,0xE3,0xE8,0x46,0x88,0xC9,0xDA,0x4E,0x00,0xCC,0x90,0x2B,0x4E,0xE8,0x18};

uint32_t GetListResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast1;
          xfer += iprot->readI32(ecast1);
          this->status = (KVStoreStatus::type)ecast1;
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->values.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readListBegin(_etype5, _size2);
            this->values.resize(_size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              xfer += iprot->readString(this->values[_i6]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.values = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t GetListResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("GetListResponse");

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("values", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->values.size()));
    std::vector<std::string> ::const_iterator _iter7;
    for (_iter7 = this->values.begin(); _iter7 != this->values.end(); ++_iter7)
    {
      xfer += oprot->writeString((*_iter7));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(GetListResponse &a, GetListResponse &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.values, b.values);
  swap(a.__isset, b.__isset);
}

const char* SyncResponse::ascii_fingerprint = "B089C846F881A6F18D64AA924E6643EF";
const uint8_t SyncResponse::binary_fingerprint[16] = {0xB0,0x89,0xC8,0x46,0xF8,0x81,0xA6,0xF1,0x8D,0x64,0xAA,0x92,0x4E,0x66,0x43,0xEF};

uint32_t SyncResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast8;
          xfer += iprot->readI32(ecast8);
          this->status = (KVStoreStatus::type)ecast8;
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->kvs.clear();
            uint32_t _size9;
            ::apache::thrift::protocol::TType _ktype10;
            ::apache::thrift::protocol::TType _vtype11;
            xfer += iprot->readMapBegin(_ktype10, _vtype11, _size9);
            uint32_t _i13;
            for (_i13 = 0; _i13 < _size9; ++_i13)
            {
              std::string _key14;
              xfer += iprot->readString(_key14);
              std::string& _val15 = this->kvs[_key14];
              xfer += iprot->readString(_val15);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.kvs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SyncResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SyncResponse");

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("kvs", ::apache::thrift::protocol::T_MAP, 2);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->kvs.size()));
    std::map<std::string, std::string> ::const_iterator _iter16;
    for (_iter16 = this->kvs.begin(); _iter16 != this->kvs.end(); ++_iter16)
    {
      xfer += oprot->writeString(_iter16->first);
      xfer += oprot->writeString(_iter16->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SyncResponse &a, SyncResponse &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.kvs, b.kvs);
  swap(a.__isset, b.__isset);
}

} // namespace