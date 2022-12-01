#include <iostream>
using namespace std;

int _randint(int start, int end) {
    // функция получает промежуток чисел и в рамках него генерирует случайные
    int num = start + rand() % (end - start + 1); // если не будет +1, то конец промежутка не будет включен
    return num;
}

// функция наполнения массива, передача массива по ссылке
void fill_array(int *arr, int size, int max, int min) {
    for (int i = 0; i < size; i++) {
        arr[i] = _randint(max, min);
    }
}

// функция, которая меняет элементы местами по ссылке
void my_swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


// пузырьковая сортировка
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        // последний i элемент всегда остается на месте
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // если число больше следующего
                int temp = arr[j];
                arr[j] = arr[j + 1];  // поменять их местами
                arr[j + 1] = temp;  // поменять их местами
            }
        }
    }
}
// пузырьковая сортировка END

// сортировка выбором
int find_min(int *arr, int start_pos, int size) {
    int min_pos = start_pos;
    for (int i = start_pos; i < size; i++) {
        if (arr[i] < arr[min_pos]) {
            min_pos = i;
        }
    }
    return min_pos;
}

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int min_pos = find_min(arr, i, size);
        int temp = arr[i];
        arr[i] = arr[min_pos];  // поменять их местами
        arr[min_pos] = temp;  // поменять их местами
    }
}
// сортировка выбором end

// сортировка вставками
void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
    }
}
// сортировка вставками END

// quick sort
int patrition(int *arr, int start, int pivot) {
    int i = start;
    while (i < pivot) {
        if (arr[i] > arr[pivot] && i == pivot - 1) {
            swap(arr[i], arr[pivot]);
            pivot--;
        } else if (arr[i] > arr[pivot]) {
            swap(arr[pivot - 1], arr[pivot]);
            swap(arr[i], arr[pivot]);
            pivot--;
        } else {
            i++;
        }
    }
    return pivot;
}

void quick_sort(int *arr, int first, int last) {
    if (first < last) {
        int pivot = patrition(arr, first, last);
        quick_sort(arr, first, pivot - 1);
        quick_sort(arr, pivot + 1, last);
    }
}
// quick sort END

// merge sort
void merge(int *array, int low, int mid, int high) {
    int i, j, k, nl, nr;
    //size of left and right sub-arrays
    nl = mid - low + 1;
    nr = high - mid;
    int larr[nl], rarr[nr];
    //fill left and right sub-arrays
    for (i = 0; i < nl; i++)
        larr[i] = array[low + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[mid + 1 + j];
    i = 0;
    j = 0;
    k = low;
    //marge temp arrays to real array
    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        } else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {       //extra element in left array
        array[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr) {     //extra element in right array
        array[k] = rarr[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int low, int high, int size) {
    /**4 шага:
     * 1. Найти серединку массива;
     * 2. Сортировать массив сначала до середины
     * 3. Сортировать массив с середины до конца
     * 4. Объединить отсортированные части **/
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid, size);
        merge_sort(arr, mid + 1, high, size);
        merge(arr, low, mid, high);
    }
}
// merge sort END

int binary_search(int *arr, int len, int key) {
    int low = 0;
    int high = len - 1;
    int mid = low + (high - low) / 2;

    while (key != arr[mid] && low != high) {  // пока не нашли число И пока границы не сомкнулись
        if (key > arr[mid]) {  // если искомое больше центрального
            low = mid + 1;  // сдвинуть левую границу массива вправо
        } else if (key < arr[mid]) {  // если искомое меньше центрального
            high = mid - 1;  // сдвинуть правую границу массива влево
        } else {
            break;
        }
        mid = low + (high - low) / 2;
    }
    if (key == arr[mid]) {
        return mid;
    } else {
        return -1;
    }
}

int exe() {
    srand(time(NULL));
    int len;
    cout << "Insert len of array: ";
    cin >> len;
    int *array = new int[len];
    fill_array(array, len, -100, 100);

    for (int i = 0; i < len; i++) {
        cout << array[i] << ", ";
    }
    cout << endl;
    // bubble_sort(array, len); <- пузырьковая сортировка
    //selection_sort(array, len);  <- сортировка выбором
    // insertion_sort(array, len);  <- быстрая сортировка
    // quick_sort(array, 0, len);
    merge_sort(array, 0, len - 1, len);
    for (int i = 0; i < len; i++) {
        cout << array[i] << ", ";
    }

    int key;
    cout << "Search for: ";
    cin >> key;
    cout << binary_search(array, len, key) << endl;
}
