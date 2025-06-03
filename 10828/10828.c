#include <stdio.h>

int strcmp(const char* s1, const char* s2) {
    while(*s1 && *s1 == *s2) s1++, s2++;
    return *s1 - *s2;
}

const int MX = 10005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    --pos;
}

int size() {
    return pos;
}

int empty() {
    return pos == 0;
}

int top() {
    return dat[pos-1];
}

int main(void) {
    int n, m;
    char s[6];

    scanf("%d", &n);
    while(n--) {
        scanf("%s", s);
        if(strcmp(s, "push") == 0) {
            scanf("%d", &m);
            push(m);
        }
        else if(strcmp(s, "pop") == 0) {
            if(empty()) printf("-1\n");
            else {
                printf("%d\n", top());
                pop();
            }
        }
        else if(strcmp(s, "size") == 0) printf("%d\n", size());
        else if(strcmp(s, "empty") == 0) printf("%d\n", empty());
        else if(strcmp(s, "top") == 0) {
            if(empty()) printf("-1\n");
            else printf("%d\n", top());
        }
    }
}