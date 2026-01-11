// https://www.acmicpc.net/problem/22866

#include <iostream>
using namespace std;

using pii = pair<int,int>;
#define X first
#define Y second

const int MX = 1'000'005;
pii dat[MX];
int pos;
void push(pii x) {dat[pos++]=x;};
void pop() {pos--;}
pii top() {return dat[pos-1];}
bool empty() {return pos==0;}
int size() {return pos;}

int h[MX], cnt[MX], idx[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // left
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        h[i] = x;

        while(!empty()) {
            if(top().X > x) break;
            pop();
        }

        if(!empty()) {
            cnt[i] += size();
            if(idx[i] == 0) idx[i] = top().Y;
            else idx[i] = (abs(i - idx[i]) <= abs(i - top().Y)) ? idx[i] : top().Y;
        }

        push({x,i});
    }
    while(!empty()) pop();

    // right
    for(int i = n; i > 0; i--) {
        int x = h[i];

        while(!empty()) {
            if(top().X > x) break;
            pop();
        }

        if(!empty()) {
            cnt[i] += size();
            if(idx[i] == 0) idx[i] = top().Y;
            else idx[i] = (abs(i - idx[i]) <= abs(i - top().Y)) ? idx[i] : top().Y;
        }

        push({x,i});
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) cout << "0\n";
        else cout << cnt[i] << ' ' << idx[i] << '\n';
    }
}