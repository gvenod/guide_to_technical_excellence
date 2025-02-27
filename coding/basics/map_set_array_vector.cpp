
// linux: compile: g++ <filename.cpp> execute: ./a.out setup: apt install g++
//windows: compile: cl <filename.cpp> execute: <filename> setup: install visual studio c++ build tools

//template: define; get size/count; traverse; add; remove; lookup

//ds: array, vector, set, map, unordered_map, unordered_set, list, stack, queue, 
//priority_queue, deque, forward_list, tree, trie, graph, heap, linked_list, hash_table, 
//bst, avl, red_black_tree, segment_tree, fenwick_tree, suffix_tree, suffix_array, disjoint_set, bloom

#include <iostream>
#include <string> //getline
#include <array>
#include <vector>
#include <algorithm> //sort
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>


using namespace std;

int unordered_map_practice() {

	cout << "hash map or unoredered map" << endl;

	unordered_map <int, int> map1 = {{1, 2}, {2, 3}, {3, 4}};
	cout << "size: " << map1.size() << endl;

	//traverse
	for (auto item:map1) //item is a pair data type std::pair<const int, int>
		cout << item.first << " " << item.second << endl;

	//find, lookup and delete
	unordered_map <int, int>::iterator itr;
	itr = map1.find(2);
	cout << "found using itr and erase : key: " << itr->first << " value: " << itr->second << endl;

	map1.erase(2);

	//traverse
	for (auto item:map1) //item is a pair data type std::pair<const int, int>
		cout << item.first << " " << item.second << endl;

	return 0;
}

/*
 * map: `stores key-value pairs; keys are unique; repeated keys are ignored.`
 *
 */
int map_practice() {
	cout << "map" << endl;
	map <int, int> map1 = {{1, 2}, {2, 3}, {3, 4}};
	cout << "size: " << map1.size() << endl;

	//traverse
	for (auto item:map1) //item is a pair data type std::pair<const int, int>
		cout << item.first << " " << item.second << endl;

	map1.insert({4, 5});
	cout << "add duplicate 1 5 and itshould be ignored." << endl;

	map1.insert({1, 5});

		//traverse
	for (auto item:map1) //item is a pair data type std::pair<const int, int>
		cout << item.first << " " << item.second << endl;
	
	//find, lookup and delete
	map <int, int>::iterator itr;
	itr = map1.find(2);
	cout << "found using itr and erase : key: " << itr->first << " value: " << itr->second << endl;
	map1.erase(2);
	
	cout << " merge with another map"	<< endl;
		//traverse
	map <int, int> map2 = {{0, 9}};
	map1.insert(map2.begin(), map2.end());

			//traverse
	for (auto item:map1) //item is a pair data type std::pair<const int, int>
		cout << item.first << " " << item.second << endl;

		
	return 0;
}

/*
 * unordered_set: to store unique elements in any order [implemented as hash tables ]
 * highlights: repeated elements while adding are ignored. delete by value.
 */

int unordered_set_practice() {
	cout << "unordered_set" << endl;
	unordered_set<int> set1 = {6, 1, 2, 3, 2, 1};
	cout << "size" << set1.size() << endl;
	set1.insert(4);
	//traverse
	for (auto val:set1)
		cout << val << endl;

		
	return 0;
}

/*
 * set: to store unique elements in sorted order [implemented as a balanced tree structure making it possible to maintain order]
 * highlights: repeated elements while adding are ignored. delete by value.
 */
int set_practice() {
	cout << "set" << endl;
	set <int> set1 = {1, 2, 3, 2, 1};

	cout << "size" << set1.size() << endl;
	set1.insert(4);
	set1.erase(2);
	set <int> set2 = {0, 9};
	set1.insert(set2.begin(), set2.end());
	//cout << "find 4" << set1.find(4) << endl;

	int i = 2; // Index to access
    auto it = std::next(set1.begin(), i);
    std::cout << "value at index " << i << " = " << *it << std::endl; 

	//traverse
	for (auto val:set1)
		cout << val << endl;

	set<int>::iterator itr;
	itr = set1.find(4);
	if(itr != set1.end())
		cout << "found using itr" << *itr << endl;
	else
		cout << "not found" << endl;


	//cout << "found using itr" << *itr << endl;

		//traverse
	for (auto it = set1.begin(); it != set1.end(); it++ )
		cout << *it << endl;	

	return 0;
}


int vector_practice() {
	cout << "vector" << endl;

vector<int> vec = { 1, 2, 3};

	//traverse
	for (auto val:vec)
		cout << val << endl;
	
	//insert
	vec.insert( vec.begin()+1, 24 );
	
		//traverse
	for (auto val:vec)
		cout << val << endl;
	
	return 0;
}


int array_practice() {
	cout << "array" << endl;

// using stl
array<int,5> arr1{ 1, 20, 3, 14, 5 }; 
	
	for(auto i:arr1) { cout << i << endl; }// using stl
	
	cout << "front = " << arr1.front() << endl;
	cout << "at index 1  = " << arr1[1]<< endl;
	arr1[1] = 21;
	
	// container operations are supported
	sort(arr1.begin(), arr1.end());
		
	for(auto i:arr1) { cout << i << endl; }// using stl

	int arr[3] = {1, 2, 3 };

	//traverse
	for (int i =0; i < sizeof(arr)/sizeof(arr[0]); i++)
		cout << arr[i] << endl;
	
	//insert
	arr[2] = 4;
	
		//traverse
	for (int i =0; i < sizeof(arr)/sizeof(arr[0]); i++)
		cout << arr[i] << endl;
	
	//delete
	arr[2] = 0;	
	
		//traverse
	for (int i =0; i < sizeof(arr)/sizeof(arr[0]); i++)
		cout << arr[i] << endl;
	
	return 0;
}

int main() {

	string number;
	cout << "Enter number [1. array, 2. set, 3. unordered_Set, 4. vector, 5. map]: ";
    getline(cin, number); // Use getline for strings to handle spaces

	if (number == "1")
		array_practice();
	else if (number == "2")
		set_practice();
	else if (number == "3")
		unordered_set_practice();
	else if (number == "4")
		vector_practice();
	else if (number == "5")
		map_practice();
	else if (number == "6")
		unordered_map_practice();
	else
		cout << "Invalid input" << endl;
	
	return 0;
}
