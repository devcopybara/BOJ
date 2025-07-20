#include <bits/stdc++.h>
using namespace std;

// 각 원소에 대해서 해당 원소 보다 큰 오른쪽 원소 중 가장 왼쪽에 있는 원소 출력
// 하나의 원소에 대한 오큰수를 찾기 위해서는 오른쪽을 탐색하고 복귀하는 비효율 발생

// 비효율을 개선하기 위해서, 오른쪽에서부터 출발하여 원소들을 오름차순으로 정렬시킨 자료구조를 만들어
// 하나의 원소에 대한 오큰수를 오름차순으로 정렬된 자료구조를 탐색하여 찾고 해당 원소를 자료구조에 삽입

const int MX = 1000002;
int A[MX];
int NGE[MX];
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];

    for(int i = n - 1; i >= 0; i--) {

        while(!S.empty() && S.top() <= A[i]) {
            S.pop();
        }
        if(S.empty()) {
            NGE[i] = -1;
        }
        else {
            NGE[i] = S.top();
        }
        S.push(A[i]);
    }

    for(int i = 0; i < n; i++) cout << NGE[i] << ' ';
}