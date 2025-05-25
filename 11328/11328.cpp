#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string a, b;
    int afreq[26], bfreq[26];
    for(int i = 0; i < n; i++) {
        cin >> a >> b;

        fill(afreq, afreq + 26, 0);
        for(char ch : a) afreq[ch - 'a']++;
        fill(bfreq, bfreq + 26, 0);
        for(char ch : b) bfreq[ch - 'a']++;

        bool isPossible = true;
        for(int i = 0; i < 26; i++) {
            if(afreq[i] != bfreq[i]) {
                isPossible = false;
                break;
            }
        }
        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}