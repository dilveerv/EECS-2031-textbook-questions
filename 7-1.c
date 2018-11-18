#include <stdio.h>
#include <ctype.h>

int main() {

    char input[] = "fdsafFDSFDSAFDSdsafdsa";
    char convert[20];
    
    int i;
    for(i = 0; input[i] != '\0'; i++){
        convert[i] = putchar(tolower(input[i]));
        
    }
    putchar('\n');
    
    return 0;
}