

#include <iostream>
using namespace std;

int main() {
    int n = 2;
    switch (n << n) {
        case 8: n++;
        case 4: n++;
        case 2: break;
        case 1: n--;
    }
    cout << n << endl; 
    return 0;
}

