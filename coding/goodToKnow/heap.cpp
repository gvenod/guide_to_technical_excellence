/*

A max heap is a specialized tree-based data structure where the value of each parent node is greater than or equal to the value of its children. This property ensures that the root node always contains the largest element in the heap.

By default priority queue implements max heap. This can be changed by using a custom comparator in which you define the priority parameter and how to compare them.

If you only want to assign highest priority to the smallest element (min-heap), then inbuilt greater<type> functional object can be used.

A min heap is a tree-based data structure where the value of each node is less than or equal to the value of its children. This ensures that the smallest element is always at the root of the tree. In C++, std::priority_queue can be used to implement a min heap by specifying std::greater<int> as the comparison function. 

*/

#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue<int> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    
    // Creating a priority queue of integers
    priority_queue<int> maxHeap;
	
    maxHeap.push(9);
    maxHeap.push(10);
    maxHeap.push(6);
    
    cout << maxHeap.top() << " ";
	
	// Creating priority queue from other container
    vector<int> v = {9, 8, 6, 10, 4, 2};
    priority_queue<int> pq2(v.begin(), v.end());
    print(pq2);
	
	
	// Creating priority queue
    priority_queue<int, vector<int>,
                    greater<int>> minHeap;
	minHeap.push(9);
    minHeap.push(8);
    minHeap.push(6);
    
    auto temp = minHeap;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
	
    return 0;
}

