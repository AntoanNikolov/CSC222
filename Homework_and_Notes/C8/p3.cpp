#include <iostream>
using namespace std;

int f(int n) {
    ++n;
    return n++;
}

int f2(int &n) {
    ++n;
    return n++;
}

int main() {
    int x = 2, y, z;
    y = f(x);
    z = f2(y);
    cout << x + y + z << endl;
    return 0;
}

// x=2
// y=4
// z=5