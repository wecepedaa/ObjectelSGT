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
	cout << "\nEstos son los valores registrados en el �rbol (InOrder) :\n";
	tree.displayInOrder();

	// Display the values.
	cout << "\nEstos son los valores registrados en el �rbol (PostOrder) :\n";
	tree.displayPostOrder();

	// Display the values.
	cout << "\nEstos son los valores registrados en el �rbol (PreOrder) :\n";
	tree.displayPreOrder();

	cout << "\n Busca un valor en el �rbol \n";
	tree.searchNode("pepe");

	// Calcula la altura del arbol
	// La altura de un �rbol binario es el n�mero de nodos de la trayectoria
	// m�s larga desde la ra�z a una hoja.
	cout << " La altura del arbol binario es : " << tree.alturaArbol();
	return 0;
}
