#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        for(int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        for(int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}