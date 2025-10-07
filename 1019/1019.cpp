#include <bits/stdc++.h>
using namespace std;
using uint64 = unsigned long long;
// 9    0   1 => [1]1
// 99   9   20 = 1+19 => 19 [10]10 + [1]9
// 999  189 300 = 20+280 => [100]100 + [10/1] 20*9
// 9999 189+300*9   1000+300*9+300
uint64 n;
uint64 arr[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(uint64 i = 1; i <= n; i++) {
        string num = to_string(i);
        for(int j : num) {
            arr[j-'0']++;
        }
    }

    for(uint64 i = 0; i < 10; i++)
        cout << arr[i] << ' ';
}