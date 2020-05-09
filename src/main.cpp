#include <iostream>
#include "LRU_Cache.h"

int main() {
    std::cout << "Hello World!" << "\n";

    LRU_Cache<int> cache(2);
    std::cout << "capacity " << cache._total_capacity << " size " << cache._current_size << "\n";

    cache.put(2,2);
    std::cout << cache.get(2) << "\n";
    std::cout << cache.get(1) << "\n";
    // std::cout << cache.get(1) << "\n";
    // cache.put(1,1);
    // cache.put(1,5);

    return 0;
}