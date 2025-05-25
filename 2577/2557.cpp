#include <bits/stdc++.h>
using namespace std;

int freq[10];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int abc = a * b * c;
    while(abc) {
        freq[abc % 10]++;
        abc /= 10;
    }

    for(int i = 0; i < 10; i++) cout << freq[i] << "\n";
}