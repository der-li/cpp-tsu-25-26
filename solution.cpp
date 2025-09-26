#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n
    long long totalSum = 0;
    for (int i = 0; i < n; ++i) {
        int k, p;
        cin >> k >> p;
        totalSum += static_cast<long long>(k) * p;
    }
    cout << totalSum << endl;
    return 0;
}
