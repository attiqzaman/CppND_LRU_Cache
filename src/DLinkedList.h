#include <iostream>
#include "BaseNode.h"

template <class T>
class DLinkedList
{
private:
    BaseNode<T> *_front, *_rear;
    bool is_empty();

public:
    DLinkedList();
    
    BaseNode<T>* add_item_to_front(int key, T value);
    void move_item_to_front(BaseNode<T> *item);

    void delete_rear_item();
    BaseNode<T>* get_rear_item();
};

template <typename T>
DLinkedList<T>::DLinkedList(): _front(nullptr), _rear(nullptr) {}

template <typename T>
bool DLinkedList<T>::is_empty(){
    return _rear == nullptr;
}

template <typename T>
BaseNode<T>* DLinkedList<T>::add_item_to_front(int key, T value) {
    BaseNode<T>* item = new BaseNode(key, value);

    if(!_front && !_rear) {
        _front = _rear = item;
    }
    else {
        item->_next = _front;
        _front->_prev = item;
        _front = item;
    }
    return item;
}

template <typename T>
void DLinkedList<T>::move_item_to_front(BaseNode<T> *item) {
    if(item==_front) {
        return;
    }
    if(item == _rear) {
        _rear = _rear->_prev;
        _rear-> _next = nullptr;
    }
    else {
        item->_prev->_next = item->_next;
        item->_next->_prev = item->_prev;
    }

    item->_next = _front;
    item->_prev = nullptr;
    _front->_prev = item;
    _front = item;
}

template <typename T>
void DLinkedList<T>::delete_rear_item(){
    if (is_empty())
    {
        return;
    }
    
    if (_front == _rear)
    {
        delete _rear;
        _front = _rear = nullptr;
        return;
    }

    auto temp = _rear;
    _rear = _rear->_prev;
    _rear->_next = nullptr;
    delete temp;
}

template <typename T>
BaseNode<T>* DLinkedList<T>::get_rear_item(){
    return _rear;
}

