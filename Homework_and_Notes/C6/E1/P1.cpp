#include <iostream>
using namespace std;

int main() {
    int i = 12;
    float f = 1000.0;
    while (i > 0) {
        i -= 3;
        f /= 10;
    }
    cout << f << endl;
    return 0;
}