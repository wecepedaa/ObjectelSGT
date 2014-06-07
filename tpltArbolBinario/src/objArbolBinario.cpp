#include "objArbolBinario.hpp"


// La funcion acepta un puntero a TreeNode y un puntero a nodo.
// La funcion inserta el nodo en el arbol apuntado por el puntero
// TreeNode. Esta funcion se llama recursivamente.
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode; // Inserta el nodo
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode); // Busca en el ramal izquierdo
	else
		insert(nodePtr->right, newNode); // Busca en el ramal derecho
}

// insertNode crea un nuevo nodo que contendra su valor, y
// pasa como parametro a la funcion insert
template <class T>
void BinaryTree<T>::insertNode(T item)
{
	TreeNode *newNode; // Puntero al nuevo nodo

	// Crea un nuevo nodo y almacena un valor en su contenido
	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = NULL;

	// Inserta el node.
	insert(root, newNode);
}

// destroySubTree es llamado por el destructor.
// Borra todos los nodos del arbol.
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}


// searchNode determina si un valor esta presente en el arbol.
// Si lo enuentra retorna TRUE de otro modo FALSE.

template <class T>
bool BinaryTree<T>::searchNode(T item)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == item)
			return true;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

// remove llama deleteNode para borrar el nodo cuyo
// valor de contenido es igual a item.
template <class T>
void BinaryTree<T>::remove(T item)
{
	deleteNode(item, root);
}


// deleteNode eleimina el nodo cuyo valor contenido
// es el pasado en item.
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
	if (item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if (item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
}



// makeDeletion toma la referenica a un puntero al nodo
// que sera borrado. El nodo es removido y las ramas
// del arbol inferior son reconectadas.

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
	// Define un puntero temporal que se usara para reconectar
	// el subarbol izquierdo
	TreeNode *tempNodePtr;

	if (nodePtr == NULL)
		cout << "NO se puede borrar un nodo vacio.\n";
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; // Reconcecta el hijo izquierdo
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; // Reconecta el hijo derecho
		delete tempNodePtr;
	}
	// Si el nodo tiene DOS hijos
	else
	{
		// Moverse un nodo a la derecha.
		tempNodePtr = nodePtr->right;
		// Vaya al nodo final izquierdo
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reconecta el subarbo Izquierdo
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reconecta el nodo derechoee.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//****************************************************************
// The displayInOrder member function displays the values *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//****************************************************************
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << "\n";
		displayInOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPreOrder member function displays the values *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << "\n";
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPostOrder member function displays the values *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << "\n";
	}
}

template <class T>
int BinaryTree<T>::alturaArbol(TreeNode *nodePtr )
{
	if (nodePtr == NULL)
		return 0;
	else
		return 1 + max(alturaArbol(nodePtr->left), alturaArbol(nodePtr->right));
}

template <class T>
void copyTree()
{

}
