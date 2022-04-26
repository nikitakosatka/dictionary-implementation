#ifndef DICTIONARY_IMPLEMENTATION_UTILS_H
#define DICTIONARY_IMPLEMENTATION_UTILS_H

#include <exception>
#include <functional>
#include <string>

template<class Key>
class not_found_exception : public std::exception {
public:
    virtual const Key &get_key() const noexcept = 0;
};

const size_t HASH_MOD = 2003;

template<class Key>
class key_not_found_exception : public not_found_exception<Key> {
private:
    std::string _message;
public:
    explicit key_not_found_exception(const std::string &message = "Key not found") {
        _message = message;
    }

    const Key &get_key() const noexcept {

    }

    const char *what() const noexcept {
        return _message.c_str();
    }
};

#endif
