#include <bits/stdc++.h>

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[9];
    int ans[7];

    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    int sum;
    for(int i = 0; i < 8; i++) {
        sum = 0;
        for(int j = i + 1; j < 9; j++) {
            sum = 0;

            for(int k = 0; k < 9; k++) {
                if(k != i && k != j) {
                    sum += arr[k];
                }
            }

            if(sum == 100) {
                for(int k = 0, l = 0; k < 9; k++) {
                    if(k != i && k != j) {
                        ans[l++] = arr[k];
                    }
                }
                break;
            }
        }

        if(sum == 100) break;
    }
    
    sort(ans, ans + 7);

    for(int i = 0; i < 7; i++) {
        cout << ans[i] << "\n"; 
    }
}