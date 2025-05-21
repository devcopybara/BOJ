#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, maxVal, maxIdx = 1;

    cin >> maxVal;

    for(int i = 2; i <= 9; i++) {
        cin >> a;

        if(a > maxVal) maxVal = a, maxIdx = i;
    }

    cout << maxVal << "\n" << maxIdx;
}