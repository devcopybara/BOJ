// https://www.acmicpc.net/problem/1920
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
int a[MX];
int n;

int binary_search(int tar) {
    int st = 0;
    int en = n-1;

    while(st <= en) {
        int mid=(st+en)/2;

        if(a[mid] > tar) en = mid-1;
        else if(a[mid] < tar) st = mid+1;
        else return 1;
    }
    return 0;
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
        cout << binary_search(x) << "\n";
    }
}