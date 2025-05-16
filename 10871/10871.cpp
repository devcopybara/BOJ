#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, t;

    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> t;

        if(t < x) cout << t << " ";
    }
    cout << "\n";
}