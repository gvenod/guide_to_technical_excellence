#include <iostream>
#include <utility>
#include <string>

int main() {
    std::pair<int, std::string> my_pair = {1, "example"};
	
    // Structured binding declaration
    auto [number, text] = my_pair;

    // Accessing elements using structured binding names
    std::cout << "Number: " << number << std::endl;
    std::cout << "Text: " << text << std::endl;

    // Modifying elements through structured binding (if not const)
    number = 42;
    text = "modified";

    std::cout << "Modified Number: " << number << std::endl;
    std::cout << "Modified Text: " << text << std::endl;

    // Original pair is also modified
     std::cout << "Original pair Number: " << my_pair.first << std::endl;
    std::cout << "Original pair Text: " << my_pair.second << std::endl;
	
	// Direct construction of pair using CTAD (C++17 and later)
	std::pair pair3{20, "world"};
	
	// Using make_pair to create a pair of int and string
  ``auto pair1 = std::make_pair(10, "hello");

	  // Using make_pair with different data types
	  auto pair2 = std::make_pair(3.14, 'A');

	  // Displaying the pairs
	  std::cout << "pair1: (" << pair1.first << ", " << pair1.second << ")" << std::endl; // Output: pair1: (10, hello)
	  std::cout << "pair2: (" << pair2.first << ", " << pair2.second << ")" << std::endl; // Output: pair2: (3.14, A)




    return 0;
}