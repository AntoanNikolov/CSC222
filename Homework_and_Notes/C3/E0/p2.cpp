#include <iostream>
using namespace std;

void print_twice(char phil) {
    cout << phil << phil << endl;
}

int main() {
    char argument = 'b';
    print_twice(argument);
    int argument2 = 1;
    print_twice(argument2);
    float argument3 = 3.2;
    print_twice(argument3);

    return 0;
}
// ints and floats only returned an empty line
