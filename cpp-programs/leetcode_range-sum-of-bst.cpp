#include <iostream>
#include <stack>

using namespace std;

/* logic
    - traverse tree and visit each node
    - check if node value is in range; if yes, add to sum
    - return sum
    */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int rangeSumBST(TreeNode* root, int low, int high) {
            TreeNode* curr = root;
            long sum = 0;
            stack<TreeNode*> node_stack;
    
            //non recursive tree traversal - add all nodes to stacks 
            while(curr || !node_stack.empty()) {

                //reach to left most node
                while (curr) {
                    node_stack.push(curr);
                    curr = curr->left;
                }

                curr = node_stack.top();
                node_stack.pop();

                cout << "sum = " << sum << endl;
                cout << "curr->val = " << curr->val << endl;
                if (curr->val >= low && curr->val <= high) {
                    sum = sum + curr->val;
                }

                //go to right of that node.
                curr = curr->right;
            }
            
            return (int)sum;
        }
    };


int main() {
    Solution sol;

    //root = [10,5,15,3,7,null,18], low = 7, high = 15; answer = 32
    TreeNode* root = new TreeNode(10);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(15);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(18);

    //binary tree
    root->left = node1;//5 on left to root 10
    root->right = node2; //15 on right of root 10
    node1->left = node3; //node 1 = 5; 3 on left of 5
    node1->right = node4; //node 1 = 5; 7 on right of 5
    node2->right = node6;//node 2 =15; 18 on right of 15

    int low = 7, high = 15;
    cout << "sum = " << sol.rangeSumBST(root, low, high) << endl;

    return 0;
}


    /* optimized code may be [not implemented here] - its a binary search tree, 
    so find first element and go only right node to find the range. 
    and stop when max is reached.*/