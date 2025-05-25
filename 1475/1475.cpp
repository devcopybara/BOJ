#include <bits/stdc++.h>
using namespace std;

int freq[10];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n) {
        freq[n % 10]++;
        n /= 10;
    }

    freq[6] = (freq[6] + freq[9] + 1) / 2;
    freq[9] = 0;

    int ans = 0;
    for(int i = 0; i < 9; i++) ans = max(ans, freq[i]);
    cout << ans;
}