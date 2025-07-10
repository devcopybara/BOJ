#include <iostream>
using namespace std;

const int MX = 100002;
template <typename T>
struct stack{
    T dat[MX];
    int pos = 0;
    void push(T x) {
        dat[pos++] = x;
    }
    void pop() {
        pos--;
    }
    T top() {
        return dat[pos-1];
    }
    int empty() {
        return pos==0;
    }
};

stack<int> S;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        
        if(n) {
            S.push(n);
        }
        else {
            S.pop();
        }
    }

    
    int ans = 0;    
    while(!S.empty()) {
        ans += S.top(); S.pop();
    }
    cout << ans;
}