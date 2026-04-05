#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];

int binary_search(int tar) {
    int st = 0;
    int en = n-1;
    while(st <= en) {
        int mid = (st+en)/2;
        if(a[mid] < tar) st = mid+1;
        else if(a[mid] > tar) en = mid-1;
        else return mid;
    }
    return -1;
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
        int i = binary_search(tar);
        if(i == -1) {
            cout << 0 << ' ';
        }
        else {
            int cnt = 0;
            for(int j = i; j < n; j++) {
                if(a[i] == a[j]) cnt++;
                else break;
            }
            for(int j = i; j >= 0; j--) {
                if(a[i] == a[j]) cnt++;
                else break;
            }
            cout << cnt-1 << ' ';
        }
    }
}