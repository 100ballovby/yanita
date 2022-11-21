#include <iostream>
using namespace std;

int randint(int min, int max);



int randint(int min, int max) {
    return rand() % (max - min) + min;
}

int check_int() {
    while (true) {
        cout << "Введите 0 для выхода из программы или 1, чтобы запустить.";
        int a;
        cin >> a;

        if (cin.fail()) {  // если извлечение не удалось
            cin.clear();  // возвращаем cin в нормальный режим
            cin.ignore(32767, '\n');  // удаляем предыдущий ввод и символ новой строки из буфера
        } else {
            if (a == 1 || a == 0) {
                return a;
            }
        }
    }
}


int main() {
    cout << "Суть задания: " << endl;
    cout << "Выполнила ... " << endl;
    bool repeat;
    repeat = check_int();

    while (repeat) {
        // тут вызываем войды
        repeat = check_int();
    }
}
