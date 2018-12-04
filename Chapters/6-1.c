#include <stdio.h>
#include <ctype.h>
#include <string.h>
    
#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b
#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))
#define MAXWORD 10

struct point {
    int x;
    int y;
};

struct point1{
    int x;
    float y;
    double a;
    long i;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
};

struct rect canonrect(struct rect r){
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    
    return temp;
};

struct{
    int len;
}*p;

struct key {
    char *word;
    int count;
} keytab[] = {"Dilveer", 7};

struct key names[] = {
{"Bob", 3},
{"Tom", 3},
{"Dilveer", 7},
{"Dog", 3},
{"Cat", 3},
{"fdas", 4},
{"cookies", 7}};

int main(int argc, char *argv[])
{   
    printf("%s, %d\n",keytab[0].word, keytab[0].count);
    printf("%s, %d\n",names[0].word, names[0].count);
    
    printf("size of a int: %lu \n", sizeof(int));
    printf("size of a float: %lu \n", sizeof(float));
    printf("size of a double: %lu \n", sizeof(double));
    printf("size of a long: %lu \n \n", sizeof(long));
    
    printf("size of struct key: %lu \n", sizeof(struct key));
    printf("size of struct point1: %lu \n", sizeof(struct point1));
}


