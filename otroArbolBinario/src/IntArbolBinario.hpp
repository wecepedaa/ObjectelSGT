/*
 * IntArbolBinario.hpp
 *
 *  Created on: 04/04/2012
 *      Author: William
 */

#ifndef INTARBOLBINARIO_HPP_
#define INTARBOLBINARIO_HPP_

class IntBinaryTree
{

private:
	// La clase TreeNode es usada para construir el arbol.
	class TreeNode
	{
		friend class IntBinaryTree;
		int value;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int value1, TreeNode *left1 = 0,
				TreeNode *right1 = 0)
		{
			value = value1;
			left = left1;
			right = right1;
		}
	};

	TreeNode *root; // Pointer to the root of the tree

	// Various helper member functions.
	void insert(TreeNode *&, int);
	void destroySubtree(TreeNode *);
	void remove(TreeNode *&, int);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *);
	void displayPreOrder(TreeNode *);
	void displayPostOrder(TreeNode *);

public:
	// These member functions are the public interface.
	IntBinaryTree() // Constructor
	{ root = 0; }
	~IntBinaryTree() // Destructor
	{
		destroySubtree(root);
	}
	void insert(int num)
	{
		insert(root, num);
	}
	bool search(int);
	void remove(int num)
	{ remove(root, num);}

	void showInOrder(void)
	{ displayInOrder(root); }
	void showPreOrder()
	{ displayPreOrder(root); }
	void showPostOrder()
	{ displayPostOrder(root); }
};


#endif /* INTARBOLBINARIO_HPP_ */
