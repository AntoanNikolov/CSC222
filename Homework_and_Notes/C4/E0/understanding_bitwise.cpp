#include <iostream>
using namespace std;

void print_byte_bits(unsigned char byte) {
    for (int mask = 128; mask > 0; mask >>= 1) {
        cout << (mask & byte ? '1' : '0');
        if (mask == 16) cout << ' ';
    }
    cout << endl;
}

void show_bitwise_operation(char byte1, char op, char byte2=0) {
    if (op == '~') {
        cout << "Showing ~" << int(byte1) << ':' << endl; 
        print_byte_bits(byte1);
        cout << "---------" << endl;
        print_byte_bits(~byte1);
        cout << endl;
        return;
    }
    if (op == 'l' || op == 'r') {
        cout << "Showing " << int(byte1) << ' ';
        cout << (op == 'l' ? "<< " : ">> ") << int(byte2) << ':' << endl;
        print_byte_bits(byte1);
        cout << "---------" << endl;
        if (op == 'l') print_byte_bits(byte1 << byte2);
        else print_byte_bits(byte1 >> byte2);
        cout << endl;
        return;
    }
    cout << "Showing " << int(byte1) << ' ' << op << ' ' << int(byte2);
    cout << ':' << endl; 
    print_byte_bits(byte1);
    print_byte_bits(byte2);
    cout << "---------" << endl;
    if (op == '&') print_byte_bits(byte1 & byte2);
    else if (op == '|') print_byte_bits(byte1 | byte2);
    else if (op == '^') print_byte_bits(byte1 ^ byte2);
    else if (op == 'l') print_byte_bits(byte1 << byte2);
    else if (op == 'r') print_byte_bits(byte1 >> byte2);
    cout << endl;
}

int main() {
    show_bitwise_operation(42, '&', 11);
    show_bitwise_operation(42, '|', 11);
    show_bitwise_operation(42, '^', 11);
    show_bitwise_operation(42, '~');
    show_bitwise_operation(42, 'l', 2);
    show_bitwise_operation(42, 'r', 2);
    return 0;
}
