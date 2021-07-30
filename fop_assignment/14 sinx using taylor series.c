//Write a program using functions to compute the sine of a value using Taylor's series approximation - pass by value.

#include<stdio.h>
#include<math.h>
float compute(float x)
{
    int i=2;
    float n=x,d=1,term,sum=0;
    while(i!=20)
    {
        term=n/d;
        sum+=term;
        n=-n*x*x;
        d=d*i*(i+1);
        i+=2;
    }
    return sum;
}

int main()
{
    float x,sinx;
    printf("Enter angle in radian : ");
    scanf("%f",&x);
    sinx=compute(x);
    printf("\nThe value of sin(%.2f radian) = sin(%.1f°) =  %f",x,(x*(180/3.14)),sinx);
    return 0;
}

