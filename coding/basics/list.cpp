
#include <iostream>
#include <string> // getline
#include <forward_list> // forward_list
#include <list>


using namespace std;

void forward_list_practice() {
    cout << "forward_list" << endl;
    forward_list<int> list1 = {1, 2, 3, 2, 1};

    cout << "size: " << distance(list1.begin(), list1.end()) << endl;
    list1.push_front(4);
    //traverse
    for (auto val : list1)
        cout << val;
    cout <<  endl;

    list1.sort();
    list1.reverse();

    //traverse
    for (auto val : list1)
        cout << val;
    cout <<  endl;

    list1.unique();

    //traverse
    for (auto val : list1)
        cout << val;
    cout <<  endl;
}

/*
* list: `doubly linked list`
*/
int list_practice() {
    cout << "list" << endl;
    list<int> list1 = {1, 2, 3, 2, 1};
    cout << "size = " << list1.size() << endl;
    list1.push_back(4);
    list1.remove(2);//will it remove both 2s? yes
    //traverse
    for (auto val:list1)
        cout << val << " ";
    cout << endl;


    list<int> list2 = {0, 9};
    list1.splice(list1.end(), list2);
    //cout << "find 4" << list1.find(4) << endl;
    int i = 2; // Index to access
    auto it = std::next(list1.begin(), i);
    std::cout << "value at index " << i << " = " << *it << std::endl;
    
    //traverse
    for (auto val:list1)
        cout << val;
    cout << endl;

    list<int>::iterator itr;
    itr = find(list1.begin(), list1.end(), 4);
    if(itr != list1.end())
        cout << "found using itr = " << *itr << endl;
    else
        cout << "not found" << endl;
    //cout << "found using itr" << *itr << endl;
    
    //traverse
    for (auto it = list1.begin(); it != list1.end(); it++ )
        cout << *it << " ";
    cout << endl;


    return 0;
}


int main() {

	string number;
	cout << "Enter number [1. list, 2. forward_list]: ";
    getline(cin, number); // Use getline for strings to handle spaces

	if (number == "1")
		list_practice();
	else if (number == "2")
		forward_list_practice();
	else
		cout << "Invalid input" << endl;
	
	return 0;
}