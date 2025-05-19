#include <stdio.h>

int main(void) {
    int arr[9];
    int ans[7];

    for(int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
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
    
    for(int i = 0; i < 7; i++) {
        int k = i;
        for(int j = i + 1; j < 7; j++) {
            if(ans[k] > ans[j]) k = j;
        }

        if(k != i) {
            int tmp = ans[k];
            ans[k] = ans[i];
            ans[i] = tmp;
        }
    }

    for(int i = 0; i < 7; i++) {
        printf("%d\n", ans[i]);
    }
}