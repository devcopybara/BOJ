#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[100005];

typedef struct node{
    char dat;
    struct node* pre;
    struct node* nxt;
}node;

node head = {-1, NULL, NULL};

void traversal() {
    node* cur = head.nxt;

    while(cur) {
        printf("%c", cur->dat);
        cur = cur->nxt;
        free(cur->pre);
    }
}

node* insert(node* addr, char val) {
    node* cur = (node*)malloc(sizeof(node));
    
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

    free(addr);

    return addr->pre;
}

int main(void) {
    node* cur = &head;

    scanf("%s", s);
    for(int i = 0; s[i]; i++) cur = insert(cur, s[i]);

    int n;
    scanf("%d", &n);
    getchar();

    while(n--) {
        char cmd;
        scanf("%c", &cmd);
        getchar();
        
        switch(cmd) {
            case 'L':
                if(cur->pre) cur = cur->pre;
                break;
            case 'D':
                if(cur->nxt) cur = cur->nxt;
                break;
            case 'B':
                if(cur != &head) cur = erase(cur);
                break;
            case 'P':
            default:
                scanf("%c", &cmd);
                getchar();
                cur = insert(cur, cmd);
                break;
        }
    }

    traversal();
}