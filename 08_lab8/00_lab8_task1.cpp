#include <iostream>
#include <fstream>

using namespace std;

struct Bus {
    int number;
    int type;
    int place;
    int dateotpr[2];
    int datepr[2];
};

struct Bus Empty;

Bus *bus = 0; // массив структур с данными
int SIZE = 0; // размер массива

void Get(Bus *arr) { // добавляет в постоянный массив структур элемент и пользователь вводит данные
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

    printf("time pribytia: ");
    printf("hour (1-23): ");
    scanf("%d", &arr[SIZE - 1].datepr[0]);
    printf("minute (1-59): ");
    scanf("%d", &arr[SIZE - 1].datepr[1]);
}

void task1(Bus *arr) {
    Get(arr);
}

void task2(Bus *arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("number:%d", arr[i].number);
        printf("\n");

        printf("type (1 - big/2 - medium/3 - small):%d", arr[i].type);
        printf("\n");

        printf("place (1 - bobruisk, 2 - borisov, 3 - gomel, 4 - mogilev):%d", arr[i].place);
        printf("\n");

        printf("time plenipotentiary:%d", arr[i].dateotpr[0]);
        printf("%s", ".");
        printf("%d", arr[i].dateotpr[1]);
        printf("\n");


        printf("time arriving:%d", arr[i].datepr[0]);
        printf("%s", ".");
        printf("%d", arr[i].datepr[1]);
        printf("\n");
    }
}

void task4(Bus *arr) {
    printf("1 - search for type\n2 - search for place\n3 - search for depart time\n4 - search for income time");
    int ans;
    scanf("%d", ans);
    if (ans == 1) {
        printf("type (1 - big/2 - medium/3 - small): ");
        int bus_type;
        scanf("%d", bus_type);
        for (int i = 0; i < SIZE; i++) {
            if (arr[i].type == bus_type) {
                printf("number:%d", arr[i].number);
                printf("\n");

                printf("type (1 - big/2 - medium/3 - small):%d", arr[i].type);
                printf("\n");

                printf("place (1 - bobruisk, 2 - borisov, 3 - gomel, 4 - mogilev):%d", arr[i].place);
                printf("\n");

                printf("time plenipotentiary:%d", arr[i].dateotpr[0]);
                printf("%s", ".");
                printf("%d", arr[i].dateotpr[1]);
                printf("\n");

                printf("time arriving:%d", arr[i].datepr[0]);
                printf("%s", ".");
                printf("%d", arr[i].datepr[1]);
                printf("\n");
            }
        }
    } else if (ans == 2) {
        printf("place (1 - bobruisk, 2 - borisov, 3 - gomel, 4 - mogilev): ");
        int place_dep;
        scanf("%d", place_dep);
        for (int i = 0; i < SIZE; i++) {
            if (arr[i].place == place_dep) {
                printf("number:%d", arr[i].number);
                printf("\n");

                printf("type (1 - big/2 - medium/3 - small):%d", arr[i].type);
                printf("\n");

                printf("place (1 - bobruisk, 2 - borisov, 3 - gomel, 4 - mogilev):%d", arr[i].place);
                printf("\n");

                printf("time plenipotentiary:%d", arr[i].dateotpr[0]);
                printf("%s", ".");
                printf("%d", arr[i].dateotpr[1]);
                printf("\n");

                printf("time arriving:%d", arr[i].datepr[0]);
                printf("%s", ".");
                printf("%d", arr[i].datepr[1]);
                printf("\n");
            }
        }
    } else if (ans == 3) {
        int time_dep;
        printf("hour (1-23): ");
        scanf("%d", time_dep);
        for (int i = 0; i < SIZE; i++) {
            if (arr[i].dateotpr[0] == time_dep) {
                printf("number:%d", arr[i].number);
                printf("\n");

                printf("type (1 - big/2 - medium/3 - small):%d", arr[i].type);
                printf("\n");

                printf("place (1 - bobruisk, 2 - borisov, 3 - gomel, 4 - mogilev):%d", arr[i].place);
                printf("\n");

                printf("time plenipotentiary:%d", arr[i].dateotpr[0]);
                printf("%s", ".");
                printf("%d", arr[i].dateotpr[1]);
                printf("\n");

                printf("time arriving:%d", arr[i].datepr[0]);
                printf("%s", ".");
                printf("%d", arr[i].datepr[1]);
                printf("\n");
            }
        }
    } else if (ans == 4) {
        int time_inc;
        printf("hour (1-23): ");
        scanf("%d", time_inc);
        for (int i = 0; i < SIZE; i++) {
            if (arr[i].datepr[0] == time_inc) {
                printf("number: ", arr[i].number);
                printf("\n");

                printf("type (1 - big/2 - medium/3 - small):%d", arr[i].type);
                printf("\n");

                printf("place (1 - bobruisk, 2 - borisov, 3 - gomel, 4 - mogilev):%d", arr[i].place);
                printf("\n");

                printf("time plenipotentiary:%d", arr[i].dateotpr[0]);
                printf("%s", ".");
                printf("%d", arr[i].dateotpr[1]);
                printf("\n");

                printf("time arriving:%d", arr[i].datepr[0]);
                printf("%s", ".");
                printf("%d", arr[i].datepr[1]);
                printf("\n");
            }
        }
    }
}

void task5(Bus *arr) {
    int d;        //номер записи, которую нужно удалить
    printf("Введите номер записи, которую необходимо удалить:\nЕсли необходимо удалить все записи,нажмите '99': ");
    cin >> d;
    if (d != 99) {
        for (int i = (d - 1); i < SIZE; i++) //цикл для удаления заданной записи, начинаем цикл с удаляемой записи
            arr[i] = arr[i + 1]; //замещаем текущую запись следующей за ней
        SIZE -= 1; //уменяьшаем счетчик полных записей на 1
    }
    if (d == 99) {
        for (int i = 0; i < SIZE; i++)//цикл по все записям от первой до 30-ой
            arr[i] = Empty; //замещаем каждую структуру в массиве пустотой
    }
}

void task6(Bus *arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j].type < arr[j + 1].type) {  // если число больше следующего
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int menu() {
    printf("1 - add bus\n2 - show shedule\n3 - add bus\n4 - search\n5 - delete\n6 - sort");
    int ans = 0;
    scanf("%d", &ans);
    return ans;
}

int menya_nado_zapuskat() {
    int work;
    auto *buses = new Bus;
    printf("1 - for start, 0 for finish:");
    scanf("%d", &work);
    int answer;
    while (work) {
        answer = menu();

        switch (answer) {
            case 1:
                task1(buses);
                break;
            case 2:
                task2(buses);
                break;
            case 3:
                task1(buses);
                break;
            case 4:
                task4(buses);
                break;
            case 5:
                task5(buses);
                break;
            case 6:
                task6(buses);
                break;
        }

        printf("1 - continue, 0 - for finish:");
        scanf("%d", &work);
    }
    return 0;
}