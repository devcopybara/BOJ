// https://www.acmicpc.net/problem/18869
// 각 우주의 구성 미리 계산
// 각 우주의 구성 비교 
#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[102][10002];

int binary_search(vector<int>& v, int target) {
    int st = 0;
    int en = v.size() - 1;
    while(st <= en) {
        int mid = (st+en)/2;
        if(v[mid] > target) en=mid-1;
        else if(v[mid] < target) st=mid+1;
        else return mid;
    }
    return -1;
}

void compress(int a[]) {
    vector<int> v(a, a + n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++)
        a[i] = binary_search(v, a[i]);
}

bool compare(int a[], int b[]) {
    for (int k = 0; k < n; k++)
        if (a[k] != b[k]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
        compress(arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            ans += compare(arr[i], arr[j]);
    cout << ans;
}