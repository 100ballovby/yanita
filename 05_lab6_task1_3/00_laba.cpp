#include <iostream>
#include <string>
using namespace std;

void char_type() {
    char a;
    cout << "Insert keyboard symbol: ";
    cin >> a;
    cout << "Symbol is: " << a << endl;
    cout << "Symbol \nnumber \tis: " << (int)a << endl;
}

void cin_char() {
    char arr[5] = {'h', 'e', 'l', 'l', 'o'};
    char arr1[10];
    cout << arr << endl;
    cout << arr1 << endl;
}

void getchar_method() {
    int symbol, i = 0;
    char arr[20];
    cout << "Insert characters, press Enter to stop" << endl;

    do {
        symbol = getchar();
        arr[i] = symbol;
        i++;
    } while (symbol != '\n');

    cout << arr << endl;
}

void lab6_task1() {
    char st[80];
    int symbol, i = 0;
    cout << "Enter string, cancel with Enter: ";
    do {
        symbol = getchar();
        st[i] = symbol;
        i++;
    } while (symbol != '\n');

    int count_one = 0;
    int countn = 0;
    int counterror = 0;
    for (int i = 0; i < 80; i++) {
        if (st[i] == '1') {
            count_one++;
        } else if (st[i] == '0') {
            if (count_one % 2 && count_one > 1) {  // если одиночные единички нужны, уберите && и до конца
                countn += count_one;
            }
            count_one = 0;
        } else {
            counterror++;
        }
    }


    if (count_one % 2) {
        countn += count_one;
    }
    if (counterror) {
        cout << "There is restricted symbols in string!" << endl;
    }
    cout << countn << endl;
}

void lab6_task2() {
    char str[80] = "subs, isub, csub.";
    char s1[80];
    int j = 0;
    for (int i = 0; str[i]; i++) {
        s1[i + j] = str[i];
        if (str[i] == ',') {
            s1[i + j + 1] = '!';
            j++;
        }
    }
    cout << s1 << endl;
}

void lab6_task3() {
    char str[4][20] {
            "Hello, c++", "Jon Doe",
            "Jayson Born", "Sim City update"
    };
    int arr_len[4], middle = 0, sum = 0;

    for (int i = 0; i < 4; i++) {
        int len = 0;
        for (int j = 0; j < 20; j++) {
            if (str[i][j] != '\u0000') {
                len++;
            }
        }
        arr_len[i] = len;
    }

    for (auto k : arr_len) {
        sum += k;
    }
    middle = sum / 4;
    cout << "Mid len: " << middle << endl;

    for (int i = 0; i < 4; i++) {
        if (arr_len[i] < middle) {
            int lst_i = arr_len[i];
            while (lst_i < middle) {
                str[i][lst_i] += ' ';
                lst_i++;
            }
        }
        if (arr_len[i] > middle) {
            int lst_i = arr_len[i];
            while (lst_i >= middle) {
                str[i][lst_i] = '\u0000';
                lst_i--;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << "'" << str[i] << "'" << endl;
    }
}

void create_char_array() {
    int n, m;
    cout << "n: "; cin >> n;
    cout << "m: "; cin >> m;
    cin.get();
    char **str_arr;
    str_arr = new char *[n];
    for (int i = 0; i < n; i++) {
        auto s = new char[m];
        int symbol, j = 0;
        cout << "Enter string, cancel with Enter: ";
        do {
            symbol = getchar();
            s[j] = symbol;
            j++;
        } while (symbol != '\n');
        str_arr[i] = s;
    }

    for (int i = 0; i < n; i++) {
        cout << str_arr[i];
    }
}