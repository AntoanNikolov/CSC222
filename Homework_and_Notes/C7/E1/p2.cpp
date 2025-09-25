#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "ABC";
    s.append(s.substr(2)).push_back(s[s.length() - 3]);
    cout << s << endl;
    return 0;
}
