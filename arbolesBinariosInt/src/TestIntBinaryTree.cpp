/*
 * IntBinaryTree.cpp
 *
 *  Created on: 31/03/2012
 *      Author: William
 */

#include "IntBinaryTree.hpp"

int main()
{
	IntBinaryTree tree;

	cout << "Insertar nodos en el arbol binario. ";
	tree.insertNode(5);
	tree.insertNode(8);
	tree.insertNode(3);
	tree.insertNode(12);
	tree.insertNode(9);
	tree.insertNode(100);
	cout << "Mision Cumplida...\n";

	// Despliega inorder.
	cout << "Recorrido Inorder:\n";
	tree.displayInOrder();

	// Despliega preorder.
	cout << "\nRecorrido Preorder:\n";
	tree.displayPreOrder();

	// Despliega postorder.
	cout << "\nRecorrido Postorder:\n";
	tree.displayPostOrder();

	// Busca el valor 3 en el arbol.
	if (tree.searchNode(3))
		cout << "ojo El 3 ha sido encontrado en el árbol.\n";
	else
		cout << "ojo El 3 NO ha sido encontrado en el arbol.\n";

	// Busca el valor 100.
	if (tree.searchNode(1000))
		cout << "ojo El 100 ha sido encontrado en el árbol binario.\n";
	else
		cout << "ojo El 100 NO ha sido encontrado en el arbol."<< endl;

	return 0;
}


