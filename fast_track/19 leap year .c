/*Activity19: Write a program with four functions to determine if given year is a leap year or not.

Input: 2000 
Output: leap year 
Input: 2100
Output: not a leap year
Input: 2004
Output: leap year
Input: 2005
Output: not a leap year*/

#include<stdio.h>
int input()
{
    int yr;
      printf("Enter the year:");
      scanf("%d",&yr);
      return yr;
}
int leap(int yr)
{
    int flag=0;
      if(yr%4==0 && yr%100!=0 && yr%400==0)
      flag=1;
      return flag;
    
}
int output(int flag)
{
      if(flag==1)
      printf("It is an leap year\n");
      else
      printf("It is not an leap year\n");
}
int main()
{
    int year,a;
      year=input();
      a=leap(year);
      output(a);
      return 0;
    
}


