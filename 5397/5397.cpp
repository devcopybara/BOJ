#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string keylog;
        cin >> keylog;

        list<char> password;
        list<char>::iterator cursor = password.end();
        for(char ch : keylog) {
            switch(ch) {
                case '<':
                    if(cursor != password.begin()) cursor--;
                    break;
                case '>':
                    if(cursor != password.end()) cursor++;
                    break;
                case '-':
                    if(cursor != password.begin()) {
                        cursor--;
                        cursor = password.erase(cursor);
                    }
                    break;
                default:
                    password.insert(cursor, ch);
                    break;
            }
        }

        for(char ch : password) cout << ch;
        cout << '\n';
    }
}