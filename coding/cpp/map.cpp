/*
Hashmap/Hashtable:
It is a data structure that stores key-value pairs, using a hash function to compute the index for each key, which determines the location where the element is stored, allowing for fast lookups, insertions, and deletions of key-value pairs.. Collisions, where different keys produce the same index, are typically handled using techniques like chaining or open addressing. In C++, this is implemented as std::unordered_map.

In C++, the standard std::map does not allow duplicate keys. When attempting to insert a key that already exists, the std::map will not insert a new element; instead, it will either return an iterator to the existing element, or overwrite the value associated with the existing key, depending on the method used for insertion or access.

To handle scenarios requiring duplicate keys, std::multimap should be used. std::multimap allows multiple entries with the same key, maintaining the elements in a sorted order based on the keys.
*/

#include <iostream>
#include <map>
#include <unordered_map>

int main() {
	
    std::map<std::string, int> age_map = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

	//range based
    for (const auto& pair : age_map) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }
	
	//iterator
	for (std::map<std::string, int>::const_iterator it = age_map.begin(); it != age_map.end(); ++it) {
        std::cout << it->first << " is " << it->second << " years old." << std::endl;
    }
	
	//Using Structured Bindings (C++17 and later)
	for (const auto& [name, age] : age_map) {
        std::cout << name << " is " << age << " years old." << std::endl;
    }
	
	// Example of unordered_map (hashmap)
	std::unordered_map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;
	
	
	// Example of multi map
	std::multimap<int, std::string> myMultimap;
    myMultimap.insert({1, "Value 1"});
    myMultimap.insert({1, "Value 2"}); // Allows duplicate key
    myMultimap.insert({2, "Value 3"});

    std::cout << "Multimap size: " << myMultimap.size() << std::endl; // Output: 3
    
    auto range = myMultimap.equal_range(1);
    std::cout << "Values at key 1: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " "; // Output: Value 1 Value 2
    }
    std::cout << std::endl;

    return 0;
}