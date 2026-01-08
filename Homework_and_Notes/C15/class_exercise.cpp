#include <string>
#include <iostream>
using namespace std;

string remove_char(string s, char c) {
    if (s.empty()) {
        return "";
    }
    if (s[0] == c) {
        return remove_char(s.substr(1), c);
    }
    return s[0] + remove_char(s.substr(1), c);
}

int main() {
    cout << remove_char("Mississippi", 'i') << endl;
    return 0;
}
