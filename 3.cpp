#include <iostream>
using namespace std;

struct queue {
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x) {
	queue* r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		h = t = r;
	}
	else {
		t->next = r;
		t = r;
	}
}

int pop(queue*& h, queue*& t) {
	int i = h->inf;
	queue* r = h;
	h = h->next;
	if (!h) t = NULL;
	delete r;
	return i;
}


int findMax(queue * h)
{
    int max = 0;
    queue* temp = h;
    while (temp) 
    {
        if (temp->inf > max)
        {
            max = temp->inf;
        }
        temp = temp->next;
    }
    return max; 
}

int main() {
	queue* h = NULL, * t = NULL;
	int n, x;

	cout << "n = ";
	cin >> n;

	cout << "elements:\n";
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, t, x);
	}


	cout << "queue:\n";
	while (h) {
		cout << pop(h, t) << " ";
	}

	return 0;
}