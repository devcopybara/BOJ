// https://www.acmicpc.net/problem/8980
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, c, m;
tuple<int,int,int> box[10005];
list<pair<int,int>> truck;
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
        auto it = truck.begin();
        while(it != truck.end()) {
            pair<int,int> cur = *it;
            if(cur.X == i) {
                cap -= cur.Y;
                ans += cur.Y;
                auto _it = it++;
                truck.erase(_it);
            }
            else {
                it++;
            }
        }
        
        // 짐 싣기
        while(cap < c && j < m) {
            int st, en, cnt;
            tie(en, st, cnt) = box[j];
            if(st >= i && cnt > 0) {
                if(c - cap >= cnt) {
                    truck.push_back({en,cnt});
                    cap += cnt;
                    cnt = 0;
                    box[j] = {en, st, cnt};
                    j++;
                }
                else {
                    truck.push_back({en,c - cap});
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