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

string Sum(const string &num1, const string &num2) {
    string res;
    int size1 = num1.size();
    int size2 = num2.size();

    string short_str, long_str;
    if (size1 <= size2) {
        short_str = num1;
        long_str = num2;
    } else {
        short_str = num2;
        long_str = num1;
    }
    if (size1 != size2) {
        char sign1 = short_str[0];
        short_str[0] = '0';

        for (int i = short_str.size(); i < long_str.size() - 1; i++) {
            short_str = '0' + short_str;
        }
        short_str = sign1 + short_str;
    }
    char temp = '0';
    for (int i = short_str.size() - 1; i >= 0; i--) {
        if (short_str[i] == '0' && long_str[i] == '0') {
            res = temp + res;
            temp = '0';
        }
        if ((short_str[i] == '1' && long_str[i] == '0') || (short_str[i] == '0' && long_str[i] == '1')) {
            if (temp == '1') {
                res = '0' + res;
                temp = '1';
            } else {
                res = '1' + res;
                temp = '0';
            }
        }
        if (short_str[i] == '1' && long_str[i] == '1') {
            res = temp + res;
            temp = '1';
        }
    }
    return to_dop_code(res);
}