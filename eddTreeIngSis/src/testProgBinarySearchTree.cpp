 // Demo para estudiantes de EDD
#include <iostream>
#include "binarySearchTree.h"
 
using namespace std;

int main()
{
    bSearchTreeType<int>  treeRoot;
	
    int num;

    cout << "Enter numbers ending with -999." << endl;
    cin >> num;

    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }

    cout << endl << "Tree nodes in inorder sequence: ";
    treeRoot.inorderTraversal();

    cout << endl << "Tree nodes in preorder sequence: ";
    treeRoot.preorderTraversal();

    cout << endl << "Tree nodes in postorder sequence: ";
    treeRoot.postorderTraversal();
    cout << endl;

    cout << "Tree Height: " << treeRoot.treeHeight()
         << endl;
    cout << "Number of Nodes: "
         << treeRoot.treeNodeCount() << endl;
    cout << "Number or Leaves: "
         << treeRoot.treeLeavesCount() << endl;
    cout << endl;

    cout << "Enter the item to be searched: ";
    cin >> num;
    cout << endl;

    if (treeRoot.search(num))
        cout << num << " is in the binary tree." << endl;
    else
        cout << num << " is not in the tree." << endl;

    cout << "Enter the item to be deleted: ";
    cin >> num;
    cout << endl;

    treeRoot.deleteNode(num);

    cout << endl << "**** After the delete operation.****"
         << endl;
    cout << "Tree nodes in inorder sequence: ";
    treeRoot.inorderTraversal();
    cout << endl << "Tree nodes in preorder sequence: ";
    treeRoot.preorderTraversal();

    cout << endl << "Tree nodes in postorder sequence: ";
    treeRoot.postorderTraversal();
    cout << endl;

    return 0;
}
