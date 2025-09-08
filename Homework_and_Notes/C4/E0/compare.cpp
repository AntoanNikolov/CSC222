#include <iostream>
using namespace std;

void compare(int a, int b){

    int newnum=a-b;

    if (newnum<0) {
    cout << "Second number (" << b << ") is greater" << endl;
    } else if (newnum>0){
        cout << "First number (" << a << ") is greater" << endl;
    } else if (newnum == 0){
        cout << "Both numbers are equal." << endl;
    }    

}


int main()
{
    cout << "Enter your first number: \n";
    int first_choice;
    cin >> first_choice;

    cout << "Enter your Second number: \n";
    int second_choice;
    cin >> second_choice;

    compare(first_choice,second_choice);


    

    return 0;
}
