
/*
 regular/general tree 
	- insertion can place a new node as a child of any existing node, allowing for an arbitrary number of children per node. binary tree  - insertion, a new node can only be added as a left or right child of a parent node, limiting each node to a maximum of two children;
 
 binary search tree [BST]
	- no duplicates; left child is typically considered "less than" the parent and the right child "greater than". due to the ordering property, searching for a specific value in a binary tree is usually faster than in a regular tree, especially when using a binary search algorithm O(h)
 
 self balancing tree [B-tree] 
	- as its nodes are sorted in the inorder traversal. a node can have more than two children. B-tree has a height of logM N (Where ‘M’ is the order of tree and N is the number of nodes). And the height is adjusts automatically at each update. data is sorted in a specific order, with the lowest value on the left and the highest value on the right. 
 
 AVL tree [self balancing BST] achived using left /right rotation.
	-The AVL trees are more balanced compared to Red-Black Trees, but they may cause more rotations during insertion and deletion. 
	And if the insertions and deletions are less frequent and search is a more frequent operation
	
Red Black Tree
	- are a type of balanced binary search tree that use a set of rules to maintain balance, ensuring logarithmic time complexity for operations like insertion, deletion, and searching, regardless of the initial shape of the tree. are self-balancing, using a simple color-coding scheme to adjust the tree after each modification. [root - black. leaves - black, every path will have same no of blacks;no consecutive red] O(log n)

*/


/* 
** Tree related direct questions ** 
 - define tree 
 - insert [as root, as left node, as middle node]
 - insert duplicate value; left <= root; right > root
 - print, calculate no of nodes.
 - depth first search [pre order, inorder, postorder]
	- calculate max depth / height
	- is tree balanced?
 - breadth first search
	- calculate levels
 - find value, find next node; given start node find end node
 - is tree binary tree? sorted tree? 
 - delete tree
 - delete a node, [ root node, middle node, leaf node].
 - balance tree, rotate tree [left , right] 
 -
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {

	struct stNode {
		int val;
		struct stNode *pLeft;
		struct stNode *pRight;
		stNode(int data) : val(data), pLeft(nullptr), pRight(nullptr) {}
	};

	struct stNode *pRoot = NULL;

	
	struct stNode* insert(struct stNode *pRt, int val) {
		if (pRt == NULL) { //base case
			cout << "new node created" << endl;
			return new stNode(val);
		} 
		cout << val << " =  in val : existing val = " << pRt->val << endl;
		if(val <= pRt->val) { // left <= root
			cout << "going left" << endl;
			pRt->pLeft = insert(pRt->pLeft, val);
		} else { //right > root
			cout << "going right" << endl;
			pRt->pRight = insert(pRt->pRight, val);
		}
		
		return pRt;
	}
	
	/*There are three types of depth-first traversal: pre-order, in-order, and post-order.*/
	int dfs(struct stNode *pRt) {
		if(pRt == NULL) { //base case 
			//cout<< "base case reached" << endl; 
			return 0;
		} 
		cout << pRt->val << ", "; //preorder - read data first and then L and R
		int noOfNodesLeft = dfs(pRt->pLeft);
		int noOfNodesRight = dfs(pRt->pRight);
		return 1 + noOfNodesLeft + noOfNodesRight;
	}

	int bfs(struct stNode *pRt) {
		if(pRt == NULL) return;
		
		Queue<struct stNode*> qNode;
		qNode.insert(pRt);
		
		while(!q.empty() {
			struct stNode *pCurr = q.deque();
			cout << pCurr->val << endl;
			qNode.insert(pCurr->pLeft);
			qNode.insert(pCurr->pRight);			
		}
	}
	
	bool find(struct stNode *pRt, int val) {
		if(pRt == NULL) { //base case 
			//cout<< "base case reached" << endl; 
			return false;
		} 
		if(val == pRt->val) {
			cout << "found" << endl;
			return true;
		} else if(val < pRt->val) {
			cout << "searching left" << endl;
			return find(pRt->pLeft, val);
		} else {
			cout << "searching right" << endl;
			return find(pRt->pRight, val);
		}		
	}
	
	int getDepth(struct stNode *pRt) {
		if(pRt == NULL) { //base case 
			//cout<< "base case reached" << endl; 
			return 0;
		}		
		int leftDepth = getDepth(pRt->pLeft); //get depth of left sub treee
		int rightDepth = getDepth(pRt->pRight);	
		
		return 1 + max( leftDepth, rightDepth);
	}
	
	int deleteTree(struct stNode *pRt) {
		if(pRt == NULL) { //base case 
			//cout<< "base case reached" << endl; 
			return 0;
		}
		deleteTree(pRt->pLeft);
		deleteTree(pRt->pRight);
		
		delete pRt;
		
		return 0;		
	}
	
	struct stNode* deleteNode(struct stNode *pRt, int val) {
		if(pRt == NULL) { //base case 
			//cout<< "base case reached" << endl; 
			return 0;
		}
		
		if(val == pRt->val) {
			cout << "found the node to be deleted" << endl;
			//how to link to parent node?
			
			if ((pRt->pLeft == NULL) && (pRt->pRight == NULL)) {//leaf node - no child
			
			} else if ((pRt->pLeft != NULL) && (pRt->pRight == NULL)) { //has one left child
				struct stNode * temp = pRt->pLeft;
				delete pRt;
				return temp;
				
			} else if ((pRt->pRight != NULL) && && (pRt->pLeft == NULL)) { //has one right child
				
			}
		} else if(val < pRt->val) {
			cout << "searching left" << endl;
			pRt->pLeft=deleteNode(pRt->pLeft, val);
			return pRt->pLeft;
		} else {
			cout << "searching right" << endl;
			pRt->pRight=deleteNode(pRt->pRight, val);
			return pRt->pRight;
		}		
			
			
	
	}
public:
		void print() {
			cout << "printing ";
			cout << "no of nodes = " << dfs(pRoot) << endl;
			cout << endl;
		}
		
		int insert(int val) {
			cout << "inserting " << val << endl;
			struct stNode *pRef = insert(pRoot, val);
			if(pRoot == NULL) {
				pRoot = pRef;
				cout << "root stored " << pRoot << endl;
			} //store root;
			return 0;
		}
		
		int getMaxDepth() {
			return getDepth(pRoot);
		}
		
		bool find(int val) {
			return find(pRoot, val);
		}
		
		int deleteNode(int val) {
			deleteNode(pRoot, val);
			return 0;
		}
		
		int deleteTree() {
			return deleteTree(pRoot);
		}
};

int main() {
	
	Solution sol;
	sol.print();
	sol.insert(1);
	sol.insert(3);
	sol.insert(2);
	sol.insert(2);
	sol.print();
	sol.insert(4);
	sol.print();
	cout << "max depth " <<  sol.getMaxDepth() << endl;
	cout << "is 7 found? " <<sol.find(7) << endl;
	cout << "is 3 found? " <<sol.find(3) << endl;
	sol.deleteNode(3);
	sol.deleteTree();
	return 0;
}