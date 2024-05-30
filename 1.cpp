#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
struct stack {
    char letter;
    stack* next;
};

void push(stack*& h, char x) { 
    stack* r = new stack; 
    r->letter = x; 
    r->next = h;
    h = r;
}

char pop(stack*& h) { 
    char letter = h->letter; 
    stack* r = h; 
    h = h->next; 
    delete r; 
    return letter; 
}



int main() {
    stack* head = nullptr;
    int n;

    cout << "Enter the number of letters: ";
    cin >> n;

    cout << "Enter the letters: ";

    char input;
    while (cin >> input && n > 0) {
        push(head, input);
        n--;
    }

    cout << " stack: ";
    stack* temp = head;
    while (temp) {
        cout << temp->letter << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}