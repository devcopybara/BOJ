#include <iostream>
using namespace std;

const int MX = 1'000'005;
int arr[MX];
int tmp[MX];

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
        else if(arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for(int i = st; i < en; i++) arr[i] = tmp[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    MergeSort(0,n);
    for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}