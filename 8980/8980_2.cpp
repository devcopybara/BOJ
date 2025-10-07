// https://www.acmicpc.net/problem/8980
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, c, m;
tuple<int,int,int> box[10005];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> truck;
int cap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c >> m;
    for(int i = 0; i < m; i++) {
        int st, en, cnt;
        cin >> st >> en >> cnt;
        box[i] = {en, st, cnt};
    }
    sort(box, box + m);

    int ans = 0;
    for(int i = 1, j = 0; i <= n; i++) {
        // 짐 내리기
        while(!truck.empty() && truck.top().X == i) {
            auto cur = truck.top();
            cap -= cur.Y;
            ans += cur.Y;
            truck.pop();
        }
        
        // 짐 싣기
        while(cap < c && j < m) {
            int st, en, cnt;
            tie(en, st, cnt) = box[j];
            if(st >= i && cnt > 0) {
                if(c - cap >= cnt) {
                    truck.push({en,cnt});
                    cap += cnt;
                    cnt = 0;
                    box[j] = {en, st, cnt};
                    j++;
                }
                else {
                    truck.push({en,c - cap});
                    cnt -= c - cap;
                    cap = c;
                    box[j] = {en, st, cnt};
                }
            }
            else {
                j++;
            }
        }
    }
    cout << ans;
}