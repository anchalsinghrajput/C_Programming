
/*Write a C Program containing two functions, one display() function and main(),  to get the following output.
Your main() Function should contain one variable of datatype int to store your age, pass the variable as a parameter to the display function, which will print this value and other information as well.
 
Hello World!
YOUR_NAME
YOUR_USN
My current Age is: YOUR_AGE */

#include <stdio.h>
int display(int a);
int main()
{
    printf("Hello world!\nAnchal singh\nENG20CS0030\nMy current age is:");
    display(19);
    return 0;
}
int display(int a)
{ 
   printf(" %d",a);
   return 0;
}
/*
Question/Answer:

Q1) What does backslash n (\n) do?
Ans: It adds a new line in the text at the point wherever \n is present.

Q2)What is %d ?
Ans: It is a format specifier which specifies the type of variable as decimal.

Q3) Write the syntax for function declaration.
Ans: return_type function_name ( parameter list)
                           (or)
        return_type function_name ( datatype argument_name)

Q4) What is printf()?
Ans: printf() is a library function (predefined built-in function) to display the formatted output onto the screen.*/
