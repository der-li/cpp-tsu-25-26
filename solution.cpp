#include <iostream>
#include <string>
using namespace std;

struct Node {
    long long data;    
    Node* next_node;    
    Node(long long val) : data(val), next_node(nullptr) {}
};

struct List {
    Node* head;      
    Node* current;       

    List() {
        head = new Node(100); 
        current = head;
    }

    void append(long long X) {
        Node* new_node = new Node(X);       
        new_node->next_node = current->next_node; 
        current->next_node = new_node;
        current = new_node;             
    }

    void go(long long N) {
        while (N > 0 && current->next_node != nullptr) {
            current = current->next_node;
            N--;
        }
    }

    void print() {
        cout << current->data; 
    }

    void reset() {
        current = head;
    }
};

int main() {
    List list; 
    string cmd;

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
            cout << "print ";
            list.print();
            cout << " - OK" << '\n';
        } else if (cmd == "reset") {
            list.reset();
            cout << "reset - OK" << '\n';
        }
    }
    return 0;
}
