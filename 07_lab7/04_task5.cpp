#include <iostream>
#include <string>
using namespace std;

void task5() {
    int t, num;
    cout << "Count of tests:";
    cin >> t;

    while (t--) {
        cout << "Insert n: ";
        cin >> num;
        cout << (num + 1) / 10 << endl;
    }
}