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
void BinarySearchTree::printPaths()
{
}

void printPathsHelper(Node* node, int path[], int pathlen) {
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

void printArray(int ints[], int len) {
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
			5 2
			/ \
			3 1

*/
bool BinarySearchTree::mirror()
{
	return false;
}

void BinarySearchTree::doubleTree()
{
}

void BinarySearchTree::sameTree()
{
}

int BinarySearchTree::countTrees()
{
	return 0;
}

bool BinarySearchTree::isBST()
{
	return false;
}
