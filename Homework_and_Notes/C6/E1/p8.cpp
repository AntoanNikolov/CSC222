#include <iostream>
using namespace std;

int main() {
    float v = 500.0;
    do {
        v /= 5;
        cout << '*';
    } while (v > 1.0);
    cout << endl;

    return 0;
}