/*Hashset:
It is a data structure that stores unique elements. It uses a hash function to compute the index for each element, allowing for fast lookups, insertions, and deletions. a hashset only stores the value and not a key-value pair. Duplicates are not allowed in a hashset. In C++, this is implemented as std::unordered_set.

std::set is a container that stores unique elements in a sorted order. By default, it uses the std::less comparator, which orders elements in ascending order using the < operator. there is inbult std:greater comparator.
*/

#include <iostream>
#include <set>
#include <unordered_set>

/*
The comparator must define a strict weak ordering, meaning it must satisfy the following properties:
Irreflexivity: comp(a, a) is always false.
Asymmetry: If comp(a, b) is true, then comp(b, a) is false. 
Transitivity: If comp(a, b) is true and comp(b, c) is true, then comp(a, c) is true. 
Transitivity of incomparability: If comp(a, b) is false and comp(b, a) is false, and comp(b, c) is false and comp(c, b) is false, then comp(a, c) is false and comp(c, a) is false.
*/

struct MyComparator {
	bool operator()(int a, int b) const {
		return a > b; // Sort in descending order
	}
};

//function pointer
bool myComparator(int a, int b) {
	return a > b; // Sort in descending order
}

int main() {
	
	//lamda function - C++ 11 on wards
	auto myComparator = [](int a, int b) {
            return a > b; // Sort in descending order
    };
	
	std::set<int, MyComparator> mySet;//using class
	std::set<int, decltype(myComparator)> mySet(myComparator);//using lamda fuuntion
	std::set<int, bool(*)(int, int)> mySet(myComparator);//using func pointer.
	
	mySet.insert(3);
	mySet.insert(1);
	mySet.insert(4);
	mySet.insert(2);

	for (int x : mySet) {
		std::cout << x << " "; // Output: 4 3 2 1
	}
	std::cout << std::endl;

    // Example of unordered_set (hashset)
    std::unordered_set<std::string> names;
    names.insert("Alice");
    names.insert("Bob");
    names.insert("Alice"); // Duplicate, will not be inserted
    std::cout << "Number of names: " << names.size() << std::endl;

	return 0;
}

