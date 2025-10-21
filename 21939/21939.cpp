// https://www.acmicpc.net/problem/21939
#include <bits/stdc++.h>
using namespace std;
int n,m;
int level[100'002];
multiset<pair<int,int>> problems;
string cmd;
int p,l,x;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> p >> l;
        problems.insert({l,p});
        level[p] = l;
    }
    cin >> m;
    while(m--) {
        cin >> cmd;
        if(cmd == "add") {
            cin >> p >> l;
            level[p] = l;
            problems.insert({l,p});
        }
        else if(cmd == "solved") {
            cin >> p;
            problems.erase({level[p],p});
        }
        else {
            cin >> x;
            if(x == 1)
                cout << prev(problems.end())->second << '\n';
            else
                cout << problems.begin()->second << '\n';
        }
    }
}