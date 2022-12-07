#include "task1_lib.h"
#include <iostream>

void create_matrix(int **&matrix, int n, int m) {
    /** Передаем матрицу как указатель на адрес ее ячеек.
     * Когда функция будет запущена, она найдет матрицу по адресу,
     * наполнит ее числами и сохранит результат в тех ячейках,
     * который указаны как параметр функции. **/

    matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
           matrix[i][j] = i * j;
        }
    }
}

void show_matrix(int **matrix, int n, int m) {
    /** Выводим элементы матрицы **/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int find_max(int **matrix, int n, int m) {
    /** Находим наибольший элемент матрицы **/
    int max_el = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max_el) {
                max_el = matrix[i][j];
            }
        }
    }
    return max_el;
}

void delete_matrix(int **&matrix, int n) {
    /** Очищаем память от динамической матрицы **/
    for (int i = 0; i < n; i++) {
        matrix[i] = nullptr;
    }
    matrix = nullptr;
}

