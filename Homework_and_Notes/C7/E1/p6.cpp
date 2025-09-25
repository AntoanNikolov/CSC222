#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Abc", s2 = "A";
    int i = s1.compare(s2) < 0;
    int j = s1.length() > s2.length();
    cout << i << j << endl;
    return 0;
}