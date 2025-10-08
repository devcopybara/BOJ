#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000005];
int tmp[1000005];
int uni[1000005];

int lower_idx(int tar, int arr[], int len) {
    int st = 0;
    int en = len;
    while(st < en) {
        int mid = (st+en)/2;
        if(tar <= arr[mid]) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int tar, int arr[], int len) {
    int st = 0;
    int en = len;
    while(st < en) {
        int mid = (st+en)/2;
        if(tar < arr[mid]) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a[i] = tmp[i] = val;
    }
    sort(tmp,tmp+n);
    uni[m++] = tmp[0];
    for(int i = 1; i < n; i++) {
        if(tmp[i-1] != tmp[i])
            uni[m++] = tmp[i];
    }
    for(int i = 0; i < n; i++) {
        cout << lower_idx(a[i], uni, m) << ' ';
    }
}