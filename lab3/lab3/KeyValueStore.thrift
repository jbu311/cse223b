# RPC Interface between Tribble server and backend KV store.
# Malveeka Tewari (malveeka@cs.ucsd.edu)

namespace cpp KeyValueStore

/**
 * Enum type for returning status of a RPC request made to the
 * the storage server.
 */

enum KVStoreStatus {
    OK = 1,
    EKEYNOTFOUND = 2,
    EITEMNOTFOUND = 3, // item not found in lists
    EPUTFAILED = 4,
    EITEMEXISTS = 5, // duplicate in lists
    INTERNAL_FAILURE = 6,
    NOT_IMPLEMENTED = 7
}

/**
 * Return type for a Get(key) RPC call to the storage server.
 */

struct GetResponse {
    1: KVStoreStatus status,
    2: string value
}

/**
 * Return type for a GetList(key) RPC call to the storage server.
 */

struct GetListResponse {
    1: KVStoreStatus status,
    2: list<string> values
}

struct SyncResponse {
    1: KVStoreStatus status,
    2: map<string, string> kvs
}

/**
 * RPC services offered by the backed KeyValues store.
 */

service KeyValueStore {
    GetResponse Get(1:string key),
    KVStoreStatus Put(1:string key, 2:string value, 3:string clientid),
    KVStoreStatus PutPhase1Internal(1:string key, 2:string value, 3:string clientid, 4:list<i32> vec_timestamp),
    KVStoreStatus PutPhase2Internal(1:string key, 2:bool commit, 3:string clientid),
    SyncResponse Sync()
    bool IsAlive();
    //GetListResponse GetList(1:string key),
    //KVStoreStatus AddToList(1:string key, 2:string value, 3:string clientid),
    //KVStoreStatus RemoveFromList(1:string key, 2:string value, 3:string clientid)
}
