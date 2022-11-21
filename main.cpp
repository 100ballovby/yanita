#include <iostream>
using namespace std;

int randint(int min, int max) {
    return rand() % (max - min) + min;
}


int main() {
    cout << "Суть задания: " << endl;
    cout << "Выполнила ... " << endl;
    bool repeat;
    cout << "Введите 0 для выхода из программы или 1, чтобы запустить." << endl;
    cin >> repeat;

    while (repeat) {
        // тут вызываем войды
        cout << "Введите 0 для выхода из программы или 1, чтобы запустить." << endl;
        cin >> repeat;
    }
}
