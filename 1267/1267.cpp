#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, y = 0, m = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;

        y += 10 + (a / 30) * 10;
        m += 15 + (a / 60) * 15;
    }

    if(m > y) cout << "M " << m;
    else if(y < m) cout << "Y " << y;
    else cout << "Y M " << y;
}