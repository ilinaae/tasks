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


bool isPrime(int num) { 
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void removePrimes(stack*& h) { 
    stack* result = NULL; 
    stack* h1 = NULL;
    while (h) {
        int current_int = pop(h); 
        if (!isPrime(current_int)) { 
            push(h1, current_int); 
        }
    }

    reverse(h1); 
    while (h1) {
        int temp_int = pop(h1);
        push(result, temp_int); 
    }
    h = result;
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
    removePrimes(head);
        while (head) {
        cout << pop(head) << " ";
    }

    cout << endl;
    return 0;
}