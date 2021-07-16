#pragma once
#include <cstddef>
struct node {
	int data;
	struct node* left;
	struct node* right;
};
class BinarySearchTree
{
private:
	node root;
	

 public :

	 struct node* NewNode(int data) {
		 struct node* node = new(struct node); // "new" is like "malloc"
		 node->data = data;
		 node->left = NULL;
		 node->right = NULL;
		 return(node);
	 }
	 int lookup(int targert);
	 void inser(int val);
	 int size ();
	 int maxDepth();
	 int minValue();
		 void printTree();
		 void printPostOrder();
		 void printInorder();
		 void printPretPost();
		 void hashPathSum();
		 void printPaths();
		 bool mirror();
		 void doubleTree();
		 void sameTree();
		 int countTrees();
		 bool isBST();


};

