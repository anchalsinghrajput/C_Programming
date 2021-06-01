
#include<stdio.h>
float area (float a , float b)
{
float c=a*b;
  return c;
}
int main()
{
float l,b;
 printf("enter the length of the rectangle\n");
 scanf("%f",&l);

 printf("enter the breath of the rectangle\n");
 scanf("%f",&b);

 printf("area of the rectangle is %.1f",area(l,b));
return 0;
}
