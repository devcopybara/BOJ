#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    list<char> L;
    for(char ch : s) L.push_back(ch);
    
    list<char>::iterator it = L.end();

    int n;
    cin >> n;

    char cmd;
    while(n--) {
        cin >> cmd;

        switch(cmd) {
            case 'L':
                if(it != L.begin()) it--;
                break;
            case 'D':
                if(it != L.end()) it++;
                break;
            case 'B':
                if(it != L.begin()) {
                    it--;
                    it = L.erase(it);
                }
                break;
            case 'P':
            default:
                cin >> cmd;
                L.insert(it, cmd);
                break;
        }
    }

    for(char ch : L) cout << ch;
}