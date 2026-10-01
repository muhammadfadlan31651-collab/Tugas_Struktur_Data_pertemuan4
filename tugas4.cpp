#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->kiri = NULL;
    baru->kanan = NULL;
    return baru;
}

Node* insert(Node* root, int nilai) {
    if (root == NULL) {
        return buatNode(nilai);
    }
    if (nilai < root->data) {
        root->kiri = insert(root->kiri, nilai);
    } else if (nilai > root->data) {
        root->kanan = insert(root->kanan, nilai);
    }
    return root;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->kiri);
    preOrder(root->kanan);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->kiri);
    cout << root->data << " ";
    inOrder(root->kanan);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->kiri);
    postOrder(root->kanan);
    cout << root->data << " ";
}

void hapusTree(Node* root) {
    if (root == NULL) return;
    hapusTree(root->kiri);
    hapusTree(root->kanan);
    delete root;
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "input 0 untuk berhenti:" << endl;

    while (true) {
        cin >> angka;
        if (angka == 0) break;
        root = insert(root, angka);
    }

    if (root == NULL) {
        cout << "Tree kosong." << endl;
        return 0;
    }

    cout << "Pre-order  : ";
    preOrder(root);
    cout << endl;

    cout << "In-order   : ";
    inOrder(root);
    cout << endl;

    cout << "Post-order : ";
    postOrder(root);
    cout << endl;

    hapusTree(root);
    return 0;
}
