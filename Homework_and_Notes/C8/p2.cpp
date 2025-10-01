#include <iostream>
using namespace std;

struct A
{
    int a; // 2
    char b; // 'A'
};

struct B
{
    char a; // 'C'
    int b; // 1
};

int main() {
    A a = {2, 'A'};
    B b = {'C', 1};
    cout << b.a - a.b - b.b + a.a << endl; // 'C' - 'A' - 1 + 2

    return 0;
}