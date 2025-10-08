#include <bits/stdc++.h>
using namespace std;
using uint64 = unsigned long long;
// 9    0   1 => [1]1
// 99   9   20 = 1+19 => 19 [10]10 + [1]9
// 999  189 300 = 20+280 => [100]100 + [10/1] 20*9
// 9999 189+300*9   300+300*9+1000
uint64 n;
uint64 arr[10];
uint64 digit[11][2];

void solve(int n) {
    int len = to_string(n).size();
    int exp = 1; while(--len) exp *= 10;



    solve(n % exp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    digit[1][1] = 1;
    for(int i = 2; i <= 10; i++) {

    }

    solve(n);

    for(uint64 i = 0; i < 10; i++)
        cout << arr[i] << ' ';
}