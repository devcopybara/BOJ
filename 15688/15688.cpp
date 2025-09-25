#include <bits/stdc++.h>
using namespace std;

const int BIAS = 1000000;
const int MX = 2000001;
int n;
unsigned int freq[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        freq[tmp + BIAS]++;
    }

    for(int i = 0; i < MX; i++) {
        while(freq[i]--) {
            cout << i - BIAS << '\n';
        }
    }
}