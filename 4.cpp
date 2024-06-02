#include <iostream>
using namespace std;

struct tree {
    int inf;
    tree* right;
    tree* left;
    tree* parent;
};

tree* node(int x) {//начальный узел
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x) {//вставка

    tree* n = node(x);
    if (!tr) tr = n;//если дерево пустое - корень
    else {
        tree* y = tr;
        while (y) { //ищем куда вставлять
            if (n->inf > y->inf) { //правая ветка
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; ; //узел становится правым ребенком
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf) { //левая ветка
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y; ;//узел становится левым ребенком
                    y->left = n;
                    break;
                }
            }
        }
    }
}
void inorder(tree * tr) { 
        if (tr) {
            inorder(tr->left);
            cout << tr->inf << " ";
            inorder(tr->right);
        }
}
int height(tree* tr) {
    if (!tr)
        return -1;
    else {
        int left_height = height(tr->left);
        int right_height = height(tr->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
int main() {
        setlocale(LC_ALL, "Ru");
        int n, x;
        cout << "n="; cin >> n;
        tree* tr = NULL;
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            cin >> x;
            insert(tr, x);
        }
        inorder(tr); cout << endl;
        cout << "Высота дерева: "  << height(tr) << endl;
        cout << endl;
        return 0;
}