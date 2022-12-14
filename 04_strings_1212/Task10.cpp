#include <iostream>
using namespace std;

int zapusk(){
    long long n, n1, n2, N1, N2;
    long long razmer = 100, k1 = 1, k2 = 1,  d = 0;
    cout << "Розетки: ";
    cin >> n;
    if (n % 2 == 0)	{
        n1 = n / 2;
        n2 = n - 1;
    }
    else{
        n1 = (n - 1) / 2;
        n2 = n;
    }
    auto *arr1 = new long long[razmer];
    auto *arr2 = new long long[razmer];
    auto *arr3 = new long long[razmer];
    N1 = n1;
    N2 = n2;
    while (N1 /= 10) {
        k1++;
    };
    while (N2 /= 10) {
        k2++;
    }
    for (int i = razmer - 1; i >= razmer - 1 - k1; i--){
        arr1[i] = n1 % 10;
        n1 /= 10;
    }
    cout << endl;
    for (long int i = razmer - 1; i >= razmer - 1 - k2; i--){
        arr2[i] = n2 % 10;
        n2 /= 10;
    }
    arr3[razmer - 1] = 1;
    for (long int i = razmer - 1; i >= razmer - 1 - k1; i--){
        for (long int j = razmer - 1; j >= razmer - 1 - k2; j--){
            arr3[j - d] += arr1[i] * arr2[j];
            arr3[j - d - 1] += arr3[j - d] / 10;
            arr3[j - d] %= 10;
        }
        d++;
    }
    arr3[0] = -1;
    arr3[1] = -1;
    for (long int i = 2; i < razmer; i++){
        if (arr3[i] == 0 && arr3[i - 1] == -1) {
            arr3[i] = -1;
        }

    }
    for (long int i = 0; i < razmer; i++){
        if (arr3[i] != -1) {
            cout << arr3[i];
        }
    }
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}