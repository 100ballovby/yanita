#include "dynamic_lib.h"
#include <iostream>
using namespace std;


int task_executor() {
    srand(time(NULL));
    int len;
    cout << "insert len: ";
    cin >> len;
    int *arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 100 - 1 + 1;
        cout << arr[i] << "\n";
    }

    cout << endl;
    pair<int, int> a;
    a = min(arr, 0, len - 1);
    cout << "Index: " << a.second << endl;
    cout << "Element: " << arr[a.second] << endl;
    return 0;
}