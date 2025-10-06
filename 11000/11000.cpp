#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
pair<int,int> lec[200005];
priority_queue<int, vector<int>, greater<int>> room;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        lec[i] = {s,t};
    }
    sort(lec,lec+n);
    room.push(lec[0].Y);

    for(int i = 1; i < n; i++) {
        if(lec[i].X >= room.top())
            room.pop();
        room.push(lec[i].Y);
    }
    cout << room.size();
}