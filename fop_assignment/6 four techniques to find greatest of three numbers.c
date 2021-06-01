/*Design a C program to find the greatest of 3 numbers entered by the user, using the following strategies. Your program must contain input function, and FOUR other functions with names as mentioned below.
a) findgreat1 - Using if and no else.  
b) findgreat2 - Using nested if.
c) findgreat3 - Using  Ladder if else if 
d) findgreat4 - Using Ternary operator.

Input
Enter 3 numbers: number number number

Output
Greatest of the 3 numbers using the four techniques are: GreatestNum 

GreatestNum  GreatestNum  GreatestNum*/

#include<stdio.h>

void input(int *a, int *b, int *c)
{
    printf("Enter three nums: ");
    scanf("%d %d %d",a, b, c);
}

int findgreat1(int a, int b, int c) // only if no else condition
{
    if(a>b)
    {
        if(a>c)
        return a;
    }
    if(b>c)
        return b;
    return c;
}

int findgreat2(int a, int b, int c) // nested if condition
{
    if(a>b)
    {
        if(a>c)
            return a;
        else
            return c;
    }
    else 
    {
        if (b>c)
            return b;
        else
            return c;
    }

}

int findgreat3(int a, int b, int c)  // ladder if else if condition
{
    if(a>b && a>c)
        return a;
    else if(b>c)
        return b;
    else
        return c;
}
int findgreat4(int a, int b, int c)
{
   int ans = a>b ? (a>c ? a:c) :(b>c ? b:c );   // Ternary operator condition
   return ans;
} 

void output(int a, int b, int c)
{
    printf("Greatest of the 3 numbers using the four techniques are :\n");
    printf("Greatest1 : %d \n", findgreat1(a,b,c));
    printf("Greatest2 : %d \n", findgreat2(a,b,c));
    printf("Greatest3 : %d \n", findgreat3(a,b,c));
    printf("Greatest4 : %d \n", findgreat4(a,b,c));
}
int main()
{
    int a,b,c;
    input(&a, &b, &c);
    output(a,b,c);
    return 0;
}
