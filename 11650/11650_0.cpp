// https://www.acmicpc.net/problem/11650
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<pair<int,int>> arr;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x,y});
    }
    sort(arr.begin(), arr.end());
    for(auto pos : arr) {
        cout << pos.X << ' ' << pos.Y << '\n';
    }
}