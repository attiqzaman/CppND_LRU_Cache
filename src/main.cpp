#include <iostream>
#include "LRU_Cache.h"
#include <string>

int main() {
    std::cout << "Hello, This LRU-Cache library can store any primitive or complex C++ type" << "\n";
    std::cout << "For demo, we will be creating a string cache..." << "\n \n";

    LRU_Cache<std::string> cache(3); // create string cache of max 3 items.
    std::string k1 = "key 1";
    std::string k2 = "key 2";
    std::string k3 = "key 3";
    std::string k4 = "key 4";

    cache.put(1, k1);
    cache.put(2, k2);
    cache.put(3, k3); // at this point we should have our cache at max capacity with all three elements.

    std::cout << "\n";
    cache.print_cache(); // we should get all three elements printed on screen
    std::cout << "\n";

    // lets re-use one of the existing elements from cache, effectively bring it to the front of most recent used list
    cache.get(1);
    std::cout << "\n";

    cache.put(4, k4);; // item 2 should be removed from cache because thats the least recently used item
    std::cout << "\n";

    cache.print_cache(); // we should get item 1, 3 and 4
    std::cout << "\n";

    k4 = "key 4 updated";
    cache.put(4, k4);; // update item 4's value
    std::cout << "\n";

    cache.print_cache(); // we should get item 1, 3 and 4 like before but item 4 should have the updated value.
    std::cout << "\n";

    return 0;
}