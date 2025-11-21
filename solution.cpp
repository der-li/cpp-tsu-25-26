#include <iostream>
#include <string>
using namespace std;

struct Node {
    long long data;   
    Node* next_node;  
    Node(long long val): data(val), next_node(nullptr) {}
};

struct List {
    Node* head;     
    Node* current_node;

    List() {
        head = new Node(100); 
        current_node = head;
    }

    void append(long long X) {
        Node* new_node = new Node(X);        
        new_node->next_node = current_node->next_node; 
        current_node->next_node = new_node;
        current_node = new_node;             
    }

    void go(long long steps) {
        while (steps > 0 && current_node->next_node != nullptr) {
            current_node = current_node->next_node;
            steps--;
        }
    }

    void print() {
        cout << current_node->data;
    }

    void reset() {
        current_node = head; 
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
            long long N; cin >> N; long long originalN = N;
            current_value = last_value; 
            list.go(N);
            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            cout << "print " << list.print() << " - OK" << '\n';
        } else if (cmd == "reset") {
            current_value = 100; 
            list.reset();
            cout << "reset - OK" << '\n';
        }
    }
    return 0;
}
