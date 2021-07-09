//power using loop

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


float power(int b, int p)
{
    float r=1;
    
    if(p>0)
    {
        while(p!=0)
        {
            r=r*b;
            p--;
        }
        return r;
    }
    else if(p==0){
        return 1;
    }
    
    if(p<0){
        while(p<0){
            r=r/b;
            p++;
        }
        printf("%.5f\n",r);
        return r;
    }
}


int main()
{
    int b,e;
    float r;
    
    printf("Enter the base and the exponent:\n");
    scanf("%d%d",&b,&e);
    
    if(e >= 0)
        printf("%d raised to the power %d gives: %.2f",b,e,power(b,e));
    else
        printf("%d raised to the power %d gives: %.5f",b,e,power(b,e));

    return 0;
}


 //Write a program to calculate Power n, of a base number b, both entered by the user using recursion.
 
 #include<stdio.h>
 
 double power(int b, int e)
 {
    if(e==0)
        return 1;
    else
        return power(b,e-1)*b;
 }
 
 int main()
 {
    int b ,e ;
    printf("Enter the base : ");
    scanf("%d",&b);
    printf("\nEnter the exponent : ");
    scanf("%d",&e);
    
    printf("\n%d to the power %d is %.2lf",b,e,power(b,e));
    
    return 0;
 }
 
