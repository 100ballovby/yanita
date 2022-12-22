#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int str_to_int(string str);
int getInt();
int size(string str);

int zapusk_menya() {  // это функция main
    int a;
    string ans = "";
    cout << "Type number: ";
    a = getInt();

    while (a) {
        if (a % 3 == 0) {
            ans = '3' + ans;
            a = (a - 1) / 3;
        } else {
            char ch = (a % 3) + '0';
            ans = ch + ans;
            a /= 3;
        }
    }
    cout << "Result: " << ans << endl;
    return 0;
}

int get_s_size(string str) {
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}

int str_to_int(string str) {
    long long int ans = 0, sign = 1, size = get_s_size(str);

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

int getInt() {
    string str;
    bool is_int;

    do {
        is_int = true;
        cin >> str;
        for (int i = 0; i < get_s_size(str); i++) {
            if (!isdigit(str[i])) {
                cout << "Error! It is not a number!\n";
                is_int = false;
                break;
            }
        }

    } while (!is_int);

    return str_to_int(str);
}
