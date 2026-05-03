// https://www.acmicpc.net/problem/1700

// 0. 문제
// 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화

// 1. 정의
// 전기용품의 사용 순서가 주어질 때 플러그를 빼는 최소 횟수

// 2. 풀이
// 현재 멀티탭의 전기용품 중 다음 사용순서가 가장 먼 전기용품을 뽑는다.

// 3. 증명(귀류법)
// 명제 
// : 다음 사용순서가 가장 먼 전기용품 뽑지 않을 경우, 플러그를 빼는 횟수 최소
// 증명 
// : 다음 사용순서가 가장 먼 전기용품A를 뽑지 않고 최소화를 위한 전기용품B를 뽑을 경우
// 전기용품A를 다시 사용하기 전 전기용품B를 먼저 다시 사용하기 위한 순서가 도래한다.
// 전기용품B를 다시 사용하기 위해 무조건 다른 전기용품을 1번더 뽑아야 한다.
// 전기용품A를 뽑았다면 전기용품B를 위해 1번더 뽑지 않았을 것이다.
// 그리고 전기용품A를 뽑는 것이 최소화를 위한 전기용품B를 뽑았던 것을 충분히 대체해도 아무런 문제가 없다.
// 따라서, 명제는 거짓이므로, 기존 풀이는 참이다.

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define X first
#define Y second

const int MX = 105;
int time2app[MX];
queue<int> app2time[MX];

priority_queue<pii> plug;
int plugged[MX];
int pCnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int t = 0; t < k; t++) {
        int app; cin >> app;
        time2app[t] = app;
        app2time[app].push({t});
    }   

    int ans = 0;

    for(int t = 0; t < k; t++) {
        int app = time2app[t];
        app2time[app].pop();

        if(plugged[app] != 1) {
            plugged[app] = 1;

            if(pCnt < n) {
                // 멀티탭에 꽂힌 전기용품이 n개보다 적은 경우, 현재 전기용품을 꽂기만 한다.
                pCnt++;
            }
            else {
                // 멀티탭에 꽂힌 전기용품이 n개인 경우, 꽂힌 것 중 우선순위가 낮을걸 뽑고, 현재 전기용품을 꽂는다.
                ans++;

                auto cur = plug.top(); plug.pop();
                while(plugged[cur.Y] == 0) {
                    cur = plug.top(); plug.pop();
                }
                plugged[cur.Y] = 0;
            }
        }

        // 멀티탭에 전기용품 꽂기
        if(!app2time[app].empty()) plug.push({app2time[app].front(),app});
        else plug.push({MX,app});
    }

    cout << ans;
}