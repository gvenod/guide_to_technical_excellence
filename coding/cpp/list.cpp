/*
The std::list in C++ is a container that implements a doubly linked list. Each element in a std::list stores a value and pointers to both the previous and next elements in the sequence, allowing for bidirectional traversal. This structure enables efficient insertion and removal of elements from any position within the list in constant time, O(1). However, it does not support fast random access like arrays or vectors, as accessing an element requires traversing the list from the beginning or end.
*/

#include <iostream>
#include <list> //default is double linked list

//A custom comparison function can be passed to sort() to define a specific sorting order.
bool compareDescending(int a, int b) {
    return a > b;
}

int main() {
    std::list<int> myList = {5, 2, 8, 1, 9};

    // Using iterators
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using range-based for loop
    for (int element : myList) {
        std::cout << element << " ";
    }
    std.cout << std::endl;

	// Remove a specific element
    myList.remove(2); // Removes all occurrences of 2

    // Remove an element at a specific position
    std::list<int>::iterator it = myList.begin();
    std::advance(it, 2); // Move iterator to the 3rd element
    myList.erase(it); // Removes the element at the iterator position

    // Remove the first element
    myList.pop_front();

    // Remove the last element
    myList.pop_back();
    
    // Clear the entire list
    //myList.clear();
	
	myList.sort(); // Sorts the list in ascending order

    // Print the list after deletion
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
	
	myList.sort(compareDescending); // Sorts the list in descending order

    // Print the sorted list
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;	
	
    return 0;
}
