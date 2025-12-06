// https://www.acmicpc.net/problem/1005
#include <bits/stdc++.h>
using namespace std;
int t,n,k,w;
vector<int> adj[10'005];
int deg[10'005];
int duration[10'005];

struct Compare {
    bool operator()(int a, int b) const {
        if(duration[a] != duration[b])
            return duration[a] < duration[b];
        return a < b;
    }
};
set<int, Compare> task_queue;

void multitasking(int task_time) {
    for(int task : task_queue) {
        duration[task] -= task_time;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t; 
    while(t--) {
        // 초기화, 입력
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> duration[i];
            adj[i].clear();
            deg[i] = 0;
        }
        for(int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            deg[v]++;
        }
        cin >> w;
        task_queue.clear();
        // 위상정렬
        for(int i = 1; i <= n; i++) {
            if(deg[i] == 0) {
                task_queue.insert(i);
            }
        }
        int total_task_time = 0;
        while(!task_queue.empty()) {
            int cur = *task_queue.begin(); task_queue.erase(task_queue.begin());
            if(duration[cur] > 0) {
                total_task_time += duration[cur];
                multitasking(duration[cur]);
                duration[cur] = 0;
            }
            if(cur == w)
                cout << total_task_time << '\n';
            for(int nxt : adj[cur]) {
                deg[nxt]--;
                if(deg[nxt] == 0) {
                    task_queue.insert(nxt);
                }
            }
        }
    }
}