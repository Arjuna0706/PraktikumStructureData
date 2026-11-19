#include "tree.h"

int main() {
    adrNode root;
    createTree_108072500059(root);

    infotype x;
    for (int i = 0; i < 7; i++) {
        cout << "Masukkan node: ";
        cin >> x;
        insertNode_108072500059(root, createNode_108072500059(x));
    }

    cout << endl;
    cout << "Masukkan nilai dari node yang ingin dicari: ";
    cin >> x;
    if (searchNode_108072500059(root, x) != nullptr) {
        cout << "Node dengan nilai " << x << " ditemukan!" << endl;
    } else {
        cout << "Node dengan nilai " << x << " tidak ditemukan!" << endl;
    }

    cout << endl;
    cout << "Print BST (inorder traversal): ";
    displayTree_108072500059(root);
    cout << endl;
    cout << "Jumlah node: " << countNodes_108072500059(root) << endl;
    cout << "Nilai terkecil: " << getMinValue_108072500059(root) << endl;
    cout << "Nilai terbesar: " << getMaxValue_108072500059(root) << endl;

    return 0;
}