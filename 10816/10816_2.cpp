#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];

int upper_idx(int tar) {
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st+en)/2;
        if(a[mid] > tar) en = mid;
        else st = mid+1;
    }
    return st;
}

int lower_idx(int tar) {
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st+en)/2;
        if(a[mid] >= tar) en = mid;
        else st = mid+1;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    cin >> m;
    while(m--) {
        int tar;
        cin >> tar;
        cout << upper_idx(tar) - lower_idx(tar) << ' ';
    }
}