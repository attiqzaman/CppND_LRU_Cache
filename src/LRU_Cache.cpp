#include <iostream>
#include <map>

#include "LRU_Cache.h"


// template<typename T>
// LRU_Cache<T>::LRU_Cache(int capacity) {
//     _total_capacity = capacity;
//     _current_size = 0;
//     _items = new DLinkedList<int>();
//     _items_dict = std::map<int, BaseNode<T>*> ();
// }

// template<typename T>
// LRU_Cache<T>::~LRU_Cache(){
//     for (auto it = _items_dict.begin(); it != _items_dict.end(); it++)
//     {
//        // TODO
//     }
// }

// template<typename T>
// BaseNode<T>* LRU_Cache<T>::get(int key){
//     if(_items_dict.find(key)==_items_dict.end()) {
//         return -1;
//     }

//     auto val = _items_dict[key]->value;

//     // move the page to front
//     _items->move_item_to_front(_items_dict[key]);
//     return val;
// }

// template<typename T>
// void LRU_Cache<T>::put(int key, T value){
//     if(_items_dict.find(key)!=_items_dict.end()) {
//           // if key already present, update value and move item to head
//           _items_dict[key]->value = value;
//           _items->move_item_to_front(_items_dict[key]);
//           return;
//       }

//         if(_current_size == _total_capacity) {
//           // remove rear item
//           int k = _items->get_rear_item()->key;
//           _items_dict.erase(k);
//           _items->delete_rear_item();
//           _current_size--;
//         }

//         // add new item to head to Queue
//         BaseNode<T> *new_item = _items->add_item_to_front(key, value);
//         _current_size++;
//         _items_dict[key] = new_item;
// }

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
// void TemporaryFunction ()
// {
//     LRU_Cache<int> TempObj(1);
//     // LRU_Cache<float> TempObj2(1);
// }