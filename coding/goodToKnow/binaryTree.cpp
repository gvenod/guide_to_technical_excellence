#include <iostream>
#include <algorithm>	//math
#include <cmath>		//abs

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
	Node() : data(0), left(nullptr), right(nullptr) {}
	Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

//A binary tree is considered balanced if, for every node, the height difference between its left and right subtrees is no more than 1.
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

bool isBalanced(Node* root) {
    if (root == nullptr) {//base case
        return true;
    }
	
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);	
    if (std::abs(leftHeight - rightHeight) > 1) {
        return false;
    }
	
    return isBalanced(root->left) && isBalanced(root->right);
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder_traversal(Node* root) {
    if (root != nullptr) {
        inorder_traversal(root->left);
        std::cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

Node* findMin(Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr; //key not found

    if (key < root->data) {
        root->left = deleteNode(root->left, key); //go to left side
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key); //go right
    } else {
        // Node to be deleted found
        if (!root->left) {//no left child; return right.
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {//no right child return left
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node has two children
        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

void dfs_non_recursive(Node* root) {
    if (!root) return;

    std::stack<Node*> node_stack;
    node_stack.push(root);

    while (!node_stack.empty()) {
        Node* current_node = node_stack.top();
        node_stack.pop();
        std::cout << current_node->data << " ";

        if (current_node->right) {
            node_stack.push(current_node->right);
        }
        if (current_node->left) {
            node_stack.push(current_node->left);
        }
    }
}

void bfs(Node* root) {
    if (!root) return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        std::cout << current->data << " ";

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}


int breadthOfTree(Node* root) {
    if (!root) {
        return 0;
    }

    std::queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        maxWidth = std::max(maxWidth, levelSize); 

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }
    return maxWidth;
}

int maxDepth(Node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return std::max(leftDepth, rightDepth) + 1;
    }
}


int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

/*
root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
*/
    std::cout << "Inorder traversal of the constructed BST: \n";
    inorder_traversal(root);
    std::cout << std::endl;
	
	std::cout << "DFS Traversal: ";
    dfs_non_recursive(root);
    std::cout << std::endl;
	
	std::cout << "BFS traversal: ";
    bfs(root);
    std::cout << std::endl;

	deleteNode(root, 20);
	
    return 0;
}