#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    int la = a.size(), lb = b.size();
    if(la != lb) return la < lb;

    int na = 0, nb = 0;
    for(char ch : a) if(isdigit(ch)) na += ch - '0';
    for(char ch : b) if(isdigit(ch)) nb += ch - '0';
    if(na != nb) return na < nb;

    return a < b;
}


int n;
string arr[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}