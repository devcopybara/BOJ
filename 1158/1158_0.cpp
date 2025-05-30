#include <bits/stdc++.h>
using namespace std;

const int MX = 5005;

int dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        dat[i] = i;
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    pre[1] = n;
    nxt[n] = 1;
    nxt[0] = 1;
    
    int size = n;
    int cur = 0;
    cout << '<';
    while(size) {
        for(int i = 0; i < k; i++) cur = nxt[cur];
        
        cout << dat[cur];
        nxt[pre[cur]] = nxt[cur];
        pre[nxt[cur]] = pre[cur];
        size--;

        if(size) cout << ", ";
  }
  cout << '>';
}