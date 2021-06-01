/*Write a program to find the greatest of three numbers. Your program should contain separate input, FindGreat, output functions apart from the main() function.


input function - Accepts and returns the user inputs to main().
FindGreat function - Finds and returns the greatest of the three numbers.
output function - Prints the value sent to it*/



#include<stdio.h>
int input(int a)
{
    scanf("%d",&a);
    return a;
}
int find_great( int a, int b, int c)
{
  if(a>=b)
    {
      if(a>=c)
      return a;
      else
      return c;
    }
  else
   {
      if(b>=c)
      return b;
      else
      return c;
   }
}
void output(int a, int b, int c, int d)
{
    printf(" largest of %d %d and %d is : %d \n ",a,b,c,d);
}
int main()
{
int a, b,c ;
    printf("enter three number :\n ");
  
    a=input(a);
    b=input(b);
    c=input(c);
    output(a,b,c,find_great(a,b,c));
return 0;
}
