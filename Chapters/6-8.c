#include <stdio.h>
#include <stdlib.h>

typedef union{
        char *firstName;
        char *lastName;
    }myUnion;
	

int main() {
    
    myUnion mU;
    mU.firstName = "Adam";
    mU.lastName = "Smith";
    
    printf("%s\n", mU.firstName);
    
    /*
	int *p = (int*)malloc(6 * sizeof(int));
	*p = 2;
	*(p+1) = 9;
	*(p+2) = 467;
	*(p+3) = 47;
	*(p+4) = 234;
	*(p+5) = 1;
	printf("%d\n",p[5]);
    */
    
	return 0;
}