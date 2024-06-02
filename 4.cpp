#include <iostream>
using namespace std;

struct tree {
    int inf;
    tree* right;
    tree* left;
    tree* parent;
};

tree* node(int x) {//��������� ����
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x) {//�������

    tree* n = node(x);
    if (!tr) tr = n;//���� ������ ������ - ������
    else {
        tree* y = tr;
        while (y) { //���� ���� ���������
            if (n->inf > y->inf) { //������ �����
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; ; //���� ���������� ������ ��������
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf) { //����� �����
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y; ;//���� ���������� ����� ��������
                    y->left = n;
                    break;
                }
            }
        }
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
        cout << endl;
        cout << "������ ������: "  << endl;
        cout << endl;
        return 0;
}