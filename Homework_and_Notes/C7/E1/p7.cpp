#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    s1 = "XYZ";
    s2 = s1.substr(1, 1) + s1.substr(2) + s1.substr();
    s1 = s2.substr(1, 1) + s2.substr(2) + s2.substr();
    cout << s1 << ' ' << s2 << endl;
    return 0;
}