#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void string_basics() {
    string s = "Hello!";
    cout << s.size() << endl;
    s += "go";
    cout << s << endl;
    cout << s.size() << endl;
}

void string_getline() {
    string phrase;
    string phrase2;
    cout << "Insert phrase: ";
    getline(cin, phrase);  // чтобы записать текст с пробелами в строку
    cout << phrase << endl;
    cout << "Insert phrase 2: ";
    getline(cin, phrase2);
    cout << phrase2 << endl;
}

void string_search() {
    string str;
    cout << "string: ";
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',') {
            str[i] = '.';
            str[i + 1] = '.';
        }
    }
    cout << str;
}

// ЗАДАЧА №6

int Fact(int N)
{
    if (N == 1)
        return 1;
    else
        return N * Fact(N - 1);
}

void lab6_task6() {
    string str;
    int x, y, p;
    getline(cin, str);
    sort(str.begin(), str.end());
    x = y = 0;
    p = 1;
    for (int i = y; str[i]; i++)
    {
        if (str[i] == str[i+1])
        {
            x++;
        }
        else
        {
            y = x;
            x++;
            if (x > 1)
                p *= Fact(x);
            x = 0;
        }
    }
    cout << Fact(str.size()) / p << endl;
}

// КОНЕЦ ЗАДАЧИ №6

// Задача №7
bool check_palindromes(string word) {
    int n = word.length();
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    if (n > 2) {  // если в слове более трех букв
        for (int i = 0; i < n; i++, n--) {
            if (word[i] != word[n - 1]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }

}
// КОНЕЦ ЗАДАЧИ №7

void suf_pref() {
    const int LETTERS_IN_ALPHABET = 26;
    string s1, s2;
    cout << "Enter prefix: ";
    cin >> s1;
    cout << "Enter suffix: ";
    cin >> s2;

    int length;
    cout << "Full length of the string: ";
    cin >> length;

    long double between = length - (s1.size() + s2.size());
    cout << "Number of possible variants is: " << endl;
    cout << pow(LETTERS_IN_ALPHABET, between) * 2;
}
