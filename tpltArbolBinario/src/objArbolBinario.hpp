/*
 * objArbolBinario.hpp
 *
 *  Created on: 05/04/2012
 *      Author: William
 */

#ifndef OBJARBOLBINARIO_HPP_
#define OBJARBOLBINARIO_HPP_

#include <iostream>
using namespace std;

// Stack template
template <class T>
class BinaryTree
{
private:
	struct TreeNode
	{
		T value; // El valor del nodo
		TreeNode *left; // Puntero al nodo hoja izquierdo
		TreeNode *right; // Puntero al nodo hoja derecho
	};

	TreeNode *root; // Puntero al nodo raiz

	// Funciones miembro privadas
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(T, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

	int  alturaArbol(TreeNode *);
	//void copyTree(TreeNode *&, TreeNode *&);

public:
	// Constructor
	BinaryTree()
	{ root = NULL; }

	// Destructor
	~BinaryTree()
	{ destroySubTree(root); }

	// Operaciones del arbol binario
	void insertNode(T);
	bool searchNode(T);
	void remove(T);

	void displayInOrder() const
	{ displayInOrder(root); }

	void displayPreOrder() const
	{ displayPreOrder(root); }
	void displayPostOrder() const
	{ displayPostOrder(root); }

	int  alturaArbol()
	{
		return alturaArbol(root);
	}

	void copyTree()
	{
		//return copyTree(root, root);
	}

};

#endif /* OBJARBOLBINARIO_HPP_ */
