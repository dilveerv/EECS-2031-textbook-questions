#include <stdio.h>

void swap(int *px, int *py);
    
int main(){
    int a = 2;
    int b = 40;
    
    printf("Before: %d, %d\n", a, b);
    swap(&a, &b);
    
    printf("After: %d, %d\n\n", a, b);
    
    printf("%p, %p\n", &a, &b);
    return 0;
}

void swap(int *px, int *py){
    
    int temp;
    temp = *px;
    *px = *py; 
    *py = temp;
}