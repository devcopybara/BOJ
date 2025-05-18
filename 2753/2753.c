#include <stdio.h>

int main(void) {
    int year;
    scanf("%d", &year);

    if(year % 4) printf("0");
    else if(year % 100) printf("1");
    else if(year % 400) printf("0");
    else printf("1");
    
    
}