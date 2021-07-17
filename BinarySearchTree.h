#pragma once
#include <iostream>
#include <cstddef>
#include <math.h> 
#include <queue>
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}node;
class BinarySearchTree
{
private:
	Node root;
	

 public :

	 Node* NewNode(int data) {
		 Node* node = new(Node); // "new" is like "malloc"
		 node->data = data;
		 node->left = NULL;
		 node->right = NULL;
		 return(node);
	 }
	 /*
		Given a binary tree, return true if a node
		with the target data is found in the tree..
      */
	 int  lookup(Node* node,int targert);
	 /*
		Give a binary search tree and a number, inserts a new node
		with the given number in the correct place in the tree.
		Returns the new root pointer which the caller should
		then use (the standard trick to avoid using reference parameters).
     */
	 void insert(Node* root, int val);
	 /*
	 traversal. Given a binary tree, count the number of nodes in the tree.
	 */
	 int  size (Node * root);

	 /*
	 Given a binary tree, compute its "maxDepth" -- the number of nodes along the longest path from the root node down
		to the farthest leaf node. The maxDepth of the empty tree is 0,
	 */
	 int  maxDepth(Node *root);
	 /*
	 * Given a non-empty binary search tree (an ordered binary tree), return the minimum data value found in that tree.
     Note that it is not necessary to search the entire tree. 
	 */
	 int  minValue(Node *root);

	 /**
	 Given a non-empty binary search tree (an ordered binary tree), return the maximum data value found in that tree.
      Note that it is not necessary to search the entire tree.
	 **/	 
	 
	 int maxValue(Node* root);
	 /*
	 Given a binary search tree (aka an "ordered binary tree"), iterate over the nodes to print them out in increasing
	 order. So the tree...
				4
			   / \
			  2   5
			 / \
            1   3
     Produces the output "1 2 3 4 5". This is known as an "inorder" traversal of the tree.
	 */
	 void printTree(Node *root);
	 void printPostOrder(Node *root);
	 void printInorder(Node *root);
     void printPreOrder(Node *root);

     int hashPathSum(Node *root, int sum);
     void printPaths(Node *root);
	 void mirror(Node *root);
     void doubleTree();
	 void sameTree();
	 int  countTrees();
     bool isBST();


};

