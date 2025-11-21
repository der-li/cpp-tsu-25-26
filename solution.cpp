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
        Node* new_node = new Node(X);
        new_node->next = current->next;
        current->next = new_node;
        current = new_node; 
    }

    void go(long long N) {
        while (N > 0 && current->next != nullptr) {
            current = current->next;
            N--;
        }
    }

    void print() {
        cout << current->value;
    }

    void reset() {
        current = first;
    }
};

int main() {
    List list;

    long long last_value = 100; 
    long long current_value = 100; 
    string cmd;

    while (cin >> cmd) {
        if (cmd == "append") {
            long long X; cin >> X;
            list.append(X);
            last_value = current_value = X; 
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N;
            current_value = last_value; 
            list.go(N);
            cout << "go " << N << " - OK" << '\n';
        } else if (cmd == "print") {
            cout << "print ";
            list.print();
            cout << " - OK" << '\n';
        } else if (cmd == "reset") {
            list.reset();
            current_value = 100; 
            cout << "reset - OK" << '\n';
        }
    }

    return 0;
}
