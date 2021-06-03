/*Activity 22: Write a program with four functions to add two complex numbers. Use appropriate structure(s).
input complex number 1 and complex number 2: 1 1 2 2
The sum of 1 + 1i and 2 + 2i is 3 + 3i.*/

#include<stdio.h>
struct complex {
    float r;
    float i;
};
typedef struct complex c;
c input()
{ 
    c a;
    printf("enter real and imaginary number:\n");
    scanf("%f%f",&a.r,&a.i);
    return a;
}
float realsum(c a, c b)
{
    float rs;
    rs=a.r+b.r;
    return rs;
}
float imgsum(c a, c b)
{
    float is;
    is=a.i+b.i;
    return is;
}
void output(c a,c b, float rs,float is)
{
    printf("the sum of %.1f+%.1fi and %.1f+%.1fi is %.1f+%.1fi ",a.r,a.i,b.r,b.i,rs,is);
}
int main()
{
    c a,b;
    float rs,is;
    a=input();
    b=input();
    rs=realsum(a,b);
    is=imgsum(a,b);
    output(a,b,rs,is);
    return 0;
}
