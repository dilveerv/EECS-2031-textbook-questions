#include <stdio.h>
#include <ctype.h>

int main() {
    char string[] = "hello, world";
    
    printf("%s\n",string);
    
    /* Padded from the left */
    printf("%13s\n",string);
    
    /* Total length of string */
    printf("%.5s\n",string);
    
    float x = 234.13425;
    printf("%.4f\n",x);
    
    int y = 143242;
    printf("%.1d\n",y);
    
    int c;

    printf(string);
    
    return 0;
}

