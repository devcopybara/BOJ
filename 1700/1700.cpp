// https://www.acmicpc.net/problem/1700
#include <bits/stdc++.h>
using namespace std;
#define INF_T 105
int n, k;
int idx_app[105];
int time_app[105];
queue<int> app_time[105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    
    for(int t = 0; t < k; t++) {
        int app;
        cin >> app;
        time_app[t] = app;
        app_time[app].push(t);
    }
    
    int ans = 0;
    for(int t = 0; t < k; t++) {
        int cur_app = time_app[t];
        app_time[cur_app].pop();

        int max_time = 0;
        int max_idx = 0;
        for(int i = 0; i < n; i++) {
            int tar_app = idx_app[i];
            // 빈자리가 있는 경우
            if(tar_app == 0) {
                max_idx = i;
                break;
            }
            // 이미 꽂혀 있는 경우
            if(cur_app == tar_app) {
                max_idx = i;
                break;
            }
            // 뭘 뽑을지 결정
            if(app_time[tar_app].empty()) {
                max_time = INF_T;
                max_idx = i;
            }
            else {
                if(app_time[tar_app].front() > max_time) {
                    max_time = app_time[tar_app].front();
                    max_idx = i;
                }
            }
        }

        if(cur_app != idx_app[max_idx]) {
            if(idx_app[max_idx] != 0)
                ans++;
            idx_app[max_idx] = cur_app;
        }
    }
    cout << ans;
}