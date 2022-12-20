#include <iostream>
#include <string>
using namespace std;


int add(int n1, int n2) {
    int res = 0, c = 0;
    res = n1 ^ n2;
    c = (n1 & n2) << 1;
    while (c) {
        int temp = res;
        res ^= c;
        c = (temp & c) << 1;
    }
    return res;
}

int negative(int &n) {
    n = ~n;
    return add(n, 1);
}

int substraction(int a, int b) {
    return add(a, negative(b));
}

void task6(int n) {
    int res, arr[3] = {5, 73, 151};
    for (int i = 0; i < 3; i++) {
        res = abs(n);

        while (res > 0) {
            res = substraction(res, arr[i]);
        }

        if (res == 0) {
            cout << "Divided by " << arr[i] << endl;
        } else {
            cout << "Not divided by " << arr[i] << endl;
        }
    }
}