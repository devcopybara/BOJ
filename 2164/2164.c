#include <stdio.h>

const int MX = 1000005;
int dat[MX];
int head, tail;

void push(int x) {
    dat[tail++] = x;
}
void pop() {
    head++;
}
int size() {
    return tail - head;
}
int front() {
    return dat[head];
}
int back() {
    return dat[tail-1];
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) push(i);

    int ord = 0;
    while(size() > 1) {
        if(ord) push(front());
        pop();
        ord ^= 1;
    }
    printf("%d\n", front());
}