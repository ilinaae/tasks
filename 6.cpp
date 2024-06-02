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

int main() {
    setlocale(LC_ALL, "Ru");
    tree* tr = NULL;
    int n, x;
    in >> n;
    create(tr, n);
    preorder(tr);
    cout << endl;
    return 0;
}