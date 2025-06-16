#include <iostream>
using namespace std;

const int MX = 200002;
typedef struct queue_t{
    int dat[MX];
    int head = 0, tail = 0;
    void push(int x) {
        dat[tail++] = x;
    }
    void pop() {
        head++;
    }
    int front() {
        return dat[head];
    }
}queue_t;

int n,k;
int dist[100002];
queue_t Q;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(dist, dist+100001,-1);
    dist[n] = 0;
    Q.push(n);
    while(dist[k] == -1){
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1, cur+1, 2*cur}){
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur]+1;
            Q.push(nxt);
        }        
    }
    cout << dist[k];
}