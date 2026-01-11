// https://www.acmicpc.net/problem/1725
// 1. 데이터 목록
// 높이,왼쪽 너비,오른쪽 너비
// 2. 데이터 확정 시점
// 높이 : 현재 원소 -> 현재 원소의 높이와 위치 데이터 존재
// 왼쪽 너비 : 현재 원소보다 작은 첫번째 이전 원소 탐색 시점 -> 이전 원소들의 높이와 위치 데이터 필요
// 오른쪽 너비 : 현재 원소보다 작은 첫번째 다음 원소 탐색 시점 -> 다음 원소들의 높이와 위치 데이터 필요
// 3. 데이터 확정 순서
// 즉시 현재 원소의 높이와 왼쪽 너비와 오른쪽 너비를 확정 => O(N^2)
// 현재 원소의 높이와 위치 데이터를 저장하여 이전 원소들의 높이와 위치 데이터를 얻으면, 왼쪽 너비는 당연히 확정할 수 있고, 현재 원소로 오른쪽 너비를 확정할 수 있는 이전 원소들에 대해서만 오른쪽 너비 확정 => O(N)
// 4. 풀이
// 이전 원소들을 통해 왼쪽 너비를 확정하여 저장한 이전 원소들 중 현재 원소보다 큰 오른쪽 너비를 확정할 수 있는 이전 원소들은 현재 원소들은 넓이를 계산하고 현재 원소의 왼쪽 너비를 확정하여 저장한다.
// 이때 현재 원소보다 큰 이전 원소들 쉽게 찾기 위해 오름차순 정렬이 필요하고 현재 원소보다 큰 원소는 제거하는 저장 구조는 스택 구조가 편리하다.
#include <iostream>
using namespace std;
using int64 = long long;
using pii = pair<int,int>;
#define X first
#define Y second
const int MX = 100'005;
pii dat[MX];
int64 pos;
void push(pii x) {dat[pos++]=x;}
void pop() {pos--;};
pii top() {return dat[pos-1];}
bool empty() {return pos==0;}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int64 n;
    cin >> n;
    int64 ans = 0;
    for(int64 i = 0; i < n; i++) {
        int64 h, left = i;
        cin >> h;
        while(!empty()) {
            if(top().X <= h) break;
            left = top().Y;
            ans = max(ans, top().X * (i-left));
            pop();
        }
        if(!empty() && top().X == h) continue;
        push({h,left});
    }
    while(!empty()) {
        ans = max(ans, top().X * (n-top().Y));
        pop();
    }
    cout << ans;
}