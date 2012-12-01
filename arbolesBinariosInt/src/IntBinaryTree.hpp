/*
 * IntBinaryTree.h
 *
 *  Created on: 30/03/2012
 *      Author: William
 */

#ifndef INTBINARYTREE_H_
#define INTBINARYTREE_H_
#include <iostream>
using namespace std;

class IntBinaryTree
{
private:
	struct TreeNode
	{
		 int value; // El Valor del Nodo
		 TreeNode *left; // Puntero al nodo hijo izquierdo
		 TreeNode *right; // Puntero al nodo hijo derecho
	 };

	 TreeNode *root; // Puntero al nodo raiz

	 // Funciones miembro Privadas
	 void insert(TreeNode *&, TreeNode *&);
	 void destroySubTree(TreeNode *);
	 void deleteNode(int, TreeNode *&);
	 void makeDeletion(TreeNode *&);

	 void displayInOrder(TreeNode *) const;
	 void displayPreOrder(TreeNode *) const;
	 void displayPostOrder(TreeNode *) const;

	 // La palabra const al final de las funciones miembro,
	 // especifican que esta funcion no puede modificar
	 // las variables miembro de una variable de tipo IntBinaryTree.

 public:
	 // Constructor
	 IntBinaryTree()
	 { root = NULL; }

	 // Destructor
	 ~IntBinaryTree()
	 {
		 //destroySubTree(root);
	 }

	 // Operaciones del Arbol Binario
	 void insertNode(int);
	 bool searchNode(int);
	 void remove(int);

	 void displayInOrder() const
	 {
		 displayInOrder(root);
	 }
	 void displayPreOrder() const
	 {
		 displayPreOrder(root);
	 }
	 void displayPostOrder() const
	 {
		 displayPostOrder(root);
	 }
 };
/*
Esta funcion toma como argumentos un puntero a un SubArbol y un puntero a un nuevo nodo.
Busca una ubicacion apropiada en el SubArbol para insertar el nodo, y realiza la insercion.
Tomar en cuenta la declaración del primer parámetro, nodePtr:

	TreeNode *&nodePtr

El parámetro nodePrt no es simplemente un puntero a una estrucutra TreeNode, es una referencia
a un puntero a una estrucutra TreeNode. Esto significa que cualquier accion que se ejecuta en
nodePtr se realiza realmente  en el argumento que fue pasado en nodePtr.

*/

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode; // Inserta el nodo.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode); // Busca en la rama izquierda.
	else
		insert(nodePtr->right, newNode); // Busca en la rama derecha.
}

void IntBinaryTree::insertNode(int num)
{
	TreeNode *newNode; // Puntero a un nuevo nodo

	// Crea un nuevo nodo y almacena en el un numero num
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = NULL;

	// Inserta el nodo..
	insert(root, newNode);
}

/*--------------------------------------------------------------------*
 * La funcion miembro displayInOrder despliega los valores
 * en el subarbol apuntado por nodePtr, haciendo un recorrido
 * INORDER (Simétrico).
 *
 * 1. Recorrer el subárbol izquierdo Inorder.
 * 2. Visitar la raíz.
 * 3. Recorrer el subárbol derecho.
 * -------------------------------------------------------------------*/

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

/*--------------------------------------------------------------------*
* La funcion miembro displayPreOrder despliega los valores
* en el subarbol apuntado por nodePtr, haciendo un recorrido
* PREORDER.
*
* 1. Visitar la raíz
* 2. Recorrer el subárbol izquierdo.
* 3. Recorrer el subárbol derecho.
* -------------------------------------------------------------------*/

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

/*--------------------------------------------------------------------*
* La funcion miembro displayPostOrder despliega los valores
* en el subarbol apuntado por nodePtr, haciendo un recorrido
* POSTORDER.
* 1. Recorrer el subárbol izquierdo.
* 2. Recorrer el subárbol derecho.
* 3. Visitar la raíz.
* -------------------------------------------------------------------*/
void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

bool IntBinaryTree::searchNode(int num)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

#endif /* INTBINARYTREE_H_ */
