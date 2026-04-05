// https://www.acmicpc.net/problem/2467
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 2'000'000'005;
const int MX = 100'005;
int arr[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    pair<int,int> ans = {0,1};
    for(int i = 0; i < n; i++) {
        int j = lower_bound(arr+i+1,arr+n,-arr[i])-arr;

        if((j < n) && (abs(arr[i]+arr[j]) < abs(arr[ans.X]+arr[ans.Y]))) ans = {i,j};
        if((j-1 != i) && (abs(arr[i]+arr[j-1]) < abs(arr[ans.X]+arr[ans.Y]))) ans = {i,j-1};
    }

    cout << arr[ans.X] << " " << arr[ans.Y];
}