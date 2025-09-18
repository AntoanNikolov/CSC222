#include <iostream>
using namespace std;

int main() {
    int n = 0, m = 7 ^ 5;
    while (n == 0) {
        if (m > 1)
            n = m;
        ++m;
    }
    cout << n << m << endl;
    return 0;
}