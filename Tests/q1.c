/*  
    Name: Dilveer Virdi
    Student Number: 214332308
*/

#include <stdio.h>

int main()
{
    char firstlast[] = "\"Dilveer Virdi\"";
    int student = 214332308;
    char todaydate[] = "\"October 15, 1900\"";
    
    printf("{\"name\" : %s, \"number\" : \"%d\", ", firstlast, student);
    printf("\"date\" : %s}\n", todaydate);
}


/* 
Question 1 Write a program in ANSI C that prints out

{"name" : "Your name", "number" : "Your student number", "date" : "your date of birth" }

Where if your name was "John Smith", your student number was "12345678" and you were born on October 15, 1900, your code would output

{"name" : "John Smith", "number" : "12345678", "date" : "October 15, 1900" }

Your code should be properly formatted, be written in ANSI C, and have a comment block before the main definition that includes your name and student number.  Call the file q1.c and upload it to 'Practice Lab Test' on the Moodle site
*/
