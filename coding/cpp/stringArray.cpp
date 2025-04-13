#include <iostream>
#include <string>

int main() {
    std::string stringArray[] = {"apple", "banana", "cherry", "date"};
    int arraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    // Using a traditional for loop
    std::cout << "Traversing with a for loop:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        std::cout << stringArray[i] << std::endl;
    }

    // Using a range-based for loop (C++11 and later)
    std::cout << "\nTraversing with a range-based for loop:" << std::endl;
    for (const std::string& str : stringArray) {
        std::cout << str << std::endl;
    }
    
    //Using iterator
    std::cout << "\nTraversing with iterator:" << std::endl;
    for (auto it = std::begin(stringArray); it != std::end(stringArray); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}