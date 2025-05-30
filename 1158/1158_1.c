#include <stdio.h>

typedef struct node{
    int dat;
    struct node* pre;
    struct node* nxt;
}node;
const int MX = 5005; 
node nodepool[MX];
int unused = 1;

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

node head, tail;
node* pop_front() {
    if(!head.nxt) return NULL;
    
    node* addr = head.nxt;
    addr->pre->nxt = addr->nxt;
    if(addr->nxt) addr->nxt->pre = addr->pre;
    return addr;
}

node* push_back(node* cur) {
    if(!tail.pre) return NULL;

    node* addr = tail.pre;

    cur->pre = addr;
    cur->nxt = addr->nxt;

    if(addr->nxt) addr->nxt->pre = cur;
    addr->nxt = cur;

    return cur;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    
    node* rear = &head;
    for(int i = 1; i <= n; i++) rear = insert(rear, i);
    rear->nxt = &tail, tail.pre = rear;
    
    printf("<");
    while(head.nxt != &tail) {
        for(int i = 0; i < k - 1; i++) {
            push_back(pop_front());
        }
        
        printf("%d", pop_front()->dat);
        
        if(head.nxt != &tail) printf(", ");
        else break;
    }
    printf(">");
}