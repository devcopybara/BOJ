// https://www.acmicpc.net/problem/1043
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> person_vis(52,false);
vector<bool> party_vis(52,false);

int cnt;
vector<int> truth_people;
vector<int> party2people[52];
vector<int> person2parties[52];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    cin >> cnt;
    for(int i = 0; i < cnt; i++) {
        int a;
        cin >> a;
        truth_people.push_back(a);
    }
    
    for(int i = 1; i <= m; i++) {
        cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            int a;
            cin >> a;
            party2people[i].push_back(a);
            person2parties[a].push_back(i);
        }
    }
    
    for(int a : truth_people) {
        queue<int> q;
        person_vis[a] = 1;
        q.push(a);
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(int i : person2parties[cur]) {
                for(int nxt : party2people[i]) {
                    if(person_vis[nxt]) continue;
                    person_vis[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
    }

    for(int a = 1; a <= n; a++) {
        if(!person_vis[a]) continue;

        for(int i : person2parties[a]) {
            party_vis[i] = 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if(!party_vis[i]) {
            ans++;
        }
    }
    cout << ans;
}