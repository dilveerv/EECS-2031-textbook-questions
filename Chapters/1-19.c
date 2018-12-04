#include <stdio.h>
#define MAX 100

void reverse(char s[]);
int length(char s[]);


int main(){
    
    int c;
    char input[MAX];
    
    for(int k=0;(c=getchar()) != EOF && k < 100;++k){
        if(c == '\n'){
            input[k] = '\0';
            break;
        }else
            input[k] = c;
    }
    
    printf("Before reverse: %s\n", input);
    reverse(input);
    printf("After reverse: %s\n", input);
}



int length(char s[]){
    int length = 0;
    
    for(int j=0; j<MAX; ++j){
        if(s[j] == '\0'){
            length = j;
            break;   
        }
    }
    return length;
}

void reverse(char s[]){
    char r[MAX];
    
    int len = length(s);
    
    int index = len - 1;
    
    for(int l=0; l<len; ++l){
        if(s[index-l] == '\0'){
            r[l] = '\0';
            break;
        }else
            r[l] = s[index-l];
    }
    
    for(int h=0; h<len; ++h){
        s[h] = r[h];
    }
}