#ifndef DICTIONARY_IMPLEMENTATION_DICTIONARY_H
#define DICTIONARY_IMPLEMENTATION_DICTIONARY_H

template<class Key, class Value>
class Dictionary {
public:
    virtual ~Dictionary() = default;

    virtual const Value &get(const Key &key) const = 0;

    virtual void set(const Key &key, const Value &value) = 0;

    virtual bool is_set(const Key &key) const = 0;
};

#endif
