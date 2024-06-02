#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;
ifstream in("input.txt");
struct tree {
    int inf;
    tree* right;
    tree* left;
};

tree* node(int x) {
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    return n;
}
void create(tree*& tr, int n) {
    int x;
    if (n > 0) {
        in >> x;
        tr = node(x);
        int nl = n / 2;
        int nr = n - nl - 1;
        create(tr->left, nl);
        create(tr->right, nr);
    }
}
void preorder(tree* tr) {
    if (tr) {
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}
int find_X_Height(tree* tr, int key, int height) {
    if (!tr) {
        return -1; 
    }

    if (tr->inf == key) {
        return height; 
    }

    int leftHeight = find_X_Height(tr->left, key, height + 1);
    if (leftHeight != -1) {
        return leftHeight; 
    }

    int rightHeight = find_X_Height(tr->right, key, height + 1);
    return rightHeight; 
}
int main() {
    setlocale(LC_ALL, "Ru");
    tree* tr = NULL;
    int n, x;
    in >> n;
    create(tr, n);
    preorder(tr);
    int key;
    cout << "Введите значение узла для определения его высоты: ";
    cin >> key;
    int nodeHeight = find_X_Height(tr, key, 0);
    if (nodeHeight != -1) {
        cout << "Высота узла " << key << ": " << nodeHeight << endl;
    }
    else {
        cout << "Узел с заданным значением не найден." << endl;
    }
    cout << endl;
    return 0;
}