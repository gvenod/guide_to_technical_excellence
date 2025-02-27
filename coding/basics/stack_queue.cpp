/* Queue/Stack: define, insert, delete, print, traverse, peek, pass as ref to function, create a copy */ 
/* Queue/Stack: swap, reverse, merge, insert duplicate */
/* Priority Queue: default maxHeap; change priority to do minHeap; insert duplicate
 Note: heap - tree based data structure satisfying heap property
	- min-heap, the value of each node is less than or equal to the value of its children
	- max-heap, the value of each node is greater than or equal to the value of its children
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/* custom comparator for changing the priority in priority queue */
//less and greator or default comparator in priority queue to support max and min heap. less/maxheap is the default. 
class compare {
	public:
	 bool operator()(int a, int b){ //pass custom/user data structure 
		 return a > b;//return true or false.
	 }
};

class Solution {	
	
	public:
		void printstack(stack<int>& sta) { //dont pass it as reference.
			stack<int> sta_duplicate(sta); //create copy - initialize dup_q from q 
			cout << " printing =" ;
			while(!sta_duplicate.empty()) {
				 cout << sta_duplicate.top() << " "; 
				 sta_duplicate.pop();
			}
			cout << endl;
		}
		
		/*LIFO - Last In First Out*/
		void playWithStack() {
			stack<int> sta;
			sta.push(1);
			sta.push(2);
			sta.push(3);
			sta.push(4);
			
			cout << " stack size = "<< sta.size() << endl; //get size
			cout << " stack top = "<< sta.top() << endl; //peek			
			//traverse
			printstack(sta);
			
			cout << " stack size = "<< sta.size() << endl;
			sta.pop();//delete from front				
		}
		
		void printq(queue<int>& q) { //dont pass it as reference.
			std::queue<int> q_duplicate(q); //initialize dup q 
			cout << " printing =" ;
			while(!q_duplicate.empty()) {
				 cout << q_duplicate.front() << " "; 
				 q_duplicate.pop();
			}
			cout << endl;
		}
		
		int reverse_q_recursive(queue<int>& q) {
			if(q.empty()) {return 0;} // base case

			int front = q.front();//get the front item
			q.pop();//remove the front item from queue

			reverse_q_recursive(q); //b4 adding to back remove the next element.
			
			q.push(front);//add to back
		}

		/*First In First Out (FIFO)*/
		void playWithQueue() {
			// Creating queue from vector
			vector<int> v = {9, 8, 6, 6, 10, 4, 2};

			queue<int> q, q2, q3;//(v.begin(), v.end());//define
			q.push(5);//insert
			q.push(6);
			cout << " q size = "<< q.size() << endl; //get size
			cout << " q front = "<< q.front() << endl; //peek
			cout << " q back = "<< q.back() << endl; //peek
			printq(q);//traverse/print
			printq(q3);//traverse/print
			
			cout << " q size = "<< q.size() << endl;
			q.pop();//delete from front
			
			
			
			q.push(1);
			q.push(2);
			q.push(3);
			q.push(4);
			printq(q);//traverse/print
			
			//Reverse a queue using stack			
			stack<int> sta;
			while (!q.empty()) {
				sta.push(q.front());
				q.pop();
			}
			while (!sta.empty()) {
				q.push(sta.top());
				sta.pop();
			}
			
			printq(q);//traverse/print

			reverse_q_recursive(q);
			printq(q);
			
				
			q2.push(13);
			q2.push(14);
			printq(q2);//traverse/print
			
			cout << "swap" << endl;
			q.swap(q2);
			
			printq(q);//traverse/print
			printq(q2);//traverse/print
			
			cout << "merge q1 and q2" << endl;
			while(!q2.empty()) {
				q.push(q2.front());
				q2.pop();
			}
			printq(q);//traverse/print
			printq(q2);//traverse/print		
			
			return;
		}
		
		void print_priority_q(priority_queue<int>& pq) { //dont pass it as reference.
			priority_queue<int> pq_duplicate(pq); //initialize dup q 
			cout << " printing =" ;
			while(!pq_duplicate.empty()) {
				 cout << pq_duplicate.top() << " "; 
				 pq_duplicate.pop();
			}
			cout << endl;
		}

		void print_priority_q_min(priority_queue<int, vector<int>,greater<int>>& pq) { //dont pass it as reference.
			priority_queue<int, vector<int>, greater<int>> pq_duplicate(pq); //initialize dup q 
			cout << " printing =" ;
			while(!pq_duplicate.empty()) {
				 cout << pq_duplicate.top() << " "; 
				 pq_duplicate.pop();
			}
			cout << endl;
		}	

		void print_priority_q_max(priority_queue<int, vector<int>,less<int>>& pq) { //dont pass it as reference.
			priority_queue<int, vector<int>, less<int>> pq_duplicate(pq); //initialize dup q 
			cout << " printing =" ;
			while(!pq_duplicate.empty()) {
				 cout << pq_duplicate.top() << " "; 
				 pq_duplicate.pop();
			}
			cout << endl;
		}			
	
		/* priority queue 
			- by default - max value pushed/inserted - will go to top - on calling top will get max value; maxheap 
			- uses same header file <queue>
			- are implemented using a heap data structure
			- accessed like stack using push/top/pop functions*/
		void playWithPriorityQueue() {
						
			priority_queue<int> pq1;
			pq1.push(1);
			print_priority_q(pq1);
			cout << " push new item " << endl;
			pq1.push(2);
			print_priority_q(pq1);
			pq1.push(3);
			print_priority_q(pq1);
			cout << " push duplicate 3 " << endl;
			pq1.push(3);
			print_priority_q(pq1);
			pq1.push(5);
			print_priority_q(pq1);
			pq1.push(4);
			print_priority_q(pq1);
			cout << pq1.top() << endl;
			print_priority_q(pq1);
			
			
			cout << "Default priority queue with max value on top" << endl;
			vector<int> v = {9, 8, 6, 6, 10, 4, 2};
			priority_queue<int> pq2(v.begin(), v.end());
			print_priority_q(pq2);
			cout << " removing item on top " << pq2.top() << endl;
			pq2.pop();
			print_priority_q(pq2);
			cout << " removing item on top " << pq2.top() << endl;
			pq2.pop();
			print_priority_q(pq2);
						
			
			cout << "Changing priority order of priority queue to have min on the top" << endl;
			priority_queue<int, vector<int>, greater<int>> min_pq_order(v.begin(), v.end());
			/*priority_queue<int, vector<int>, greater<int>> min_pq_order;
			min_pq_order.push(2);
			min_pq_order.push(3);
			min_pq_order.push(4);*/
			print_priority_q_min(min_pq_order);
			cout << " removing item on top " << min_pq_order.top() << endl;
			min_pq_order.pop();
			print_priority_q_min(min_pq_order);
			
			cout << "Changing to Default priority order of priority queue to have max on the top" << endl;
			priority_queue<int, vector<int>, less<int>> max_pq_order(v.begin(), v.end());
			print_priority_q_max(max_pq_order);
			
		}
};

int main () {
	Solution sol;
	sol.playWithStack();
	cout << "**************************" << endl;
	sol.playWithQueue();
	cout << "**************************" << endl;
	sol.playWithPriorityQueue();
	return 0;
}