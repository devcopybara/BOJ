// https://www.acmicpc.net/problem/3015
// 조건 : 
// A와 B가 볼 수 있으려면, A 와 B 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다.
// 결과 : 
// 서로 볼 수 있는 쌍의 수를 출력
// 풀이 : 
// 이 문제의 대전제인 "a와 b가 볼 수 있으려면, 사이에 a 또는 b보다 키가 큰 사람이 없어야 한다."에 의해 
// 각각의 원소b의 왼쪽A와 오른쪽C에서 b가 볼 수 있는 X와 Y를 수를 구하면, 중복이 발생하므로 X만 구한다. 
// X는 b-1부터 시작해서 b보다 큰 첫번째 a 하나까지의 A의 원소들 중 중복 허용 단조 감소하는 원소들이다. 
// 그리고 다음 b'의 X'는 X에 b보다 작은 원소 버리고 b를 추가하면 된다. (DP) 
// 이렇게 이전 데이터를 활용하면서 중복 허용 단조 감소 원소들 중 b보다 작은 원소만 버리고 b를 추가하면 되는 자료구조는 stack을 이용하면 된다. 
// 구현 : 
// 중복 허용 단조 감소 스택 S로 현재 원소 b가 볼 수 있는 원소의 수를 계산하고, 
// 이 성질을 유지한 채로 b를 추가한 스택 S'를 다음 원소 b'가 볼 수 있는 원소의 수를 계산하는데 이용한다. 
// 여기서 스택에서 b가 볼 수 있는 원소의 수를 계산하는 방법은
//  b가 볼 수 있는 원소는, b보다 작은 크기 원소들과 b와 같은 크기 원소들과 b보다 큰 원소 1개까지 구해야하므로,
// S를 b보다 큰 원소 1개까지 뽑았다가 다시 채워야하지만, 이렇게 동작하면 계산 과정에서 overhead가 크므로, 
// 각 원소의 크기마다 연속된 원소의 개수를 {h, cnt} 같이 저장시켜서, 
// S를 while문으로 h[b]보다 작은 원소들은 pop()하여 cnt를 ans에 누적하고 
// empty()거나 h[b]보다 크거나 같은 원소를 만나면 while을 종료하여, 
// h[b]와 같은 크기의 원소에 대해서는 한번더 pop()하여 cnt를 ans에 누적하고, 
// h[b]보다 큰 원소가 있는지에 따라 ans에 1을 누적해야 하므로 S에 원소가 empty인지 확인해서 empty가 아니면 ans에 1을 누적하고, 
// 최종적으로 {h[b], cnt+1}을 push()한다.

#include <iostream>
using namespace std;

using pii = pair<int,int>;
#define X first
#define Y second

const int MX = 500'005;
pii dat[MX];
int pos;

void push(pii val) {dat[pos++] = val;}
void pop() {--pos;}
int size() {return pos;}
pii top() {return dat[pos-1];}
int empty() {return (pos == 0);}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long ans = 0;
    while(n--) {
        int x, cnt = 1;
        cin >> x;
        
        while(!empty()) {
            if(top().X >= x) break;
            ans += top().Y;
            pop();
        }
        if(!empty() && top().X == x) {
            cnt += top().Y;
            ans += top().Y;
            pop();
        }
        if(!empty()) ans += 1;
        push({x,cnt});
    }
    cout << ans;
}