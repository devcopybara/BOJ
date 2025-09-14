// https://www.acmicpc.net/problem/17140
#include <bits/stdc++.h>
using namespace std;

const int MX = 101;

int r,c,k;
int arr[MX][MX];
int cnt[MX];
int sec;

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int idx, int i, int k, int dir) {
    if(dir == 0) {
        swap(arr[idx][i],arr[idx][k]);
        swap(arr[idx][i+1],arr[idx][k+1]);
    }
    else {
        swap(arr[i][idx],arr[k][idx]);
        swap(arr[i+1][idx],arr[k+1][idx]);
    }
}

void sort2(int idx, int size, int dir) {
    if(dir == 0) {
        for(int i = 0; i < size; i += 2) {
            int k = i;
            for(int j = i + 2; j < size; j += 2) {
                if(arr[idx][k+1] > arr[idx][j+1] || 
                    (arr[idx][k+1] == arr[idx][j+1] && arr[idx][k] > arr[idx][j]))
                    k = j;
            }
            if(k != i)
                swap2(idx, i, k, 0);
        }
    }
    else {
        for(int i = 0; i < size; i += 2) {
            int k = i;
            for(int j = i + 2; j < size; j += 2) {
                if(arr[k+1][idx] > arr[j+1][idx] || 
                    (arr[k+1][idx] == arr[j+1][idx] && arr[k][idx] > arr[j][idx]))
                    k = j;
            }
            if(k != i)
                swap2(idx, i, k, 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k; r--, c--;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];
    int n = 3, m = 3;

    while(sec < 100) {
        if(arr[r][c] == k) {
            break;
        }

        if(n >= m) {
            // r 연산
            int max_size = 0;
            for(int i = 0; i < n; i++) {
                fill(cnt, cnt + MX, 0);

                for(int j = 0; j < m; j++) {
                    cnt[arr[i][j]]++;
                }

                int j = 0;
                for(int k = 1; k < MX; k++) {
                    if(cnt[k]) {
                        arr[i][j++] = k;
                        arr[i][j++] = cnt[k];
                    }
                }
                max_size = max(max_size, j);
                sort2(i,j,0);

                while(j < MX) arr[i][j++] = 0;
            }
            m = min(max_size, 100);
        }
        else {
            // c 연산
            int max_size = 0;
            for(int j = 0; j < m; j++) {
                fill(cnt, cnt + MX, 0);
                
                for(int i = 0; i < n; i++) {
                    cnt[arr[i][j]]++;
                }

                int i = 0;
                for(int k = 1; k < MX; k++) {
                    if(cnt[k]) {
                        arr[i++][j] = k;
                        arr[i++][j] = cnt[k];
                    }
                }
                max_size = max(max_size, i);
                sort2(j,i,1);

                while(i < MX) arr[i++][j] = 0;
            }
            n = min(max_size, 100);
        }
        sec++;
    }
    cout << (arr[r][c] == k ? sec : -1);
}