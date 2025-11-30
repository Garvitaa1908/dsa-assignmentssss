#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.empty() || q.size() % 2 != 0) {
        cout << "Queue must have even number of elements!" << endl;
        return;
    }

    int halfSize = q.size() / 2;
    stack<int> s;
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter number of elements (even number): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Please enter an even number of elements!" << endl;
        return 0;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    cout << "\nOriginal Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

