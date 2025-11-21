#include <iostream>
#include <string>
using namespace std;

struct List {
    long long value;      
    List* next_node;   
    List* current_node;     

    List(long long v) : value(v), next_node(nullptr), current_node(this) {}

    void append(long long new_value) {
        List* new_node = new List(new_value);
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

    long long get_value() {
        return current_node->value;
    }

    void reset() {
        current_node = this;
    }
};

int main() {
    List lst(100);
    string command;
    while (cin >> command) {
        if (command == "append") {
            long long X; cin >> X;
            lst.append(X);
            cout << "append " << X << " - OK\n";
        } else if (command == "go") {
            long long N; cin >> N;
            lst.go(N);
            cout << "go " << N << " - OK\n";
        } else if (command == "print") {
            cout << "print " << lst.get_value() << " - OK\n";
        } else if (command == "reset") {
            lst.reset();
            cout << "reset - OK\n";
        }
    }
    return 0;
}
