#include <iostream>
using namespace std;

char f(char n) {
    int count = 0;
    for (n = 4 * n; n > 0; n >>= 2)
        count++;
    return count;
}

void f(int n) {
    for (char count = f(char(n)); count > 0; count--)
        cout << '*';
}

int main() {
    char x = 3;
    f(3);
    cout << endl;
    return 0;
}