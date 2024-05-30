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

bool isConsonant(char letter) {
    letter = tolower(letter);
    return isalpha(letter) && strchr("bcdfghjklmnpqrstvwxyz", letter) != nullptr;
}

void insert_znak(stack*& h) {
    stack* result = NULL;
    stack* tempStack = NULL;

    while (h) {
        push(result, pop(h));
    }
    bool consonant_f = false;
    while (result) {
        char currentLetter = pop(result);
        if (!consonant_f && isConsonant(currentLetter)) {
            push(tempStack, currentLetter);
            push(tempStack, '!');
            consonant_f = true;
        }
        else {
            push(tempStack, currentLetter);
        }
    }
    while (tempStack) {
        push(h, pop(tempStack));
    }
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
    insert_znack(head);
    cout << " stack: ";
    stack* temp = head;
    while (temp) {
        cout << temp->letter << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}