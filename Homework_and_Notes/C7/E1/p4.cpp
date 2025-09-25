#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "ACC";
    string s2 = "GCTAA";
    string s;
    s1.swap(s2);
    s2.swap(s);
    s.swap(s2);
    cout << s1 << endl;
    return 0;
}