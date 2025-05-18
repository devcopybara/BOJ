#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0, min = 100, a;

    for(int i = 0; i < 7; i++) {
        cin >> a;

        if(a & 1) {
            sum += a;
            if(min > a) min = a;
        }    
    }

    if(sum) {
        cout << sum << "\n" << min;
    }
    else {
        cout << -1;
    }
}