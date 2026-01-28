// https://www.acmicpc.net/problem/19700

// 0. 문제
// 각 학생의 팀내 최대 키순위를 만족하는 최소 팀수를 구하라.

// 1. 풀이
// 키가 작고 순위가 낮은 학생부터 배치
// 배치할 학생을 기존 팀들 중 배치할 수 있는 팀들 중 인원이 가장 많은 팀에 배치
// 배치할 수 있는 팀은 팀 인원이 학생 순위보다 낮은 팀
// 학생을 기존 팀들 중 배치할 수 있는 팀이 없으면 새로운 팀에 배치

// 2. 필요 데이터
// 배치할 수 있는 팀들 중 인원이 가장 많은 팀

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> students;
    for(int i = 0; i < n; i++) {
        int h, k;
        cin >> h >> k;
        students.push_back({h,k});
    }
    sort(students.begin(), students.end(), greater<pair<int, int>>());

    multiset<int, greater<int>> teams; // 오름차순
    for (auto student : students) {
        auto [h,k] = student;
        auto it = teams.upper_bound(k); // (내림차순) 정확히 그 값을 찾고 싶으면 lower_bound, 그 값을 초과하는 첫 원소를 찾으면 upper_bound
        if (it == teams.end()) {
            teams.insert(1);
        }
        else {
            teams.insert(*it + 1);
            teams.erase(it);
        }
    }

    cout << teams.size();
}