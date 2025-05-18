#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;

    cin >> a >> b >> c;

    if(a>b)swap(a, b);

    if(b>c) {
        swap(b, c);
        if(a>b) swap(a, b);
    }
    
    cout << a << " " << b << " " << c;
}