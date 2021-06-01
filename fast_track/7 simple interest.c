/*Activity7: Write a program to find simple interest given Principal, Rate of Interest and Time.

SimpleInterest = Principal * Time * RateOfInterest/100.

Input:
Enter Principal = 100
Enter Time = 1 year
Enter Rate of interest = 2

Output:
The simple interest for a principal of 100 Rs over 1year given 2% rate of interest is 2 Rs.*/


#include<stdio.h>
double SI(double p, double t, double r)
{
double si=(p*t*r)/100;
return si;
}
int main()
{
double p,t,r;
double si;
  printf("enter principle :\n ");
  scanf("%lf",&p);
  printf("enter time :\n ");
  scanf("%lf",&t);
  printf("enter rate :\n ");
  scanf("%lf",&r);
  printf("The simple interest for a principal of %.1lf Rs over %.1lf year given %.1lf rate of interest is %.3lf \n", p,t,r,SI(p,t,r));
  return 0;
}

