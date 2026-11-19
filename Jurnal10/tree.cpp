#include "tree.h"

void createTree_108072500059(adrNode &root) {
    root = nullptr;
}

adrNode createNode_108072500059(int x) {
    adrNode p = new Node;
    p->value = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertNode_108072500059(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
    } else if (p->value < root->value) {
        insertNode_108072500059(root->left, p);
    } else {
        insertNode_108072500059(root->right, p);
    }
}

adrNode searchNode_108072500059(adrNode root, int x) {
    if (root == nullptr) {
        return nullptr;
    } else if (x < root->value) {
        return searchNode_108072500059(root->left, x);
    } else if (x > root->value) {
        return searchNode_108072500059(root->right, x);
    }

    return root;
}

void displayTree_108072500059(adrNode root) {
    if (root != nullptr) {
        cout << root->value << " ";
        displayTree_108072500059(root->left);
        displayTree_108072500059(root->right);
    }
}

int countLeafNodes_108072500059(adrNode root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return countLeafNodes_108072500059(root->left)
         + countLeafNodes_108072500059(root->right);
}

int countInternalNodes_108072500059(adrNode root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    }

    return 1 + countInternalNodes_108072500059(root->left)
         + countInternalNodes_108072500059(root->right);
}

int heightTree_108072500059(adrNode root) {
    if (root == nullptr) {
        return -1;
    }

    int leftHeight = heightTree_108072500059(root->left);
    int rightHeight = heightTree_108072500059(root->right);

    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    }

    return 1 + rightHeight;
}

int sumOfValues_108072500059(adrNode root) {
    if (root == nullptr) {
        return 0;
    }

    return root->value
         + sumOfValues_108072500059(root->left)
         + sumOfValues_108072500059(root->right);
}