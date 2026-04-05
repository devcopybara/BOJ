// https://www.acmicpc.net/problem/18870
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'005;
int a[MX];
int b[MX];
int n;
int uni[MX];
int m;

int binary_search(int tar) {
    int st = 0;
    int en = m-1;

    while(st <= en) {
        int mid = (st+en)/2;
        if(uni[mid] < tar) st = mid+1;
        else if(uni[mid] > tar) en = mid-1;
        else return mid;
    }
    return -1;
}

int lower_bound(int tar) {
    int st = 0;
    int en = m;

    while(st < en) {
        int mid = (st+en)/2;
        if(uni[mid] < tar) st = mid+1;
        else if(uni[mid] > tar) en = mid;
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
    memcpy(b,a,n*sizeof(int));

    sort(a,a+n);

    for(int i = 0; i < n; i = upper_bound(a[i])) uni[m++] = a[i];

    for(int i = 0; i < n; i++) cout << lower_bound(b[i]) << ' '; // binary_search(b[i]) << ' ';
}