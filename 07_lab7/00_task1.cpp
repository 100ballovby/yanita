#include <iostream>
#include <string>
using namespace std;

string to_dop_code(string code_of_number) {
    int length = code_of_number.size();

    if (code_of_number[0] == '1') {                     // Перевод числа в дополнительный код
        for (int i = 1; i < length; i++) {
            if (code_of_number[i] == '1') {
                code_of_number[i] = '0';
            } else {
                code_of_number[i] = '1';
            }
        }
        for (int i = length - 1; i > 0; i--) {
            if (code_of_number[i] == '1') {
                code_of_number[i] = '0';
            } else {
                code_of_number[i] = '1';
                break;
            }
        }
    }

     return code_of_number;
}