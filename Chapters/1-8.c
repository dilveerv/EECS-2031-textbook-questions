#include <stdio.h>
#include <string.h>

/* Exercise 1-8. Write a program to count blanks, tabs, and newline */

int main(){
    
    /* Number of... */
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;
    
    int c;
    
    while((c = getchar()) != EOF){
        if (c == '\n')
            ++newlines;
        if (c == '\t')
            ++tabs;
        if (c == ' ')
            ++blanks;
    }
    
    printf("\n");
    printf("# of blanks: %d \n", blanks);
    printf("# of tabs: %d \n", tabs);
    printf("# of newlines: %d \n", newlines);
    printf("\n");
}
