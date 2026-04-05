// https://www.acmicpc.net/problem/2110
#include <bits/stdc++.h>
using namespace std;

const int MX = 200'005;
int a[MX];
int n,c;

int get_cnt(int dist) {
    int cnt = 1;

    int pre = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i]-pre >= dist) {
            pre = a[i];
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);

    int st = 1;
    int en = 1'000'000'000;
    while(st < en) {
        int mid = (st+en+1)/2;

        int cnt = get_cnt(mid);

        if(c < cnt) st = mid;
        else if(c > cnt) en = mid-1;
        else st = mid;
    }
    cout << st;
}