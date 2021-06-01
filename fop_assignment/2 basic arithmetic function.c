/*Activity 2
Write a program using C language for simulating Basic arithmetic functions of a calculator for two integers accepted from the user. 

Your program should contain the following functions:

add,sub,mul,div,display.

*/
#include<stdio.h>
int add(int a , int b)
{
    int sum= a+b;
    return sum;

}
int subtract(int a , int b)
{
    int sub=a-b;
    return sub;
}
int multiply(int a , int b)
{
    int mul=a*b;
    return mul;
}
int division(int a, int b)
{
    float d = a/b;
    return d;
}
void display(int num)
{
    printf("%d\n",num);
}
int main()
{
    int a,b;
    printf(" enter a\n ");
    scanf("%d",&a);
    printf("enter b\n");
    scanf("%d",&b)
      ;
    printf(" \n sum of %d and %d is ",a,b);
    display(add(a,b));
  
    printf(" \n subtract of %d and %d is ",a,b);
    display(subtract(a,b));
  
    printf(" \n multiplication  of %d and %d is ",a,b);
    display(multiply(a,b));
  
    printf(" \n division of %d and %d is ",a,b);
    display(division(a,b))
return 0;
}
