#include <bits/stdc++.h>
using namespace std;

const int MX = 35;

typedef pair<char, int> Dat;
typedef struct Stack{
    Dat dat[MX];
    int pos = 0;

    void push(Dat x) {
        dat[pos++] = x;
    }

    void pop() {
        pos--;
    }

    int empty() {
        return pos == 0;
    }

    Dat top() {
        return dat[pos - 1];
    }

    void acc(int x) {
        dat[pos - 1].second += x;
    }
}Stack;


int isValid(string& s, int len) {
    Stack S;

    for(int i = 0; i < len; i++) {
        if(s[i] == '(' || s[i] == '[') {
            S.push({s[i], 0});
        }
        else if(!S.empty()
            && ((s[i] == ')' && S.top().first == '(') || (s[i] == ']' && S.top().first == '['))
        ) {
            S.pop();
        }
        else {
            return 0;
        }
    }

    return S.empty() == 1 ? 1 : 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = 0, len = s.size();
    if(isValid(s, len)) {
        Stack S;
        for(int i = 0; i < len; i++) {
            if(s[i] == '(' || s[i] == '[') 
                S.push({s[i], 0});
            else {
                int score = max(1, S.top().second), weight = s[i] == ')' ? 2 : 3;
                S.pop();
                
                if(S.empty()) ans += score * weight;
                else S.acc(score * weight);
            }
        }
        cout << ans;
    }
    else {
        cout << 0;
    }
}