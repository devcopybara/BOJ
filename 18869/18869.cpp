// https://www.acmicpc.net/problem/18869
#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[100][10'000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    int ans = 0;

    for(int a = 0; a < m; a++) {
        for(int b = a+1; b < m; b++) {

            bool is_same = true;
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    if((arr[a][i] == arr[a][j] && arr[b][i] == arr[b][j])
                    || (arr[a][i] > arr[a][j] && arr[b][i] > arr[b][j])
                    || (arr[a][i] < arr[a][j] && arr[b][i] < arr[b][j])) {
                        continue;
                    }
                    else {
                        is_same = false;
                        break;
                    }
                }

                if(!is_same)
                    break;
            }

            if(is_same)
                ans++;
        }
    }

    cout << ans;
}