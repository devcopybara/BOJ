// https://www.acmicpc.net/problem/17298

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000002;
int A[MX];
int NGE[MX];
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];

    for(int i = n - 1; i >= 0; i--) {

        while(!S.empty() && S.top() <= A[i]) {
            S.pop();
        }
        if(S.empty()) {
            NGE[i] = -1;
        }
        else {
            NGE[i] = S.top();
        }
        S.push(A[i]);
    }

    for(int i = 0; i < n; i++) cout << NGE[i] << ' ';
}