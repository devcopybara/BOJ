#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c[21];
    for(int i = 1; i <= 20; i++) c[i] = i;

    for(int i = 0; i < 10; i++) {
        cin >> a >> b;

        for(int j = a, k = b; j < k; j++, k--) {
            swap(c[j], c[k]);
        }
    }

    for(int i = 1; i <= 20; i++) cout << c[i] << " ";
}