#include <bits/stdc++.h>
using namespace std;

const int MX = 250'005;
int dat[MX];
int lc[MX];
int rc[MX];
int unused = 0;

// int insert(int cur, int x, int h) {
//     if(x < dat[cur]) {
//         if(lc[cur] != -1) {
//             return insert(lc[cur], x, h+1);
//         }
//         else {
//             lc[cur] = unused;
//             dat[unused] = x;
//             unused++;
//             return h+1;
//         }
//     }
//     else {
//         if(rc[cur] != -1) {
//             return insert(rc[cur], x, h+1);
//         }
//         else {
//             rc[cur] = unused;
//             dat[unused] = x;
//             unused++;
//             return h+1;
//         }
//     }
// }

int insert(int x) {

    int cur = 0, h = 1;
    while(cur != -1) {
        h++;
        if(x < dat[cur]) {
            if(lc[cur] != -1) {
                cur = lc[cur];
            }
            else {
                lc[cur] = unused;
                dat[unused] = x;
                unused++;
                break;
            }
        }
        else {
            if(rc[cur] != -1) {
                cur = rc[cur];
            }
            else {
                rc[cur] = unused;
                dat[unused] = x;
                unused++;
                break;
            }
        }
    }
    return h;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    fill(lc, lc+n, -1);
    fill(rc, rc+n, -1);

    int root;
    cin >> root;
    dat[unused] = root;
    unused++;
    
    int ans = 1;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        ans += insert(x);
    }
    cout << ans;
}