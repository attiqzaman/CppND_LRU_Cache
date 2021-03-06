#include <iostream>
#include <map>
#include "DLinkedList.h"

template <class T>
class LRU_Cache
{
private:
    DLinkedList<T> *_items;
    std::map<int, BaseNode<T>*> _items_dict;
    int _total_capacity, _current_size;

public:    
    LRU_Cache(int capacity);
    ~LRU_Cache();
    T get(int key);
    bool key_exists(int key);
    void put(int key, T &value);
    void print_cache();
};

template<typename T>
LRU_Cache<T>::LRU_Cache(int capacity) {
    std::cout << "LRU_Cache constructor: creating instance with capacity " << capacity << '\n';
    _total_capacity = capacity;
    _current_size = 0;
    _items = new DLinkedList<T>();
    _items_dict = std::map<int, BaseNode<T>*> ();
}

template<typename T>
LRU_Cache<T>::~LRU_Cache(){
    std::cout << "LRU_Cache desstructor" << '\n';
    for (auto& [key, value]: _items_dict) {
        delete value;
    }

    delete _items;
}

template<typename T>
void LRU_Cache<T>::print_cache() {
    std::cout << "printing cache..." << '\n';
    if (_current_size == 0)
    {
        std::cout << "Cache is empty." << '\n';
    }
    
    for (auto& [key, value]: _items_dict) {
        std::cout << key << " => " << value->_value << '\n';
    }
}

template<typename T>
bool LRU_Cache<T>::key_exists(int key){
    return _items_dict.find(key)!=_items_dict.end();
}

template<typename T>
T LRU_Cache<T>::get(int key){
    auto val = _items_dict[key]->_value;
    std::cout << "item with key " << key << " used/fetched by user, bringing it to the front of most recently used list." << '\n';
    _items->move_item_to_front(_items_dict[key]);
    return val;
}

template<typename T>
void LRU_Cache<T>::put(int key, T& value){
    if(_items_dict.find(key)!=_items_dict.end()) {
        // if key already exists, update value and move item to head
        std::cout << "item with key " << key << " already exists in cache." << '\n';
        _items_dict[key]->_value = value;
        _items->move_item_to_front(_items_dict[key]);
        return;
    }

    if(_current_size == _total_capacity) {
        // remove rear item
        int k = _items->get_rear_item()->_key;
        std::cout << "cache reached maximum capacity, removing least recently used item with key " << k << '\n';
        _items_dict.erase(k);
        _items->delete_rear_item();
        _current_size--;
    }

    // add new item to head to Queue
    BaseNode<T> *new_item = _items->add_item_to_front(key, value);
    _current_size++;
    _items_dict[key] = new_item;
    std::cout << "item with key " << key << " added to cache." << '\n';
}
