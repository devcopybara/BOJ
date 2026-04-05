// https://www.acmicpc.net/problem/14002
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
int tbx[MX];
int tbi[MX];
int len;
int arr[MX];
int pre[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        
        if(tbx[len] < x) {
            pre[i] = tbi[len++];
            tbx[len] = x;
            tbi[len] = i;
        }
        else {
            for(int j = len-1; j >= 0; j--) {
                if(tbx[j] < x) {
                    pre[i] = tbi[j];
                    tbx[j+1] = x;
                    tbi[j+1] = i;
                    break;
                }
            }
        }
    }

    cout << len << '\n';

    vector<int> ans;
    int cur = tbi[len];
    while(cur != 0) {
        ans.push_back(arr[cur]);
        cur = pre[cur];
    }

    for(int i = len-1; i >= 0; i--) cout << ans[i] << ' ';
}