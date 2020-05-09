#include "DLinkedList.h"

// template <typename T>
// DLinkedList<T>::DLinkedList(): _front(nullptr), _rear(nullptr) {}

// template <typename T>
// bool DLinkedList<T>::is_empty(){
//     return _rear == nullptr;
// }

// template <typename T>
// BaseNode<T>* DLinkedList<T>::add_item_to_front(int key, T value) {
//     BaseNode<T>* item = new BaseNode(key, value);

//     if(!_front && !_rear) {
//         _front = _rear = item;
//     }
//     else {
//         item->next = _front;
//         _front->prev = item;
//         _front = item;
//     }
//     return item;
// }

// template <typename T>
// void DLinkedList<T>::move_item_to_front(BaseNode<T> *item) {
//     if(item==_front) {
//         return;
//     }
//     if(item == _rear) {
//         _rear = _rear->prev;
//         _rear->next = nullptr;
//     }
//     else {
//         item->prev->next = item->next;
//         item->next->prev = item->prev;
//     }

//     item->next = _front;
//     item->prev = nullptr;
//     _front->prev = item;
//     _front = item;
// }

// template <typename T>
// void DLinkedList<T>::delete_rear_item(){
//     if (is_empty())
//     {
//         return;
//     }
    
//     if (_front == _rear)
//     {
//         delete _rear;
//         _front = _rear = nullptr;
//         return;
//     }

//     auto temp = _rear;
//     _rear = _rear->_prev;
//     _rear->_next = nullptr;
//     delete temp;
// }

// template <typename T>
// BaseNode<T>* DLinkedList<T>::get_rear_item(){
//     return _rear;
// }

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
// void DlinkTemporaryFunction ()
// {
//     DLinkedList<int> TempObj();
//     // DLinkedList<float> TempObj2();
// }