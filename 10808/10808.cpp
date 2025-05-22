#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for(char a = 'a'; a <= 'z'; a++) {
        int cnt = 0;
        for(char c : s) {
            if(c == a) cnt++;
        }
        cout << cnt << " ";
    }
}