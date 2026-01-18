// https://www.acmicpc.net/problem/11650
#include <iostream>
using namespace std;

#define X first
#define Y second

const int MX = 100'005;
pair<int,int> arr[MX];

void QuickSort(int st, int en) {
    if(en<=st+1) return;

    auto pivot = arr[st];
    int lidx = st+1;
    int ridx = en-1;

    while(1) {
        while(lidx<=ridx && arr[lidx]<=pivot) lidx++;
        while(lidx<=ridx && arr[ridx]>=pivot) ridx--;
        if(lidx>ridx) break;
        swap(arr[lidx],arr[ridx]);
    }

    swap(arr[st],arr[ridx]);
    QuickSort(st,ridx);
    QuickSort(ridx+1,en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x,y};
    }
    
    QuickSort(0,n);

    for(int i = 0; i < n; i++) {
        cout << arr[i].X << ' ' << arr[i].Y << '\n';
    }
}