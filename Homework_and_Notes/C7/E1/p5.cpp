#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "School";
    int i = s.compare("Grade") > 0;
    int j = s.compare("High") < 0;
    cout << i << j << endl;

    return 0;
}