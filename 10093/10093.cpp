#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long a, b, t;
    cin >> a >> b;

    if(a > b) {
        t = a;
        a = b;
        b = t;
    }

    cout << (b != a ? b - a - 1 : 0) << "\n";

    for(unsigned long long i = a + 1; i < b; i++) cout << i << " ";
}