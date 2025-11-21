#include <iostream>
#include <string>
using namespace std;

struct List {
    long long value;   
    List* next;       
    List* current;        

    List(long long v) : value(v), next(nullptr), current(this) {}

    void append(long long x) {
        List* newNode = new List(x);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode;
    }

    void go(long long steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
    }

    long long getValue() {
        return current->value;
    }

    void reset() {
        current = this;
    }
};

int main() {
    List list(100); 

    string command;
    while (cin >> command) {
        if (command == "append") {
            long long X; cin >> X;
            list.append(X); 
            cout << "append " << X << " - OK\n";
        } else if (command == "go") {
            long long N; cin >> N;
            list.go(N);
            cout << "go " << N << " - OK\n";
        } else if (command == "print") {
            cout << "print " << list.getValue() << " - OK\n";
        } else if (command == "reset") {
            list.reset(); 
            cout << "reset - OK\n";
        }
    }
    return 0;
}
