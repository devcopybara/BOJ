// https://www.acmicpc.net/problem/21944
#include <bits/stdc++.h>
using namespace std;
int n,m,p,l,g,x;
string cmd;
pair<int,int> P2LG[100'002];
set<int> L2P[102];
set<int> GL2P[102][102];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> p >> l >> g;
        P2LG[p] = {l,g};
        L2P[l].insert(p);
        GL2P[g][l].insert(p);
    }
    cin >> m;
    while(m--) {
        cin >> cmd;
        if(cmd=="recommend") {
            cin >> g >> x;
            if(x == 1) {
                for(int i = 100; i > 0; i--) {
                    if(GL2P[g][i].empty()) continue;
                    cout << *prev(GL2P[g][i].end()) << '\n';
                    break;
                }
            }
            else {
                for(int i = 1; i <= 100; i++) {
                    if(GL2P[g][i].empty()) continue;
                    cout << *GL2P[g][i].begin() << '\n';
                    break;
                }
            }
        }
        else if(cmd=="recommend2") {
            cin >> x;
            if(x == 1) {
                for(int i = 100; i > 0; i--) {
                    if(L2P[i].empty()) continue;
                    cout << *prev(L2P[i].end()) << '\n';
                    break;
                }
            }
            else {
                for(int i = 1; i <= 100; i++) {
                    if(L2P[i].empty()) continue;
                    cout << *L2P[i].begin() << '\n';
                    break;
                }
            }
        }
        else if(cmd=="recommend3") {
            cin >> x >> l;
            bool isexist = 0;
            if(x == 1) {
                for(int i = l; i <= 100; i++) {
                    if(L2P[i].empty()) continue;
                    cout << *L2P[i].begin() << '\n';
                    isexist = 1;
                    break;
                }
            }
            else {
                for(int i = l-1; i > 0; i--) {
                    if(L2P[i].empty()) continue;
                    cout << *prev(L2P[i].end()) << '\n';
                    isexist = 1;
                    break;
                }
            }
            if(!isexist) cout << "-1\n";
        }
        else if(cmd=="add") {
            cin >> p >> l >> g;
            P2LG[p] = {l,g};
            L2P[l].insert(p);
            GL2P[g][l].insert(p);
        }
        else {
            cin >> p;
            tie(l,g) = P2LG[p];
            L2P[l].erase(p);
            GL2P[g][l].erase(p);
        }
    }
}