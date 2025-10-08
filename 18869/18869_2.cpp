// https://www.acmicpc.net/problem/18869
// 각 우주의 구성 미리 계산
// 각 우주의 구성 문자열 정렬
// 같은 개수 계수 -> ans += xC2
#include <bits/stdc++.h>
using namespace std;
using uint64 = unsigned long long;
int m, n;
int arr[100][10'000];
string comp[100];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    for(int a = 0; a < m; a++) {
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[a][i] == arr[a][j])
                    comp[a] += '0';
                else if(arr[a][i] > arr[a][j])
                    comp[a] += '1';
                else if(arr[a][i] < arr[a][j])
                    comp[a] += '2';
            }
        }
    }
        
    sort(comp, comp+m);

    uint64 ans = 0;

    uint64 cnt = 0;
    for(int i = 0; i < m; i++) {
        if(i == 0 || comp[i-1] != comp[i]) {
            ans += cnt * (cnt-1) / 2;
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    ans += cnt * (cnt-1) / 2;
    
    cout << ans;
}