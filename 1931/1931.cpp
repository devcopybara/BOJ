#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> schedules;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int st, en;
        cin >> st >> en;
        schedules.push_back({en,st});
    }
    sort(schedules.begin(), schedules.end());
    int ans = 0;
    int pre = 0;
    for(pair<int,int> schedule : schedules) {
        int st = schedule.second, en = schedule.first;
        if(st >= pre) {
            ans++;
            pre = en;
        }
    }
    cout << ans;
}