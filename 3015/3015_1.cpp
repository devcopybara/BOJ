// https://www.acmicpc.net/problem/3015
// 조건 : A와 B가 볼 수 있으려면, 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다.
// 결과 : 서로 볼 수 있는 쌍의 수를 출력
// 풀이1: 각 A가 볼 수 있는 B들의 총합
// 왼쪽 A 부터 각 A가 볼 수 있는 A의 오른쪽의 있는 B들의 총합
// 왼쪽 A 부터 각 A의 오른쪽의 있는 B들 중 A 보다 큰 첫번째 B까지 단조 증가하는 B들의 총합
// 풀이2: 각 B를 볼 수 있는 A들의 총합
// 

#include <iostream>
using namespace std;

const int MX = 500'005;
int dat[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> dat[i];
    }

    long long ans = 0;
    for(int i = 0; i < n-1; i++) {
        int cnt = 0;
        int h = dat[i+1];
        for(int j = i+1; j < n; j++) {
            if(dat[i] < dat[j]) {
                cnt++;
                break;
            }
            if(h == 0) {
                h = dat[j];
                cnt++;
                continue;
            }
            if(h <= dat[j]) {
                h = dat[j];
                cnt++;
            }
        }
        ans += cnt;
    }
    cout << ans;
}