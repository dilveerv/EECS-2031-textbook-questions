#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    
    char str[20];
    int test = 22;
    sprintf(str, "%d", test);

    printf("%s\n",str);
    
    return 0;
}