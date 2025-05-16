#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int year;
    cin >> year;

    if(year % 4) cout << 0;
    else if(year % 100) cout << 1;
    else if(year % 400) cout << 0;
    else cout << 1;
    
    
}