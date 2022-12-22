#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long int string_to_integer(string str);
int get_size(string str);
string convert_to_binary(const string &number);
string binary_counter(const int &end);
int get_num();

int zapuskator() { // это функция main
    cout << "Count double ten numbers\nType number of double ten number:";
    int test;
    test = get_num();

    cout << binary_counter(test) << endl;
    return 0;
}

int get_size(string str) {
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}

long long int string_to_int(string str) {
    long long int ans = 0, sign = 1, size = get_size(str);

    if (str[0] == '-') {
        sign = -1;
    }
    for (int i = 0; i < size; i++) {
        if (str[i] != '-') {
            ans += ((str[i]) - '0') * pow(10, size - 1 - i);
        }
    }
    return sign * ans;
}

string convert_to_binary(const string &number) {
    long long int tmp = string_to_int(number);
    string ans;

    while (tmp != 0) {
        ans = char((tmp % 2) + 48) + ans;
        tmp /= 2;
    }
    return ans;
}

string binary_counter(const int &end) {
    string ans = "0", tmp;
    int counter = 0, i = 0;
    while (i < end) {  // пока мы не найдем нужный нам номер двудесятичного числа
        if (ans[get_size(ans) - 1] == '0') {
            ans[get_size(ans) - 1] = '1';
        } else {
            counter = 0;
            while (counter < get_size(ans)) {
                if (ans[get_size(ans) - 1 - counter] == '0') {
                    ans[get_size(ans) - 1 - counter] = '1';

                    for (int k = get_size(ans) - counter; k < get_size(ans); k++) {
                        ans[k] = '0';
                    }
                    break;
                }
                counter++;
            }
            if (counter == get_size(ans)) {
                for (int j = 0; j < get_size(ans); j++) {
                    ans[j] = '0';
                }
                ans = '1' + ans;
            }
        }
        tmp = convert_to_binary(ans); // преобразуем в двоичное
        tmp = tmp.substr(get_size(tmp) - get_size(ans), get_size(tmp));

        if (tmp == ans) {
            i++;
        }
    }
    return ans;
}

int get_num() {
    string str;
    bool is_int;

    do {
        is_int = true;
        cin >> str;
        for (int i = 0; i < get_size(str); i++) {
            if (!isnumber(str[i])) {
                cout << "Error! It is not a number!\n";
                is_int = false;
                break;
            }
        }

    } while (!is_int);

    return string_to_int(str);
}
