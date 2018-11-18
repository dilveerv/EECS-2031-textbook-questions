#include <stdio.h>
#include <stdlib.h>

typedef char String[];

typedef struct boring{
    int number;
    char c;
}boring;

typedef struct smartArray{
    int *array;
    int length;
}smartArray;

smartArray *createSmartArray(int length);

int main() {
    
    String newString = "COOKIES!";
    boring myStruct;
    
    myStruct.number = 10;
    myStruct.c = 'f';
    
    int x = 5;
    int i = 0;
    
    smartArray *myArray = createSmartArray(x);
    
    for(i = 0;i<myArray->length;i++){
        myArray->array[i] = i;
        printf("%d ", myArray->array[i]);
    }
    
    printf("\n");
    printf("%s\n",newString);
    printf("%d, %c\n", myStruct.number, myStruct.c);
    
    return 0;
}

smartArray *createSmartArray(int length){
    
    smartArray *newArray = malloc(sizeof(smartArray));
    
    newArray->length = length;
    newArray->array = malloc(sizeof(int)* length);
    
    return newArray;
}
