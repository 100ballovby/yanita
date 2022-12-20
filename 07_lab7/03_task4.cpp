#include <string>

using namespace std;

string to_romanian(int num) {
    string ans_num = "";
    string roman_numbers[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM",
                                "M"}; // создаём два массива в которых соответсвующие элементы
    int roman_in_arabian[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900,
                                1000};                  // являются числами в римской и арабской системах

    for (int i = 12; i >= 0; i--) {
        while (num - roman_in_arabian[i] >= 0) {             //  перевод и з арабской в римскую систему счисления
            ans_num += roman_numbers[i];
            num -= roman_in_arabian[i];
        }
    }

    return ans_num;
}