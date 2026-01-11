// https://www.acmicpc.net/problem/11003

// 조건 :
// D_i = A_i-L+1 ~ A_i 중의 최솟값
// i ≤ 0 인 A_i는 무시하고 D를 구한다.

// 결과 :
// D_i를 순서대로 출력

// 풀이1 : 
// 각각의 원소에서 현재 원소 A_i부터 이전 원소 A_i-L+1까지 모든 원소들을 비교하여 그 중에 최소값인 원소 D_i를 구한다.

// 풀이1 필요/불필요한 데이터 :
// 1. 현재 원소 A_i [필요]
// 2. 현재 원소 A_i부터 이전 원소 A_i-L+1까지 모든 원소들 [필요]
// 3. 현재 원소 A_i와 이전 원소 A_i-L+1까지 모든 원소들을 중에 최소값인 원소 D_i [필요]
// 4. 이전 원소 A_i-L부터 이전 모든 원소들 [불필요]

// 풀이1 데이터 획득/제거 시점 :
// 1. 현재 원소 A_i : 현재 원소의 A_i값과 i위치 입력 시 [획득1]
// 2. 현재 원소 A_i부터 이전 원소 A_i-L+1까지 모든 원소들 : 현재 원소의 A_i값과 i위치 입력 시 저장 -> i위치부터 i-L+1위치까지의 원소들 탐색 시 [획득2]+[제거4]
// 3. 현재 원소 A_i부터 이전 원소 A_i-L+1까지 모든 원소들을 비교하여 그 중에 최소값인 원소 D_i : i위치부터 i-L+1위치까지의 원소들 탐색 시 비교 -> 최소값 추출 시 [획득3]

// 풀이2 필요/불필요한 데이터 :
// 1. 현재 원소 A_i [필요]
// 2. 현재 원소 A_i보다 작은 A_i-L+1까지 이전 원소들 [필요]
// 3. 현재 원소 A_i와 이전 원소 A_i-L+1까지 모든 원소들의 최소값 D_i [필요]
// 4. 이전 원소 A_i-L부터 이전 모든 원소들 [불필요]
// 5. 현재 원소 A_i보다 큰 이전 모든 원소들 [불필요]

// 풀이2 데이터 획득/제거 시점 :
// 1. 현재 원소 A_i : 현재 원소의 A_i값과 i위치 입력 시 [획득1]
// 2. 현재 원소 A_i보다 작은 A_i-L+1까지 이전 원소들 : 현재 원소의 A_i값과 i위치 입력 시 -> A_i값보다 큰 저장된 이전 원소들 제거 시 [획득2]+[제거5]
// 3. 현재 원소 A_i와 저장된 현재 원소 A_i보다 작은 A_i-L+1까지 이전 원소들의 최소값 D_i : 
// 현재 원소의 A_i값과 i위치 입력 시 -> A_i값보다 큰 저장된 이전 원소들 제거 시 
// -> 현재 원소 A_i와 저장된 현재 원소 A_i보다 작은 이전 원소들 정렬 
// -> 저장된 원소들의 최소값의 위치가 i부터 i-L+1까지면 D_i로 확정하고 그 외 위치면 제거 [획득3]+[제거4]

// 핵심 원리 :
// 1. 문제 정의
// 2. 필요/불필요 데이터 정의
// 3. 필요/불필요 데이터 획득/제거 시점 정의
// 4. 1~3 과정 구체화 및 세분화하여 재정의

#include <iostream>
using namespace std;

using pii = pair<int,int>;
#define X first
#define Y second

const int MX = 5'000'005;
pii dat[MX + 1];
int head = MX, tail = MX;
void push_front(pii x) {dat[--head]=x;}
//void push_back(pii x) {dat[tail++]=x;}
void pop_front() {head++;}
void pop_back() {tail--;}
pii front() {return dat[head];}
pii back() {return dat[tail-1];}
bool empty() {return head==tail;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        while(!empty()) {
            if(front().X < a) break;
            pop_front();
        }

        push_front({a,i});
        
        while(!empty()) {
            if(back().Y >= i-l+1) break;
            pop_back();
        }

        // 최소값 확정
        cout << back().X << ' ';
    }
}