/*
In queue, elements are inserted into one end of the container and deleted from the other. deque allow both insertion and deletion to both ends. It also allows random access.

In C++, deque container provides fast insertion and deletion at both ends. Stands for Double Ended QUEue, it is a special type of queue where insertion and deletion operations are possible at both the ends in constant time complexity.

Just like arrays and vectors, deque elements can also be randomly accessed by their indexes using the operator []. Deque also provides the front()and back() methods to easily access the first and last element.

*/

#include <iostream>
#include <deque> //double ended queue - push/pop form front and back.
#include <queue>
using namespace std;

void playWithQueue() {
	std::queue<int> que;

    // Enqueue elements
    que.push(10);
    que.push(20);
    que.push(30);

    std::cout << "Queue size: " << que.size() << std::endl; // Output: 3
    std::cout << "Front element: " << que.front() << std::endl; // Output: 10

    // Dequeue elements
    que.pop();
    std::cout << "Front element after pop: " << que.front() << std::endl; // Output: 20

    que.pop();
    que.pop();

    if (que.empty()) {
        std::cout << "Queue is empty" << std::endl;
    }
}

void playWithDeque() {
	
	//an empty deque
    deque<int> dq1;

    //with default size and value
    deque<int> dq2(3, 4);

    // Creating a deque from an initializer list of 5 elements
    deque<int> dq = {1, 4, 2, 3, 5};
	
	// Inserting elements at back and front
    dq.push_back(6);
    dq.push_front(0);
	
	std::cout << "Element at index 1: " << dq[1] << std::endl;//random access
    
    for (auto x: dq)
        cout << x << " ";
	
	
	// Accessing elements
    cout << dq[2] << endl;
    cout << dq.front() << endl;
    cout << dq.back();
	
	// Updating element - changes the element at index 2 to 8
    dq[2] = 8;
	
	// Traversing using the for loop
    for (int i = 0; i < dq.size(); i++) 
        cout << dq[i] << " ";
	
	
	// Deleting from the back and front
    dq.pop_back();
    dq.pop_front();
    
	dq.erase(dq.begin());
}

int main() {
	
	playWithQueue();
	playWithDeque();
		
    return 0;
}