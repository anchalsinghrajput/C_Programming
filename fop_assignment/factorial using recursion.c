//Write a program in C to find the factorial of a number entered by the user using recursion.

#include<stdio.h>
int fact(int n)
{
    if(n==0)
        return 1;
    return fact(n-1)*n;
}
int main()
{
    int n;
    printf("Enter the number to get its factorial value :\n");
    scanf("%d",&n);
    printf("%d! = %d",n,fact(n));
    return 0;
}
