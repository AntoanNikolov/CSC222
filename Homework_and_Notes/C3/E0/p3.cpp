// 1. If you call a function and never do anything with the result, it simply gets discarded
// 2. Compilation error:
// #include <iostream>
// using namespace std;

// void print_twice(char phil) {
//     cout << phil << phil << endl;
// }

// int main() {
//     char argument = 'b';
//     print_twice(argument);
//     int argument2 = 1;
//     print_twice(argument2);
//     float argument3 = 3.2;
//     print_twice(argument3);
//     int result = print_twice('a') + 7;


//     return 0;
// }
// 3. Yes, we can write functions that return results like so:

#include <iostream>
using namespace std;

int add_together(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    int num1 = 5;
    int num2 = 6;
    int result = add_together(num1,num2);
    cout << "And the result is... " << result << endl;

    return 0;
}