#include <iostream>
#include <cmath>
using namespace std;

struct stack { 
    int inf;
    stack* next;
};

void push(stack*& h, int x) { 
    stack* r = new stack; 
    r->inf = x; 
    r->next = h; 
    h = r; 
}

void reverse(stack*& h) { 
    stack* head1 = NULL; 
    while (h) { 
        push(head1, pop(h)); 
    }
    h = head1; 
}

int main() {
    stack* head = NULL;
    int n;

    cout << "n = "; 
    cin >> n;
    cout << "Enter the numbers: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(head, x);
    }

    cout << endl;
    return 0;
}