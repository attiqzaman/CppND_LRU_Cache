#ifndef BASENODE_H
#define BASENODE_H


template <class T>
class BaseNode {
    public:
        int _key; // key could have been hashcode of the value (so we can compute it internally instead of force user to send it) but for simplicity keeping it an int.
        T _value;
        BaseNode *_prev, *_next;

        BaseNode<T>(int key, T value);
};

template <class T>
BaseNode<T>::BaseNode(int key, T value): _key(key), _value(value), _prev(nullptr), _next(nullptr) {}

#endif