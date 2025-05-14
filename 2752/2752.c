#include <stdio.h>

#define MAX(a,b,c) (a>=b && a>=c?a:b>=a && b>=c?b:c)
#define MIN(a,b,c) (a<=b && a<=c?a:b<=a && b<=c?b:c)

int main(){
    int a, b, c;
    int d, e, f;

    scanf("%d %d %d",&a,&b,&c);

    d = MIN(a,b,c);
    f = MAX(a,b,c);
    e = a+b+c-d-f;

    printf("%d %d %d",d,e,f);
    
    
}