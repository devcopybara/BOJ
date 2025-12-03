#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<string, vector<string>> ancestors;
unordered_map<string, int> indegree;

vector<string> result;
unordered_map<string, int> order;

set<string> names;
set<string> roots;
unordered_map<string, set<string>> child_names;

bool cmp(string a, string b) {
    return order[a] < order[b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        names.insert(name);
    }
    
    cin >> m;
    while(m--) {
        string name1, name2;
        cin >> name1 >> name2;
        ancestors[name1].push_back(name2);
        indegree[name2]++;
    }
    // 조상에 대해 위상정렬
    queue<string> q;
    for(string name : names) {
        if(indegree[name] == 0) {
            q.push(name);
        }
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        result.push_back(cur);
        for(auto nxt : ancestors[cur]) {
            indegree[nxt]--;
            if(indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    // result : 정렬된 조상 순서 -> order : 자신의 순서 
    for(int i = 0; i < n; i++)
        order[result[i]] = i;

    // 직계 부모 탐색을 통해 직계 자식 구성
    for(string name : names) {
        // 조상이 없으면 시조
        if(ancestors[name].size() == 0) {
            roots.insert(name);
        }
        // 순서가 가장 빠른 조상이 직계 부모
        else {
            sort(ancestors[name].begin(), ancestors[name].end(), cmp);
            string parent_name = *ancestors[name].begin();
            child_names[parent_name].insert(name);
        }
    }
    // 시조 이름 순으로 출력
    cout << roots.size() << '\n';
    for(auto name : roots) {
        cout << name << ' ';
    }   
    cout << '\n';
    // 이름 순으로 
    for(string name : names) {
        cout << name << ' ' << child_names[name].size() << ' ';
        // 직계 자식 이름 순으로 출력
        for(string child_name : child_names[name]) {
            cout << child_name << ' ';
        }   
        cout << '\n';
    }
}