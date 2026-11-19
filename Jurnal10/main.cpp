#include "tree.h"

int main() {
    adrNode root;
    int x;

    createTree_108072500059(root);

    for (int i = 0; i < 9; i++) {
        cout << "Masukkan node: ";
        cin >> x;
        insertNode_108072500059(root, createNode_108072500059(x));
    }

    cout << "\nnode dalam tree (preorder traversal) : ";
    displayTree_108072500059(root);
    cout << "\n\n";

    cout << "banyak leaf node dalam tree     : "
         << countLeafNodes_108072500059(root) << endl;

    cout << "banyak internal node dalam tree : "
         << countInternalNodes_108072500059(root) << endl;

    cout << "besar height pada tree          : "
         << heightTree_108072500059(root) << endl;

    cout << "total value dalam tree          : "
         << sumOfValues_108072500059(root) << endl;

    return 0;
}