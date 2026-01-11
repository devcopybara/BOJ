// https://www.acmicpc.net/problem/17299
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
int val[MX], freq[MX];
int ans[MX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        val[i] = x;
        freq[x]++;
    }
    
    for(int i = n-1; i >= 0; i--) {
        int x = val[i], y = freq[val[i]];
        while(!empty()) {
            if(top().Y > y) break;
            pop();
        }

        if(empty()) ans[i] = -1;
        else ans[i] = top().X;

        push({x,y});
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}
