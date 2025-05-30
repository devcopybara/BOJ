#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MX = 1000005;
typedef struct node{
    char dat;
    struct node* pre;
    struct node* nxt;
}node;
node nodepool[MX];
int unused;

node password;

void traversal() {
    node* cur = password.nxt;

    while(cur) {
        printf("%c", cur->dat);
        cur = cur->nxt;
    }
}

node* insert(node* addr, char val) {
    node* cur = &nodepool[unused++];

    cur->dat = val;
    cur->pre = addr;
    cur->nxt = addr->nxt;

    if(addr->nxt) addr->nxt->pre = cur;
    addr->nxt = cur;

    return cur;
}

node* erase(node* addr) {
    addr->pre->nxt = addr->nxt;
    if(addr->nxt) addr->nxt->pre = addr->pre;

    return addr->pre;
}

char keylog[MX];
int main(void) {
    int n;
    scanf("%d", &n);

    while(n--) {
        unused = 0;
        password.pre = NULL, password.nxt = NULL;

        scanf("%s", keylog);

        node* cursor = &password;
        for(int i = 0; keylog[i]; i++) {
            switch(keylog[i]) {
                case '<':
                    if(cursor->pre) cursor = cursor->pre;
                    break;
                case '>':
                    if(cursor->nxt) cursor = cursor->nxt;
                    break;
                case '-':
                    if(cursor != &password) cursor = erase(cursor);
                    break;
                default:
                    cursor = insert(cursor, keylog[i]);
                    break;
            }
        }

        traversal();
        printf("\n");
    }
}