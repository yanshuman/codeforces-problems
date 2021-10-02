#include<iostream>
#include <queue>
using namespace std;

// creating class for a node of a tree
class node{
public:
	int data;
	node* left;
	node* right;
	node(int data){
		this -> data = data;
		this -> left = nullptr;
		this -> right = nullptr;
	}
};

// preorder traversal result of a tree
void preOrder(node* root) {
	if(root == nullptr) {
		return;
	}
	cout << root -> data << " ";
	preOrder(root -> left);
	preOrder(root -> right);
}

// inOrder traversal result of a tree
void inOrder(node* root) {
	if(root  == nullptr) {
		return;
	}
	inOrder(root -> left);
	cout << root -> data << " ";
	inOrder(root -> right);
}

// postOrder traversal result of a tree
void postOrder(node* root) {
	if(root == nullptr) {
		return;
	}
	postOrder(root -> left);
	postOrder(root -> right);
	cout << root -> data << " ";
}

//level order traversal in binary tree

void levelOrder(node* root) {
	if(root == nullptr)
		return;
	queue<node*> q;
	q.push(root);

	while(!q.empty()) {
		node* curr = q.front();
		q.pop();
		cout << curr->data << " ";
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
	}
}

// 	// find the sum of nodes at (k)th level

int sumAtK(node* root, int k) {
	if(root == NULL)
		return -1; // -1 to indicate that no root exists
	queue<node*> q;
	int level = 0, sum = 0;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* curr = q.front();
		q.pop();
		if(curr != NULL) {
			if(level == k){
				sum += curr -> data;
			}
			if(curr -> left)
				q.push(curr -> left);
			if(curr -> right)
				q.push(curr -> right);
		}
		else if(!q.empty()) {
			q.push(NULL);
			level++;
		}
	}
	return sum;
}

// height of a binary tree

int height(node* root) {
	if(root == NULL) {
		return 0;
	}
	int l = height(root -> left);
	int r = height(root -> right);
	return max(l,r) + 1;
}

// number of nodes in a binary tree

int numberOfNodes(node* root) {
	if(root == NULL) {
		return 0;
	}
	int l = numberOfNodes(root -> left);
	int r = numberOfNodes(root -> right);
	return l+r+1;
}

// sum of nodes in a binary tree
int sum(node* root) {
	if(root == NULL)
		return 0;
	return sum(root ->left) + sum(root -> right) + root -> data;
}

// diameter of a binary tree (with time complexity of O(n^2))

int diameter(node* root) {
	if(root == NULL)
		return 0;
	int l = height(root -> left);
	int r = height(root -> right);

	int currDiameter = l + r + 1;

	int lDiameter = diameter(root -> left);
	int rDiameter = diameter(root -> right);

	return max(currDiameter, max(lDiameter, rDiameter));
}

// now finding diameter of tree using optimized method, in O(n) time

int oDiameter(node* root, int* ht) {
	if(root == NULL) {
		*ht = 0;
		return 0;
	}
	int lh = 0, rh = 0;
	int lDia = oDiameter(root -> left, lh);
	int rDia = oDiameter(root -> right, rh);

	int currDia = lh + rh + 1;
	*ht = max(lh, rh) + 1;

	return ht; 
}
// BINARY search tree (code to be written-- binary tree(insertion, deletion, searching),

void binaryInsert(node* root, int val) {
	node* curr = new node(val);
	if(root == NULL) {
		root = curr;
		return;
	}
	if(val < root -> data) {
		binaryInsert(root -> left, val);
	}else
		binaryInsert(root -> right, val);
	// return root;
} 
// avl trees (insertion, deletion, searching, rotatation)






int main() {
	node* root = new node(1);
	root -> left = new node(12);
	root -> right = new node(5);
	root -> left -> left = new node(7);
	root -> left -> right = new node(0);
	root -> right -> left = new node(7);
	root -> right -> right = new node(2);

	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	levelOrder(root);
	cout << endl;
	cout << sumAtK(root, 0);
}