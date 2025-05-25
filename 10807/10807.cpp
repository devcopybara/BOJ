#include <iostream>
using namespace std;

int occur[201];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        occur[a + 100]++;
    }

    int v;
    cin >> v;

    cout << occur[v + 100];
}