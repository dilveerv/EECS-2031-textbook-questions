#include <stdio.h>

/*print Fahrenheit-Celsius table for fahr=0,20,...,300; floatinq-point version*/

/*print the corresponding Celsisus to fahrenheit table*/

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temp table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    
    float c[20];
    float f[20];
    int counter = 0;
    int k;
    
    printf("Fahrenheit-Celsius Table\n");
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0); /*convert*/
        c[counter] = celsius;
        f[counter] = fahr;
        printf("%3.0f %6.1f\n", fahr, celsius);
        counter++;
        fahr = fahr + step;
    }
    
    printf("\n");
    
    printf("Celsius-Fahrenheit Table\n");
    for(k = 0; k < 16; k++){
        printf("%5.1f %4.0f\n", c[k], f[k]);
    }
    return 123;
}