#include <bits/stdc++.h>
using namespace std;
int n;
int a[100'005];
vector<bool> used(100'005,false);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    long long ans = 0;
    used[a[0]] = 1;
    int en = 0;
    for(int st = 0; st < n; st++) {
        while(en < n-1 && !used[a[en+1]]) {
            en++;
            used[a[en]] = 1;
        }
        
        ans += (en-st+1); // st를 시작으로 하는 경우의수
        used[a[st]] = 0;
    }
    cout << ans;
}