#include <stdio.h>

int strcmp(const char* s1, const char* s2) {
    while(*s1 && (*s1 == *s2)) s1++, s2++;
    return (*s1 - *s2);
}

const int MX = 2000005;
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
int empty() {
    return head == tail;
}
int back() {
    return dat[tail-1];
}
int front() {
    return dat[head];
}
int main(void) {    
    int n;
    scanf("%d", &n);
    while(n--) {
        char s[6];
        scanf("%s", s);
        if(strcmp(s, "push") == 0) {
            int m;
            scanf("%d", &m);
            push(m);
        }
        else if(strcmp(s, "pop") == 0) {
            if(empty()) printf("-1\n");
            else {
                printf("%d\n", front());
                pop();
            }
        }
        else if(strcmp(s, "size") == 0) printf("%d\n", size());
        else if(strcmp(s, "empty") == 0) printf("%d\n", empty());
        else if(strcmp(s, "back") == 0) {
            if(empty()) printf("-1\n");
            else printf("%d\n", back());
        }
        else if(strcmp(s, "front") == 0) {
            if(empty()) printf("-1\n");
            else printf("%d\n", front());
        }
    }
}