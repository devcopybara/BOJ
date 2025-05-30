#include <stdio.h>

typedef struct node{
    int dat;
    struct node* pre;
    struct node* nxt;
}node;
const int MX = 5005; 
node nodepool[MX];
int unused;

node* insert(node* addr, int val) {
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

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    node head = nodepool[unused++];
    node* rear = &head;
    for(int i = 1; i <= n; i++) rear = insert(rear, i);
    
    int cnt = k;
    node* cur = &head;
    
    printf("<");
    while(head.nxt) {
        cnt--;
        if(cur->nxt) cur = cur->nxt;
        else cur = head.nxt;
        
        if(cnt == 0) {
            printf("%d", cur->dat);
            
            cnt = k;
            cur = erase(cur);
            
            if(head.nxt) printf(", ");
            else break;
        }
    }
    printf(">");
}