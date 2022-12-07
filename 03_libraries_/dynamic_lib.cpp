#include <iostream>

std::pair<int, int> min(int *array, int i, int j) {
    if (i >= j) {  // базовый случай
        return std::pair<int, int>(array[j], j);
    }
    int center = i + (j - i) / 2;
    std::pair<int, int> left = min(array, i, center);
    std::pair<int, int> right = min(array, center + 1, j);
    return (left.first < right.first) ? left : right;
}



