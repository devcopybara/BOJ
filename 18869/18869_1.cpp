// https://www.acmicpc.net/problem/18869
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<vector<int>, int> cnt; // 안정성을 위해 map 사용

    for(int i = 0; i < n; i++) {
        vector<int> v(m);
        for(int j = 0; j < m; j++) {
            cin >> v[j];
        }

        // 1. 정렬된 배열 생성
        vector<int> sorted = v;
        sort(sorted.begin(), sorted.end());

        // 2. rank 생성 (중복 고려)
        unordered_map<int,int> rank;
        int r = 0;
        rank[sorted[0]] = 0;

        for(int j = 1; j < m; j++) {
            if(sorted[j] != sorted[j-1]) r++;
            rank[sorted[j]] = r;
        }

        // 3. 원래 순서 기준으로 rank 배열 생성
        vector<int> key(m);
        for(int j = 0; j < m; j++) {
            key[j] = rank[v[j]];
        }

        cnt[key]++;
    }

    // 4. 조합 계산
    long long ans = 0;
    for(auto &val : cnt) {
        long long k = val.second;
        ans += k * (k - 1) / 2;
    }

    cout << ans;
}