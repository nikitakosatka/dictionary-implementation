#ifndef DICTIONARY_IMPLEMENTATION_UNORDEREDDICTIONARY_H
#define DICTIONARY_IMPLEMENTATION_UNORDEREDDICTIONARY_H

#include <cstddef>
#include <vector>
#include <iterator>

#include "Dictionary.h"
#include "utils.h"


template<class Key, class Value>
class UnorderedDictionary : Dictionary<Key, Value> {
private:
    const size_t mod = HASH_MOD;
    std::vector<std::vector<std::pair<Key, Value>>> table;

    const size_t getHash(const Key &key) const {
        return std::hash<Key>{}(key) % mod;
    }

public:
    UnorderedDictionary() {
        table.resize(mod);
    }

    const Value &get(const Key &key) const {
        size_t hashValue = getHash(key);

        for (size_t i = 0; i < table[hashValue].size(); i++) {
            if (table[hashValue][i].first == key) {
                return table[hashValue][i].second;
            }
        }

        throw key_not_found_exception<Key>();
    }

    void set(const Key &key, const Value &value) {
        size_t hashValue = getHash(key);

        table[hashValue].push_back(std::make_pair(key, value));
    }

    void remove(const Key &key) {
        size_t hashValue = getHash(key);

        for (size_t i = 0; i < table[hashValue].size(); i++) {
            if (table[hashValue][i].first == key) {
                table[hashValue].erase(table[hashValue].begin() + i);
                return;
            }
        }

        throw key_not_found_exception<Key>();
    }

    bool is_set(const Key &key) const {
        try {
            get(key);
            return true;
        } catch (key_not_found_exception<Key>) {
            return false;
        }
    }
};


#endif
