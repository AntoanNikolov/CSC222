#include <iostream>
using namespace std;

int main() {
    int a, b = 2 | 5;
    for (a = 0; a < 3; a += 2)
        b++;
    cout << b << endl;
    return 0;
}
