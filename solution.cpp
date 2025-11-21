#include <iostream>
#include <string>

using namespace std;

struct Node {
    long long value;
    Node* next;
    Node(long long val): value(val), next(nullptr) {}
};

struct List {
    Node* first;  
    Node* current;  
    List() {
        first = new Node(100);
        current = first;
    }

    void append(long long X) {
        Node* newNode = new Node(X);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode;
    }

    void go(long long N) {
        while (current->next != nullptr && N > 0) {
            current = current->next;
            N--;
        }
    }

    long long get() {
        return current->value;
    }

    void reset() {
        current = first;
    }
};

int main() {
    List list;
    std::string cmd;
    while (cin >> cmd) {
        if (cmd == "append") {
            long long X; cin >> X;
            list.append(X);
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N;
            list.go(N);
            cout << "go " << N << " - OK" << '\n';
        } else if (cmd == "print") {
            cout << "print " << list.get() << " - OK" << '\n';
        } else if (cmd == "reset") {
            list.reset();
            cout << "reset - OK" << '\n';
        }
    }
    return 0;
}
