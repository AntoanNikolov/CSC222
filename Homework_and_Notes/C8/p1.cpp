#include <iostream>
using namespace std;

struct A
{
    int a; // 1, 5
    float b; // 2, 6
};

struct B
{
    int b; // 3, 7
    float a; // 4, 8
};

struct C
{
    A a; // 
    B b; // 
};

int main() {
    C c1 = {1, 2, 3, 4}, c2 = {5, 6, 7, 8};
    cout << c1.b.a + c2.a.b << endl; // 4+6==10

    return 0;
} 