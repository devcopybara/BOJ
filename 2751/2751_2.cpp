#include <iostream>
using namespace std;

const int MX = 1'000'005;
int arr[MX];

void QuickSort(int st, int en) {
    if(en<=st+1) return;
    int pivot = arr[st];
    int lidx = st+1;
    int ridx = en-1;

    while(1) {
        while(lidx <= ridx && arr[lidx] <= pivot) lidx++;
        while(lidx <= ridx && arr[ridx] >= pivot) ridx--;
        if(lidx > ridx) break;
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
    for(int i = 0; i < n; i++) cin >> arr[i];
    QuickSort(0,n);
    for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}