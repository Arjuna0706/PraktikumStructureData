#include "tree.h"

int main() {
    adrNode root;
    createTree_108072500059(root);

    infotype x;
    for (int i = 0; i < 9; i++) {
        cout << "Masukkan node: ";
        cin >> x;
        insertNode_108072500059(root, createNode_108072500059(x));
    }

    cout << endl;
    cout << "Node dalam BST: ";
    displayTree_108072500059(root);
    cout << endl;

    adrNode minNode = getMinNode_108072500059(root);
    adrNode maxNode = getMaxNode_108072500059(root);
    cout << "Node terkecil dalam BST: " << minNode->info << endl;
    cout << "Node terbesar dalam BST: " << maxNode->info << endl;

    return 0;
}