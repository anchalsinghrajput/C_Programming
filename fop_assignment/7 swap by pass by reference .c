/*Design a C program to swap two numbers entered by the user. 
Your program must include Input, Swap, and display functions .
Use Pass by reference for swap function.*/

#include<stdio.h>
int input(int count)
{
    int a;
    printf("Enter number %d :\n",count);
    scanf("%d",&a);
    return a;
}
void swap(int *a, int *b)
{
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}
void display(int a, int b)
{
    printf("After swap \n number1 =%d \n number2 =%d \n",a,b);
}
int main()
{
int a,b;
    int count=1;
    a=input(count);
    count++;
    b=input(count);
    swap(&a,&b);
    display(a,b);
    return 0;
}

