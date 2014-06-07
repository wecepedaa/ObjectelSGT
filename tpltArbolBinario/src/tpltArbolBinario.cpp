//============================================================================
// Name        : tpltArbolBinario.cpp
// Author      : William Cepeda
// Version     :
// Copyright   : Docencia UNACH
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <iostream>
#include "objArbolBinario.cpp"
using namespace std;
const int NUM_NODES = 5	;

int main()
{
	string name;

	// Create the binary tree.
	BinaryTree<string> tree;

	// Insert some names.
	for (int count = 0; count < NUM_NODES; count++)
	{
		cout << "	Ingrese un nombre: ";
		getline(cin, name);
		tree.insertNode(name);
	}

	// Display the values.
	cout << "\nEstos son los valores registrados en el árbol (InOrder) :\n";
	tree.displayInOrder();

	// Display the values.
	cout << "\nEstos son los valores registrados en el árbol (PostOrder) :\n";
	tree.displayPostOrder();

	// Display the values.
	cout << "\nEstos son los valores registrados en el árbol (PreOrder) :\n";
	tree.displayPreOrder();

	cout << "\n Busca un valor en el árbol \n";
	tree.searchNode("pepe");

	// Calcula la altura del arbol
	// La altura de un árbol binario es el número de nodos de la trayectoria
	// más larga desde la raíz a una hoja.
	cout << " La altura del arbol binario es : " << tree.alturaArbol();
	return 0;
}
