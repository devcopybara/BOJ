#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, cnt;

    for(int i = 0; i < 3; i++)  {
        cnt = 0;

        for(int i = 0; i < 4; i++) {
            cin >> a;
            cnt += a;
        }

        cout << "DCBAE"[cnt] << "\n";
    }
}