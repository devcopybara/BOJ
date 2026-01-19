// https://www.acmicpc.net/problem/1202

// 0. 문제
// 각 무게 m_i와 가격 v_i인 보석 n개 중, 각 가방에 담을 수 있는 최대 무게가 c_i인 k개의 가방에 담을 수 있는 보석의 최대 가격을 구한다.

// 1. 재정의
// 각 무게 m_i와 가격 v_i인 보석 n개일 때, 가격이 최대가 되도록 무게가 c_i인 k개의 각 가방에 담을 보석을 선택.

// 2. 풀이
// 제약 조건이 큰 작은 가방부터 시작해서, 무게를 넘지 않은 모든 보석 중 가장 가격이 높은 보석을 가방에 담는다.

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    
    vector<pair<int,int>> jewel;
    for(int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        jewel.push_back({m,v});
    }
    sort(jewel.begin(), jewel.end());

    vector<int> bag;
    for(int i = 0; i < k; i++) {
        int c;
        cin >> c;
        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());

    long long ans = 0;
    priority_queue<int> pq;
    int jCnt = 0;
    for(int c : bag) {
        while(jCnt < n && jewel[jCnt].X <= c) {
            pq.push(jewel[jCnt].Y);
            jCnt++;
        }
        if(!pq.empty()) {
            ans += pq.top(); pq.pop();
        }
    }
    cout << ans;
}