#include <bits/stdc++.h>
using namespace std;

const int MX = 10000 * 10 + 5;
int ROOT = 1;
int unused = 2;
int nxt[MX][10];
bool chk[MX];

int c2i(char c) {
    return c-'0';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        unused = 2;
        bool isvalid = true;
        fill(chk,chk+MX,false);
        for(int i = 0; i < MX; i++)
            fill(nxt[i],nxt[i]+10,-1);

        int n;
        cin >> n;
        while(n--) {
            string s;
            cin >> s;
            
            if(!isvalid) continue;

            int cur = ROOT;
            for(char c : s) {
                int idx = c2i(c);
                    
                if(nxt[cur][idx] == -1)
                    nxt[cur][idx] = unused++;
                cur = nxt[cur][idx];
                
                if(chk[cur]) {
                    isvalid = false;
                    break;
                }
            }
            chk[cur] = true;

            // if(cur != unused - 1) 

            for(int idx = 0; idx < 10; idx++) {
                if(nxt[cur][idx] != -1) {
                    isvalid = false;
                    break;
                }
            }
        }

        if(isvalid) cout << "YES\n";
        else cout << "NO\n";
    }
}