/* Exercise 1.6 - Verify that the expression getchar() != EOF is 0 or 1 */

#include<stdio.h>

int main(int argc, char *argv[]) {
    int c;
    
    /* getchar() reads a single character from the standard input stream stdin */
    while ((c = getchar()) != EOF) {
        printf("%d ", c != EOF);
        putchar(c);
    }
    
    printf("\n%d\n", c != EOF);
}
