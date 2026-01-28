// pred와 succ 사이에는 다른 값이 없기 때문에 둘을 갈라놓을 수 있는 분기 노드가 존재할 수 없기 때문에
// pred와 succ 중 나중에 삽입된 노드는 먼저 삽입된 노드의 서브트리에 삽입되고,
// pred < x < succ를 만족하므로 x는 pred와 succ의 서브트리 사이의 서브트리이므로 두 노드의 공통 서브트리로 내려가게 되고, 
// 이때 가장 깊은 노드인 “나중에 삽입된 노드”의 자식

#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<int64> ls;
    set<int64> s;
    unordered_map<int64,int64> um;

    int root;
    cin >> root;
    s.insert(root);
    um[root] = 1;

    int64 ans = 1;
    for(int i = 1; i < n; i++) {
        int64 x;
        cin >> x;
        
        int64 h = 1;
        auto it = s.lower_bound(x);
        if (it != s.end()) h = max(h, um[*it] + 1);
        if (it != s.begin()) h = max(h, um[*prev(it)] + 1);

        um[x] = h;
        ans += h;
        s.insert(x);
    }
    cout << ans;
}