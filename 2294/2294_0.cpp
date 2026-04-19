#include<iostream>
using namespace std;
const int MXN = 102;
const int MXK = 10'002;
const int INF = MXK;
int a[MXN];
int d[MXK];
int n, k;

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    fill(d+1,d+1+k,INF);
    d[0] = 0;

    for(int i = 1; i <= k; i++) {
        int tmp = INF;
        for(int j = 1; j <= n; j++) {
            if(i >= a[j]) {
                tmp = min(tmp,d[i-a[j]]+1);
            }
        }
        if(tmp != INF) d[i] = tmp;
    }
    
    if(d[k] == INF) cout << -1;
    else cout << d[k];
}