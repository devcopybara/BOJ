// https://www.acmicpc.net/problem/11650
#include <iostream>
using namespace std;

#define X first
#define Y second

const int MX = 100'005;
pair<int,int> arr[MX];
pair<int,int> tmp[MX];

void MergeSort(int st, int en) {
    if(en<=st+1) return;
    int mid = (st+en)/2;
    MergeSort(st,mid);
    MergeSort(mid,en);

    int lidx = st;
    int ridx = mid;
    for(int i = st; i < en; i++) {
        if(lidx == mid) tmp[i] = arr[ridx++];
        else if(ridx == en) tmp[i] = arr[lidx++];
        else if(arr[lidx].X < arr[ridx].X) tmp[i] = arr[lidx++];
        else if(arr[lidx].X == arr[ridx].X && arr[lidx].Y <= arr[ridx].Y) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for(int i = st; i < en; i++) arr[i] = tmp[i];
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
    
    MergeSort(0,n);

    for(int i = 0; i < n; i++) {
        cout << arr[i].X << ' ' << arr[i].Y << '\n';
    }
}