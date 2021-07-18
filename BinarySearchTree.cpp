#include "BinarySearchTree.h"

int BinarySearchTree::lookup(struct Node* node,int target)
{
	if (node == NULL)
		 return 0;
	if (node->data == target) {
		return true;
    if (target < node->data)
			return lookup(node->left, target);
     else
			return lookup(node->right, target);
	}	
}

void BinarySearchTree::insert(Node* rootNode, int val)
{
	Node* newNode = NewNode(val);

	if (rootNode == NULL) {
		rootNode = newNode;
	}
	else if (val <= rootNode->data) {
		insert(rootNode->left, val);
	}
	else {
		insert(rootNode->right, val);
	}
}


int BinarySearchTree::size(Node * root) {

	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + size(root->left) + size(root->right);
	}
}

int BinarySearchTree::maxDepth(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else {

		int lmaxDepth = maxDepth(root->left);
		int rmaxDepth = maxDepth(root->right);
		if (lmaxDepth > rmaxDepth) return 1 + lmaxDepth;
		else
			return 1 + rmaxDepth;

	}

}
/*
Given a non-empty binary search tree,
return the minimum data value found in that tree.
*/
int BinarySearchTree::minValue(Node* root)
{
	Node* curr = root;
	while (curr != NULL) {
	
		curr = curr->left;
	
	}
	if (curr!=NULL) {
		return curr->data;
	}
	
	return 0;
}

int BinarySearchTree::maxValue(Node* root)
{
	Node* curr = root;
	while (curr != NULL) {

		curr = curr->right;

	}
	if (curr != NULL) {
		return curr->data;
	}


	return 0;
}
/*
Given a binary search tree, print out
its data elements in increasing
sorted order.
*/
void BinarySearchTree::printTree(Node* root)
{
	if (root == NULL) return;
	printTree(root->left);
	std::cout << root->data;
	printTree(root->right);
}
/*
Given a binary tree, print its
nodes according to the "bottom-up"
postorder traversal.
*/
void BinarySearchTree::printPostOrder(Node* root)
{
	if (root == NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	std::cout << root->data;
}

void BinarySearchTree::printInorder(Node* root)
{
	if (root == NULL) return;
	printInorder(root->left);
    std::cout << root->data;
	printInorder(root->right);
}

void BinarySearchTree::printPreOrder(Node* root)
{
	if (root == NULL) return;
    std::cout << root->data;
	printPreOrder(root->left);
	printPreOrder(root->right);

}

/*
Given a tree and a sum, return true if there is a path from the root
down to a leaf, such that adding up all the values along the path
equals the given sum.
*/
int BinarySearchTree::hashPathSum(Node* root, int sum)
{
	if (root == NULL) {
		return (sum == 0);
	}
	else {

		int subSum = sum - root->data;
		return hashPathSum(root->left, subSum) || hashPathSum(root->right, subSum);
	}

}
/*
Given a binary tree, print out all of its root-to-leaf
paths, one per line. Uses a recursive helper to do the work.
*/
void BinarySearchTree::printPaths(Node * root)
{
	int path[1000];
	printPathsHelper(root, path, 0);
}

void BinarySearchTree::printPathsHelper(Node* node, int path[], int pathlen) {
	if (node == NULL) return;
	path[pathlen] = node->data;
	pathlen++;

	if (node->left == NULL && node->right == NULL) {

		printArray(path, pathlen);
	}
	else {
		printPathsHelper(node->left, path, pathlen);
		printPathsHelper(node->right, path, pathlen);

	}


}

void BinarySearchTree::printArray(int ints[], int len) {
	for (int i =0 ; i < len; i++) {
	
		std::cout << ints[i];
	}

}

/*
Change a tree so that the roles of the
left and right pointers are swapped at every node.
So the tree...
			4
		   / \
		  2   5
		 / \
		1   3
is changed to...
			4
		   / \
		  5   2
			 / \
			3   1

*/
void BinarySearchTree::mirror(Node *root)
{
	if (root == NULL) return;
	mirror(root->left);
	mirror(root->right);
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	
}

/*
For each node in a binary search tree,
create a new duplicate node, and insert
the duplicate as the left child of the original node.
*/
void BinarySearchTree::doubleTree(Node *node)
{ 
	Node* oldleft;
	if (node == NULL) return;
	doubleTree(node->left);
	doubleTree(node->right);
	oldleft = node->left;
	node->left = NewNode(node->data);
	node->left->left = oldleft;

}
/*
Given two trees, return true if they are
structurally identical.
*/
int BinarySearchTree::sameTree(Node * a, Node *b)
{
	if (a == NULL && b == NULL) return true;
	else if (a != NULL && b != NULL) {
		return (a->data == b->data) && sameTree(a->left, b->left)
			&& sameTree(a->right, b->right);
	}
	else
	return false;
	


}
/*
For the key values 1...numKeys, how many structurally unique
binary search trees are possible that store those keys.
*/

int BinarySearchTree::countTrees(int numKeys) {
	if (numKeys <= 1)
		return 1;
	int sum = 0;
	int left, right, root;
	for (root = 1; root <= numKeys; root++) {
		left = countTrees(root - 1);
		right = countTrees(numKeys - root);
		sum += left * right;
	}
	return sum;
}

bool BinarySearchTree::isBST(Node *root)
{
	if (root == NULL)
		return true;
	if ((root->left != NULL && root->left->data >= root->data)
		||
		(root->right!=NULL && root->data>= root->right->data)) {
		return false;
	}
	return isBST(root->left) && isBST(root->right);
	
}


bool BinarySearchTree::isABSTUtil(Node* node, int min, int max)
{
	if (node == NULL) return true;
	if ((node->data < min) || (node->data > max)) return false;
	

	return isABSTUtil(node->left, min, node->data) && 
		isABSTUtil(node->right, node->data, max);
}