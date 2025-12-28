// https://www.acmicpc.net/problem/7432
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MX = 500 * 40 + 5;
map<string, int> adj[MX];
int ROOT = 1;
int unused = 2;

void dfs(int cur, int depth) {
    for(auto nxt : adj[cur]) {
        cout << string(depth, ' ') << nxt.X << '\n';
        dfs(nxt.Y, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        // "WINNT\SYSTEM32\CONFIG"
        string path;
        cin >> path;
        
        // {"WINNT", "SYSTEM32", "CONFIG"}
        vector<string> dirs;
        size_t start = 0, pos;
        while ((pos = path.find('\\', start)) != string::npos) {
            dirs.push_back(path.substr(start, pos - start));
            start = pos + 1;
        }
        dirs.push_back(path.substr(start)); 
        
        // adj[node].find("WINNT"), adj[node].find("SYSTEM32"), adj[node].find("CONFIG")
        int cur = ROOT;
        for(string dir : dirs) {
            auto nxt = adj[cur].find(dir);
            if (nxt == adj[cur].end()) {
                adj[cur][dir] = unused++;
                cur = adj[cur][dir];
            } else {
                cur = nxt->second;
            }
        }
    }

    // print
    dfs(ROOT, 0);
}