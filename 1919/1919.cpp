#include <bits/stdc++.h>
using namespace std;

int afreq[26], bfreq[26];
int ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    for(char ch : a) afreq[ch - 'a']++;
    for(char ch : b) bfreq[ch - 'a']++;

    for(int i = 0; i < 26; i++) {
        ans += abs(afreq[i] - bfreq[i]);
    }
    cout << ans;
}