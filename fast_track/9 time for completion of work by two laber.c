/*Activity9: Write a program to compute the time for completion of the work by two workers given individual times to complete work.
Input:
Time to complete work by worker1 in minutes:  40 
Time to complete work by worker 2 in minutes: 60
Output:
The time to complete the work will by both of the worker working together is */


#include<stdio.h>
#include<math.h>

double time (float a,float b)
{
float w;
  w=(1/a)+(1/b);
  return (1/w);
}
int main()
{
double a, b;
  
  printf("\n Time to complete work by worker1 in minutes:  ");
  scanf("%f",&a);
  printf("\n Time to complete work by worker 2 in minutes: ");
  scanf("%f", &b);
  
  printf("\n The time to complete the work will by both of the worker working together is : %.1f", time(a,b));
  return 0;
}

