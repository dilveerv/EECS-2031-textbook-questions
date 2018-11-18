#include <ctype.h>
#include <stdio.h>

#define SIZE 10
int getch(void);
void ungetch(int);

int main(){
    
    int n;
    int s;
    int array[SIZE];
    int getint(int *);

    for(n=0;n<SIZE && getint(&array[n]) !=EOF; n++){
       /* For debug purposes */
       printf("storing in n = %d, getint %d\n", n, array[n]);
    }
    
    printf("storing in n = %d, getint %d\n", n, array[n]);

    for(s=0;s<=n; s++)
        printf("%d",array[s]);

    return 0;
    return 0;
}

/* getint: get next integer from input into *pn Free form input conversion routine */

int getint(int *pn)
{
    int c, sign;
    
    while (isspace(c = getch())) /* skip white space */
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){ 
    ungetch(c);     /* it's not a number */
    return 0; 
    }
    
    sign = (c == '-' ? -1: 1);
    
    if(c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
    
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}