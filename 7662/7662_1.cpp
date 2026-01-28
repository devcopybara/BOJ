// https://www.acmicpc.net/problem/7662

// 0. 문제
// 두 가지 연산이 사용되는데, 하나는 데이터를 삽입하는 연산이고 다른 하나는 데이터를 삭제하는 연산
// 데이터를 삭제하는 연산은 또 두 가지로 구분되는데 하나는 우선순위가 가장 높은 것을 삭제하기 위한 것이고 다른 하나는 우선순위가 가장 낮은 것을 삭제
// 적용될 일련의 연산이 주어질 때 이를 처리한 후 최종적으로 Q에 저장된 데이터 중 최댓값과 최솟값을 출력

// 1. 문제 재정의
// 삽입과 최대값/최솟값 삭제 연산 후, 최대값/최솟값 출력

// 2. 필요한 데이터
// 삽입된 데이터 중 최대값
// 삽입된 데이터 중 최솟값

// 3. 불필요한 데이터
// 삭제된 최대값
// 삭제된 최솟값

// 4. 풀이
// 원소를 삽입하면 정렬하여 최솟값과 최대값을 바로 찾고 삭제.

// 5. 자료구조
// 덱 -> 정렬 삽입 O(N), 최대/최솟값 삭제 O(1), 최대/최솟값 확인 O(1)
// 우선순위큐 -> 정렬 삽입 O(lgN), 최대/최솟값 삭제 O(lgN), 최대/최솟값 확인 O(1) + 삭제 리스트 확인 해쉬 O(1)
// 이진검색트리 -> 정렬 삽입 O(lgN), 최대/최솟값 삭제 O(lgN), 최대/최솟값 확인 O(lgN) 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;

        multiset<int> ms;
        while(k--) {
            char cmd;
            int val;
            cin >> cmd >> val;

            if(cmd == 'I') {
                ms.insert(val);
            }
            else {
                if(ms.empty()) continue;
                if(val == -1) {
                    ms.erase(ms.begin());
                }
                else {
                    ms.erase(prev(ms.end()));
                }
            }
        }

        if(ms.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }

}