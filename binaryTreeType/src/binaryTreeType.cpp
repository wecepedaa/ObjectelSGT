//============================================================================
// Name        : binaryTreeType.cpp
// Author      : William Cepeda
// Version     :
// Copyright   : Docencia UNACH
// Description : Hello World in C++, Ansi-style
//============================================================================

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations to implement a
// binary search tree.
//*************************************************************

#ifndef BINARYTREETYPE_HPP_
#define BINARYTREETYPE_HPP_

#include <iostream>
using namespace std;

//definicion del nodo
template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType> *llink;
	binaryTreeNode<elemType> *rlink;
};

// -----------------------------------
//Definicion de la clase
template <class elemType>
class binaryTreeType
{
public:
	const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);
	// Sobrecarga del operador de asignacion =

	bool isEmpty() const;
	// Retorna true si el arbol binario es vacio; de otro modo, retorna false.

	void inorderTraversal() const;
	// Funcion para realizar un recorrido IN-ORDER del arbol binario

	void preorderTraversal() const;
	// Funcion para realizar un recorrido PRE-ORDER del arbol binario

	void postorderTraversal() const;
	// Funcion para realizar un recorrido POST-ORDER del arbol binario


	int treeHeight() const;
	// Devuelve la altura del árbol binario

	int treeNodeCount() const;
	// Devuelve el número de nodos en el árbol binario.

	int treeLeavesCount() const;
	// Devuelve el número de hojas en el árbol binario.

	void destroyTree();
	//Desasigna el espacio de memoria ocupado por el árbol binario.
	//Post-condicion: root = NULL;

	binaryTreeType(const binaryTreeType<elemType>& otherTree);
	//copia del constructor

	binaryTreeType();
	// constructor por omision

	~binaryTreeType();
	//destructor

protected:
	binaryTreeNode<elemType> *root;

private:
	void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRoot);
	// Hace una copia del arbol binario al que apunta otherTreeRoot
	// El puntero copiedTreeRoot apunta a la raiz del arbol binario copiado.

	void destroy(binaryTreeNode<elemType>* &p);
	// Funcion para destruir el arbol binario al que apunta p.
	// Postcondition: p = NULL

	void inorder(binaryTreeNode<elemType> *p) const;
	// Funcion para realizar el recorrido IN-ORDER de arbol
	// binario al que apunta p.

	void preorder(binaryTreeNode<elemType> *p) const;
	// Funcion para realizar el recorrido PRE-ORDER de arbol
	// binario al que apunta p.

	void postorder(binaryTreeNode<elemType> *p) const;
	// Funcion para realizar el recorrido POST-ORDER de arbol
	// binario al que apunta p.

	int height(binaryTreeNode<elemType> *p) const;
	// Funcion que retorna la altura del arbol binario al que apunta p.

	int max(int x, int y) const;
	//Retorna el valor mayor de x , y.

	int nodeCount(binaryTreeNode<elemType> *p) const;
	// Funcion que retorna el numero de nodos en el arbol binario al que apunta p.


	int leavesCount(binaryTreeNode<elemType> *p) const;
	// Funcion que retorna el numero de hojas en el arbol binario al que apunta p.
};

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root == NULL);
}

template <class elemType>
void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
		binaryTreeNode<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;

	else
	{
		copiedTreeRoot = new binaryTreeNode<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
}//end copyTree

template <class elemType>
void inorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template <class elemType>
void preorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void postorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}


template <class elemType>
void binaryTreeType<elemType>::
inorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::
preorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::
postorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}

template <class elemType>
int binaryTreeType<elemType>::
height(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

template <class elemType>
void binaryTreeType<elemType>::copyTree
(binaryTreeNode<elemType>* &copiedTreeRoot,
		binaryTreeNode<elemType>* otherTreeRoot)
		{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new binaryTreeNode<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
		} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
(const binaryTreeType<elemType>& otherTree)
{
	if (otherTree.root == NULL) //otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

//overloading the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=
		(const binaryTreeType<elemType>& otherTree)
{
	if (this != &otherTree) //avoid self-copy
	{
		if (root != NULL) //if the binary tree is not empty,
			//destroy the binary tree
			destroy(root);
		if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}//end else
	return *this;
}

// -----------------------------------------------------------------------------------
//                  ARBOLES BINARIOS DE BUSQUEDA
// -----------------------------------------------------------------------------------
template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
	bool search(const elemType& searchItem) const;
	//Function to determine if searchItem is in the binary
	//search tree.
	//Postcondition: Returns true if searchItem is found in the
	// binary search tree; otherwise, returns false.

	void insert(const elemType& insertItem);
	//Function to insert insertItem in the binary search tree.
	//Postcondition: If no node in the binary search tree has the
	// same info as insertItem, a node with the info insertItem
	// is created and inserted in the binary search tree.

	void deleteNode(const elemType& deleteItem);
	//Function to delete deleteItem from the binary search tree.
	//Postcondition: If a node with the same info as deleteItem
	// is found, it is deleted from the binary search tree.

private:
	void deleteFromTree(binaryTreeNode<elemType>* &p);
	//Function to delete the node to which p points is deleted
	//from the binary search tree.
	//Postcondition: The node to which p points is deleted from
	// the binary search tree.
};


template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const
{
	binaryTreeNode<elemType> *current;
	bool found = false;
	if (root == NULL)
		cerr << "Cannot search the empty tree." << endl;
	else
	{
		current = root;
		while (current != NULL && !found)
		{
			if (current->info == searchItem)
				found = true;
			else if (current->info > searchItem)
				current = current->llink;
			else
				current = current->rlink;
		}//end while
	}//end else
	return found;
}//end search

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
	binaryTreeNode<elemType> *current; //pointer to traverse the tree
	binaryTreeNode<elemType> *trailCurrent; //pointer behind current
	binaryTreeNode<elemType> *newNode; //pointer to create the node

	newNode = new binaryTreeNode<elemType>;
	assert(newNode != NULL);
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;
	if (root == NULL)
		root = newNode;
	else
	{
		current = root;
		while (current != NULL)
		{
			trailCurrent = current;
			if (current->info == insertItem)
			{
				cerr << "The insert item is already in the list-";
				cerr << "duplicates are not allowed."
						<< insertItem << endl;
				return;
			}
			else if (current->info > insertItem)
				current = current->llink;
			else
				current = current->rlink;
		}//end while
		if (trailCurrent->info > insertItem)
			trailCurrent->llink = newNode;
		else
			trailCurrent->rlink = newNode;
	}
}//end insert

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree
(binaryTreeNode<elemType>* &p)
{
	binaryTreeNode<elemType> *current;//pointer to traverse the tree
	binaryTreeNode<elemType> *trailCurrent; //pointer behind current
	binaryTreeNode<elemType> *temp; //pointer to delete the node
	if (p == NULL)
		cerr << "Error: The node to be deleted is NULL." << endl;
	else if(p->llink == NULL && p->rlink == NULL)
	{
		temp = p;
		p = NULL;
		delete temp;
	}
	else if(p->llink == NULL)
	{
		temp = p;
		p = temp->rlink;
		delete temp;
	}
	else if(p->rlink == NULL)
	{
		temp = p;
		p = temp->llink;
		delete temp;
	}
	else
	{
		current = p->llink;
		trailCurrent = NULL;
		while (current->rlink != NULL)
		{
			trailCurrent = current;
			current = current->rlink;
		}//end while
		p->info = current->info;
		if (trailCurrent == NULL) //current did not move;
			//current == p->llink; adjust p
			p->llink = current->llink;
		else
			trailCurrent->rlink = current->llink;
		delete current;
	}//end else
}//end deleteFromTree

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
	binaryTreeNode<elemType> *current; //pointer to traverse the tree
	binaryTreeNode<elemType> *trailCurrent; //pointer behind current
	bool found = false;
	if (root == NULL)
		cout << "Cannot delete from the empty tree." << endl;
	else
	{
		current = root;
		trailCurrent = root;
		while (current != NULL && !found)
		{
			if (current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				if (current->info > deleteItem)
					current = current->llink;
				else
					current = current->rlink;
			}
		}//end while
		if (current == NULL)
			cout << "The delete item is not in the tree." << endl;
		else if (found)
		{
			if (current == root)
				deleteFromTree(root);
			else if (trailCurrent->info > deleteItem)
				deleteFromTree(trailCurrent->llink);
			else
				deleteFromTree(trailCurrent->rlink);
		}//end if
	}
}//end deleteNode


//_____________________________________________________________________________________________
//int main() {
//	cout << "Hola Mundo de Listas y Arboles" << endl; // prints Hola Mundo de Listas y Arboles
////	binaryTreeType<int> tree;
////
////	if(tree.isEmpty())
////		cout << "El arbol tiene elementos";
////	else
////		cout << "El arbol esta VACIO";
//	return 0;
//}


#endif /* BINARYTREETYPE */
