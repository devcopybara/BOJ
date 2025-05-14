#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int d, e, f;

    cin >> a >> b >> c;

    if(a>b)swap(a, b);

    d = min({a,b,c});
    f = max({a,b,c});
    e = a+b+c-d-f;

    cout << d << " " << e << " " << f;
    
    
}