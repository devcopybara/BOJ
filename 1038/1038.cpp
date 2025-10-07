// https://www.acmicpc.net/problem/1038
#include <bits/stdc++.h>
using namespace std;

vector<bool> a(10, 0);
int n; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        a[9 - i] = 1;
        do {
            if(cnt != n) {
                cnt++;
                continue;
            }
            for(int i = 0; i < 10; i++)
                if(a[i]) 
                    cout << 9 - i;
            return 0;
        } while(next_permutation(a.begin(), a.end()));
    }
    cout << -1;
}