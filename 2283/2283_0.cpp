// https://www.acmicpc.net/problem/2283
#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt;
int freq[1'000'005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = x; j < y; j++) freq[j]++;
    }

    int a = 0, b = 0;
    
    int en = 0;
    for(int st = 0; st < 1000000; st++) {
        while(en < 1000000 && cnt < k){
            cnt += freq[en];
            en++;
        }
        if(cnt == k){
            a = st, b = en;
            break;
        }
        if(en == 1000000) break;
        cnt -= freq[st];
    }

    cout << a << ' ' << b;
}