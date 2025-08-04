#include <bits/stdc++.h>
using namespace std;

void printHanoiMove(int n, int src, int dst, int nxt)
{
    if(n == 1) {
        cout << src << ' ' << dst << '\n';
        return;
    }
    printHanoiMove(n - 1, src, nxt, dst); // move all plate from src to nxt accept the largest plate
    printHanoiMove(1, src, dst, nxt);  // move the largest plate from src to dst
    printHanoiMove(n - 1, nxt, dst, src); // move all plate from nxt to dst accept the largest plate
}

int hanoi(int n)
{
    // if(n == 1) return 1;
    // return hanoi(n - 1) * 2 + 1;
    return (1 << n) - 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << hanoi(n) << '\n';
    printHanoiMove(n, 1, 3, 2);
}