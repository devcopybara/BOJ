#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[26];
char tmp[26];
char alpha[26];

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void func(int k) {
    if(k == n) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            tmp[i] = alpha[arr[i]];
            if(isVowel(tmp[i])) cnt++;
        }
        if(cnt >= 1 && n - cnt >= 2)
            cout << tmp << '\n';
        return;
    }
    int s = k == 0 ? 0 : arr[k - 1] + 1;
    for(int i = s; i < m; i++) {
        arr[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> alpha[i];
    sort(alpha, alpha + m);
    func(0);
}