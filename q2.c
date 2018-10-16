/*
Dilveer Virdi
214332308
*/
#include <stdio.h>

int isMirroredint(int x);
int isMirrored(char str[]);
int size(char s[]);
void inttochar(char s[],int x, int length);
int countDigits(int y);


int main()
{   
    printf("%d\n",isMirroredint(1001));
    printf("%d\n",isMirrored("1234321"));
    printf("%d\n",size("1234321"));
    printf("%d\n",countDigits(1001));
}

int isMirroredint(int x){
    int n = x;
    int reversedInteger = 0;
    int remainder, originalInteger;

    originalInteger = x;

    // reversed integer is stored in variable 
    while( n!=0 )
    {
        remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }

    // palindrome if orignalInteger and reversedInteger are equal
    if (originalInteger == reversedInteger)
        return 1;
    else
        return 0;
}

int isMirrored(char str[]){

    int length = size(str);
    
    for(int j = 0; j < length; ++j){
        if(str[j] + 1 != str[j + 1]){
            if(str[j] - 1 != str[j + 1]){
                if(str[j + 1] == '\0'){
                    return  1;
                }else{
                    return 0;
                }
            }
        }
    }
    
    return 0;
}

int size(char s[]){
    int length = 0;
    
    for(int j=0; j<100; ++j){
        if(s[j] == '\0'){
            length = j;
            break;   
        }
    }
    return length;
}


void inttochar(char s[],int x, int length){
    
    int temp;
    for(int k = 0; k < length; ++k){
        
        temp = x;
        for(int l=1; l<length-k; ++l){
            temp /= 10;
        }
        printf("%d\n",temp);
        s[k] = temp;
    }
    
}

int countDigits(int y){
    int length = 0;
     while(y != 0)
    {
        length++;
        y /= 10;
    }
    return length;
}



/* 
Question 2 [20 marks] 

A decimal number can be said to be mirrored if it reads the same forwards and backwards.

That is, the number 12321 is mirrored while 123 is not.

Write a function int isMirrored(int x) that returns 1 if x is mirrored and 0 if it is not. 

Be very careful with numbers like 0 and 10.
0 is mirrored, 10 is not.Write a testing harness to test your function
You may assume that your code will not be called with a negative number.

Your code should be properly formatted, be written in ANSI C, and have a comment block before the main definition that includes your name and student number.  Call the file q1.c and upload it to 'Practice Lab Test' on the Moodle site.

Note: The practice site will only let you have one file at a time, so you will end up overwriting any other file you have submitted.
*/