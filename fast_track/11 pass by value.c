/*Activity11: Write a program to add two numbers using four functions and only pass by value

Enter numbers a,b : 2 3
output: 2+3 = 5*/

#include<stdio.h>
int  input()
{
  int a;
    printf("Enter a number: \n");
    scanf("%d",&a);
    return a;
}
int sum( int a,int b)
{
  int sum = a+b;
   return sum;
}
void output(int a, int b , int c)
{
    printf("sum of %d+%d is %d \n ", a,b,c);
}
int main()
{
int x,y,z;
x=input();
y=input();
z=sum(x,y);
output(x,y,z);
return 0;
}
