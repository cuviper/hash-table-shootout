#include <inttypes.h>
#include <google/dense_hash_map>
typedef google::dense_hash_map<int64_t, int64_t> hash_t;
typedef google::dense_hash_map<std::string, int64_t> str_hash_t;
#define SETUP hash_t hash; hash.set_empty_key(-1); hash.set_deleted_key(-2); \
              str_hash_t str_hash; str_hash.set_empty_key(""); str_hash.set_deleted_key("d");
#define INSERT_INT_INTO_HASH(key, value) hash.insert(hash_t::value_type(key, value))
#define DELETE_INT_FROM_HASH(key) hash.erase(key)
#define INSERT_STR_INTO_HASH(key, value) str_hash.insert(str_hash_t::value_type(key, value))
#define DELETE_STR_FROM_HASH(key) str_hash.erase(key)
#define LOOKUP_INT(key) do { \
    google::dense_hash_map<int64_t, int64_t>::const_iterator iter = hash.find (key); \
    if (iter != hash.end()) \
      volatile int64_t v = iter->second; } while (0);

#include "template.c"
