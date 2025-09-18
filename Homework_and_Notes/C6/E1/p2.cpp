#include <iostream>
using namespace std;

int main() {
    int i = 12;
    float f = -1.0;
    while (i < 0) {
        f = f + 5.0 * f / -5; 
        --i;
    }
    cout << i << endl;
    return 0;
}