// https://www.acmicpc.net/problem/1043
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> party_adj[52];
vector<bool> vis(52,false);

int cnt;
vector<int> truth_people;
vector<int> party2person[52];
vector<int> person2party[52];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // 진실을 아는 참가자 리스트
    cin >> cnt;
    for(int i = 0; i < cnt; i++) {
        int parti;
        cin >> parti;
        truth_people.push_back(parti);
    }
    // 각 파티마다 오는 사람의 수와 번호
    for(int party = 1; party <= m; party++) {
        cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            int parti;
            cin >> parti;
            party2person[party].push_back(parti); // 각 파티에 오는 사람의 번호
            person2party[parti].push_back(party); // 각 사람이 가는 파티의 번호
        }
    }
    // 파티 인접리트스
    for(int u = 1; u <= m; u++) {
        for(int person : party2person[u]) {
            for(int v : person2party[person]) {
                if(v == u) continue; // v파티는 u파티에 참가하는 사람이 참가하는 모든 파티의 리스트이므로 v중 u가 반드시 포함된다.
                party_adj[u].push_back(v); 
                // party_adj[v].push_back(u); 중복으로 생략 (v파티에도 같은 person이 있을 것이므로 u파티도 추가된다.)
            }
        }
    }
    // 진실을 아는 참가자들이 방문하는 파티 bfs
    for(int truth_person : truth_people) {
        for(int truth_party : person2party[truth_person]) {
            if(vis[truth_party]) continue;
            queue<int> q;
            q.push(truth_party);
            vis[truth_party] = true;
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int nxt : party_adj[cur]) {
                    if(vis[nxt]) continue;
                    q.push(nxt);
                    vis[nxt] = true;
                }
            }
        }
    }
    // 과장된 이야기를 할 수 있는 파티 개수의 최댓값
    int ans = 0;
    for(int party = 1; party <= m; party++) {
        if(!vis[party]) ans++;
    }
    cout << ans;
}