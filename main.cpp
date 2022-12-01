#include <iostream>
#include "task1_lib.h"
using namespace std;

int randint(int start, int end) {
    // функция получает промежуток чисел и в рамках него генерирует случайные
    int num = start + rand() % (end - start + 1); // если не будет +1, то конец промежутка не будет включен
    return num;
}

int main() {
    srand(time(NULL));
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = randint(1, 100);
        cout << arr[i] << ", ";
    }
    cout << endl;

    /* int n, m;
    cout << "Insert n and m: "; cin >> n >> m;
    int **matrix;
    create_matrix(matrix, n, m);

    show_matrix(matrix, n, m);
    int max_matrix_element = find_max(matrix, n, m);
    cout << "Max element of matrix is: " << max_matrix_element << endl;

    delete_matrix(matrix, n);
    // cout << matrix[n-1][m-1] << endl;  //попытка обращения к очищенной памяти приводит к ошибке
    */
    return 0;
}
