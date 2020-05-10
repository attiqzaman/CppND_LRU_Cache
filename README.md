# CPPND: Memory Management Chatbot

This is the project for the capstone project of [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

I chose a simple templated LRU-cache implementation using a doubly linkedList (custom implementation) and a hashmap (std::map<T>).

## Code structure:
* BaseNode => This is a generic class used to store 'items' in our cache.
  * Data Memebers: key, value, pointer to next node, pointer to previous node.
* DLinkedList => A doublyLinkedList custom implementation which uses the aforementioned BaseNode class to create a doubly linked list.
  * Data Memebers: 
    * pointer to front node: so new items can be added to in O(1)
    * pointer to rear node: so items can be removed in O(1)
  * Memeber Functions:
    * add_item_to_front: Adds new items to the front of DLinkedList.
    * move_item_to_front: move an existing item to the front of DLinkedList.
    * delete_rear_item: delete item from the rear of DLinkedList.
    * get_rear_item: get the rear item.
* LRU_Cache => Least Recent Used Cache implementation.
  * Data Memebers: 
    * _total_capacity: (private member) used to track the total capacity of our cache.
    * _current_size: (private memebr) used to track the current size of cache.
    * pointer to DLinkedList object: used to track which items are most recently used.
    * a hasmap of all items in our cache: used to get/put new items in our cache.
  * Member Functions:
    * get: get the item from cache.
    * put: put new item in the cache.
    * key_exists: check if key exists in cache or not.
    * print_cache: helper function to print all entries currently in the cache.

## Rubric points addressed:
  * Loops, Functions:
    * The project demonstrates an understanding of C++ functions and control structures.
  * Object Oriented Programming:
    * The project uses Object Oriented Programming techniques.
    * Classes use appropriate access specifiers for class members.
    * Class constructors utilize member initialization lists.
    * Classes abstract implementation details from their interfaces.
    * Classes encapsulate behavior.
    * Overloaded functions allow the same function to operate on different parameters. (multiple constructors in BaseNode)
    * Templates generalize functions in the project.
  * Memory Management
    * The project makes use of references in function declarations.
    * The project uses destructors appropriately.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./cache`.