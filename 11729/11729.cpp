// https://www.acmicpc.net/problem/11729

#include <stdio.h>

void PrintEachHanoiMoves(int num, int prev, int curr, int next)
{
    if(num == 1)
    {
        printf("%d %d\n", prev, curr);
        return;
    }

    PrintEachHanoiMoves(num - 1, prev, next, curr);

    PrintEachHanoiMoves(1, prev, curr, next);

    PrintEachHanoiMoves(num - 1, next, curr, prev);
}

int Hanoi(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return Hanoi(n - 1) * 2 + 1;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    printf("%d\n", Hanoi(N));
    PrintEachHanoiMoves(N, 1, 3, 2);

    return 0;
}