// https://www.acmicpc.net/problem/12015
#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (arr.empty() || arr.back() < x) {
            arr.push_back(x);
        }
        else {
            int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            arr[idx] = x;
        }
    }

    cout << arr.size();
}
