// https://www.acmicpc.net/problem/1781

// 0. 문제
// n개의 각 문제의 데드라인 d_i 시간과 문제를 풀었을 때 받을 수 있는 컵라면 수 c_i가 있고, 한 문제를 풀기 위해 1시간이 걸릴 때, 받을 수 있는 최대 컵라면 수를 구하라

// 1. 재정의
// 각 데드라인 d_i와 컵라면 c_i인 문제 n개가 있고, 1시간에 1개 문제를 풀 수 있을 때, 받을 수 있는 최대 컵라면 수를 구하라
// d시간까지 d개 문제를 풀 수 있을때, 

// 2. 풀이
// 제약 사항이 큰 데드라인 200'000부터 시작해서, 데드라인이 넘지 않는 문제들 중 가장 컵라면이 많은 문제를 푼다.

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    priority_queue<int,vector<int>,greater<int>> pq;
    vector<pii> v;
    
    for(int i = 0; i < n; i++) {
        int d, c;
        cin >> d >> c;
        v.push_back({d,c});
    }
    sort(v.begin(),v.end());
    for(auto [d,c] : v) {
        pq.push(c);
        if(pq.size() > d) {
            pq.pop();
        }
    }
    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}