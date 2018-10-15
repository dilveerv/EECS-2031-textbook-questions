#include<stdio.h>
#define MAXLINE 1000
#define LIMIT 80

/* Program to print the length of all input lines greater than 80 characters */

/* we call it ngetline, for new getline so that it does not conflict with system function getline */
int ngetline(char line[],int lim);

int main(void)
{
    
  int len; /* Length of the line entered */
  char line[MAXLINE]; /*  */

  while((len=ngetline(line,MAXLINE)) > 0)
  {
    if( len > LIMIT )
      printf("%s",line);
  }

  return 0;
}

int ngetline(char s[],int lim)
{
  int i,c;
  
/* for loop that adds each char to a character array called s. 

Stops when the size limit of s is met which is size-1 because we want to keep room for '\0' 
or 
stops until EOF is reached 
or 
stops when a new line is created*/
    
  for(i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n';++i)
    s[i]=c;

    /* when you press enter */
  if(c == '\n'){
    s[i] = c;
    ++i;
  }
    s[i] = '\0';

  return i;
}