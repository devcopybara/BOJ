// https://www.acmicpc.net/problem/10814
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 100'005;
pair<int,string> arr[MX];

bool cmp(const pair<int,string>& a, const pair<int,string>& b) {
    return a.X < b.X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        arr[i] = {age,name};
    }

    stable_sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++) {
        cout << arr[i].X << ' ' << arr[i].Y << '\n';
    }
}