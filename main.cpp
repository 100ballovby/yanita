#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Bus {
    int number;
    int type;
    int place;
    int dateotpr[2];
};

struct Bus Empty;
Bus *bus = 0; // массив структур с данными

int SIZE = 0; // размер массива

void fill_array(Bus *arr) { // добавляет в постоянный массив структур элемент и пользователь вводит данные
    SIZE++; // наш размер увеличивается на 1, т.к. мы добавляем элемент в массив
    if (SIZE == 1) { // если это первый элемент, нам ничего копировать не нужно, и мы просто выделяем память под новую структуру
        bus = new Bus[SIZE];
    } else { // если это не первый элемент, нужно скопировать уже имеющиеся данные и выделить память под новую структуру
        // реализация C++ vector без vector
        Bus *temp_bus = new Bus[SIZE]; // создаем временный массив структур нового размера (как у вектора)
        for (int i = 0; i < SIZE - 1; ++i) {
            temp_bus[i] = bus[i]; // копируем в него данные из постоянного массива структур старого размера
        }
        delete[] bus; // удаляем постоянный массив структур старого размера
        bus = temp_bus; // получаем постоянный массив структур нового размера
    }
    printf("\n");
    printf("number (chislo): ");
    scanf("%d", &arr[SIZE - 1].number);

    printf("type (1 - big/2 - medium/3 - small): ");
    scanf("%d", &arr[SIZE - 1].type);

    printf("place (1 - bobruisk, 2 - borisov, 3 - gomel, 4 - mogilev): ");
    scanf("%d", &arr[SIZE - 1].place);

    printf("time otpravlenia: ");
    printf("hour (1-23): ");
    scanf("%d", &arr[SIZE - 1].dateotpr[0]);
    printf("minute (1-59): ");
    scanf("%d", &arr[SIZE - 1].dateotpr[1]);
    printf("\n");
}

void show_database() {
    cout << "===================================================================" << endl;
    string getcontent;
    ifstream openfile ("../database.txt");
    if(openfile.is_open())
    {
        while(getline(openfile, getcontent))
        {
            cout << getcontent << endl;
        }
    }
    cout << "===================================================================" << endl;
}

void sorting(Bus *arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j].dateotpr > arr[j + 1].dateotpr) {  // если число больше следующего
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void save_data(Bus *arr) { // сохраняет данные в файл базы данных
    ofstream data("../database.txt"); // открываем файл базы данных для записи данных в него
    for (int i = 0; i < SIZE; ++i) // цикл записи данных в файл базы данных
    {
        if (i != SIZE - 1) // если это не последняя струтура в постоянном массиве структур, то...
        {
            data << arr[i].number << endl;
            data << arr[i].type << endl;
            data << arr[i].place << endl;
            data << arr[i].dateotpr[0] << " " << arr[i].dateotpr[1] << endl;
        } else // а если это последняя структура в постоянном массиве структур, то...
        {
            data << arr[i].number << endl;
            data << arr[i].type << endl;
            data << arr[i].place << endl;
            data << arr[i].dateotpr[0] << " " << arr[i].dateotpr[1]; /* здесь не будет переноса строки, т.к. в будущем нам надо будет загружать данные
				из файла базы данных в программу, и при считывании он будет считывать пустую строку, а нам этого не надо*/
        }
    }
    data.close(); // закрываем файл базы данных
    cout << "Your data has been saved" << endl;
}

int menu() {
    printf("1 - add bus\n2 - show shedule\n3 - save data");
    int ans = 0;
    scanf("%d", &ans);
    return ans;
}

int main() {
    int work;
    auto *buses = new Bus;
    printf("1 - for start, 0 for finish:");
    scanf("%d", &work);
    int answer;
    while (work) {
        answer = menu();

        switch (answer) {
            case 1:
                fill_array(buses);
                break;
            case 2:
                show_database();
                break;
            case 3:
                sorting(buses);
                save_data(buses);
                break;
        }

        printf("1 - continue, 0 - for finish:");
        scanf("%d", &work);
    }
    return 0;
}