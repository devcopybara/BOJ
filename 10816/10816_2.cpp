// https://www.acmicpc.net/problem/10816
#include <bits/stdc++.h>
using namespace std;

const int MX = 500'005;
int a[MX];
int n;

int lower_bound(int tar) {
    int st = 0;
    int en = n;

    while(st < en) {
        int mid = (st+en)/2;

        if(a[mid] < tar) st = mid+1;
        else if(a[mid] > tar) en = mid;
        else en = mid;
    }
    return en;
}

int upper_bound(int tar) {
    int st = 0;
    int en = n;

    while(st < en) {
        int mid = (st+en)/2;

        if(a[mid] < tar) st = mid+1;
        else if(a[mid] > tar) en = mid;
        else st = mid+1;
    }
    return en;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);

    int m;
    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        cout << upper_bound(x)-lower_bound(x) << ' ';
    }
}