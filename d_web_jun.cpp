#include <exception>
#include <unordered_map>
#include <stdexcept>

template<class Key, class Value>
class dictionary
{
public:
    virtual ~dictionary() = default;

    virtual const Value& get(const Key& key) const = 0;
    virtual void set(const Key& key, const Value& value) = 0;
    virtual bool is_set(const Key& key) const = 0;
};

template<class Key>
class not_found_exception : public std::exception
{
public:
    virtual const Key& get_key() const noexcept = 0;
};

template<class Key>
class jun_not_found_exception : public not_found_exception<Key>
{
public:
    jun_not_found_exception(const Key& key):_key(key) {};
    const Key& get_key() const noexcept {
        return _key;
    }
private:
    const Key& _key;
};

template<class Key, class Value>
class jun_dictionary:public dictionary<Key, Value>
{
public:
    /*
    const Value& get(const Key& key) const {
        try
        {
            return _data.at(key);
        }
        catch (const std::out_of_range&)
        {
            throw jun_not_found_exception<Key>(key);
        }
    }
    */

    const Value& get(const Key& key) const {
        if (!is_set(key)) {
            throw jun_not_found_exception<Key>(key);
        }
        return _data.at(key);
    }

    void set(const Key& key, const Value& value) {
        _data[key] = value;
    }

    bool is_set(const Key& key) const {
        return _data.find(key) != _data.end();
    }
private:
    std::unordered_map<Key, Value> _data;
};
