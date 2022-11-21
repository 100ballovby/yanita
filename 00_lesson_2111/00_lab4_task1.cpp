#include <iostream>
using namespace std;

int randint(int min, int max) {
    return rand() % (max - min) + min;
}

void task1_5() {
    srand(time(NULL));
    const int k = 8;
    int arr[k];

    for (int i = 0; i < k; i++) {
        arr[i] = randint(1, 20);
        cout << arr[i] << ", ";
    }
    cout << endl << "Уникальные: " << endl;

    for (int i = 0; i < k; i++) {  // перебираем все элементы массива
        bool flag = true;  // переключатель
        for (int j = 0; j < k; j++) {
            if (i - j != 0 && arr[i] == arr[j]) { // если мы смотрим не на одно и то же число и эти числа совпадают
                flag = false;
            }
        }
        if (flag) {
            cout << arr[i] << endl;
        }
    }
}

void task2_5() {
    srand(time(NULL));
    const int n = 4;
    const int m = 4;
    int matrix[n][m];
    cout << "Матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = randint(1, 100);
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    int summ = 0, mult = 1, l_i = -1;

    if (n == m) { // если матрица квадратная
        l_i = 1;  // находим побочку как столбцы - 1 - номер_строки
    } else {  // иначе
        l_i = 2; // находим побочку как столбцы - 2 - номер_строки
    }
    for (int i = 0; i < n; i++) {
        summ += matrix[i][i];  // главная диагональ - это одинаковый номер строки и столбца
        mult *= matrix[i][m - l_i - i];  // побочная диагональ - количество строк матрицы - номер строки - 2 (потому что последний индекс в строке: m - 1)
        cout << matrix[i][m - l_i - i] << endl;
    }
    cout << "Сумма элементов главной диагонали: " << summ << endl;
    cout << "Произведение элементов побочной диагонали: " << mult << endl;
}

void task3_5() {
    int n;
    cout << "Размер марицы: ";
    cin >> n;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        matrix[i][i] = randint(0, 2);
    }
    cout << "Матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }

    cout << "Разворот на 90" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > -1; j--) {
            cout << matrix[j][i] << ", ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = nullptr;  // удаляю строки
    }
    matrix = nullptr;  // удаляю саму матрицу

    /**
    for (int i = 0; i < n; i++) {
        delete [] matrix[i];  // удаляю строки
    }
    delete [] matrix;  // удаляю саму матрицу
     * **/
}
