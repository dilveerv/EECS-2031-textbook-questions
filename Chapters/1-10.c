#include<stdio.h>

/* Write a Program to copy its input to its output, replacing each tab by \t,each backspace by \b, and each backslash by \\.
This makes tabs and backspaces visible in an unambiguous way. */

int main(void)
{
  int c;

  while((c=getchar())!=EOF)
  {
    if(c=='\t')
    {
      putchar('\\');
      putchar('t');
    }

    if(c=='\b')
    {
      putchar('\\');
      putchar('b');
    }

    if(c=='\\')
    {
      putchar('\\');
      putchar('\\');
    }
      
    if(c!='\t' && c!='\b' && c!='\\'){
        putchar(c);
    }
      
  }
    
return 0;
}