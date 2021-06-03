/*Activity22: Write a program using four functions to divide two complex numbers. Use appropriate structures. 
Input: 
4 2
2 1
Output:
( 4 + 2i ) / ( 2 + 1i) is */

#include<stdio.h>
#include<math.h>
struct complex{
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
float realcal(c a , c b)
{
    float real;
    real=((a.r*b.r)+(a.i*b.i))/(pow(b.r,2)+pow(b.i,2));
    return real;
}
float imgcal(c a , c b)
{
    float img;
    img=((b.r*a.i)-(a.r*b.i))/(pow(b.r,2)+pow(b.i,2));
    return img;
}
void output(c a, c b, float real, float img)
{
    if (img==0)
    printf("(%.1f+%.1fi) and (%.1f+%.1fi) is %.2f  ",a.r,a.i,b.r,b.i,real);
    else
    printf("(%.1f+%.1fi) and (%.1f+%.1fi) is %.2f+%.2fi  ",a.r,a.i,b.r,b.i,real,img);
}
int main()
{
    c a,b;
    float real,img;
    a=input();
    b=input();
    real=realcal(a,b);
    img=imgcal(a,b);
    output(a,b,real,img);
    return 0;
}







#include<stdio.h>
struct complex
{
  float r;
  float i;
};
typedef struct complex Comp;
Comp input()
{
    Comp c;
    printf("Enter the real and imaginary coefficients:\n");
    scanf("%f%f",&c.r,&c.i);
    return c;
}
Comp divide(Comp a,Comp b)
{
    Comp d;
    d.r=(a.r*b.r+(a.i*b.i))/(b.r*b.r+b.i*b.i);
    d.i=(a.i*b.r-a.r*b.i)/(b.r*b.r+b.i*b.i);
    return d;
}
void display(Comp a,Comp b,Comp d)
{
    printf(" (%.1f+%.1fi)/(%.1f+%.1fi) is (%.1f+%.1fi)",a.r,a.i,b.r,b.i,d.r,d.i);
}
int main()
{
    Comp a,b,c;
    a=input();
    b=input();
    c=divide(a,b);
    display(a,b,c);
    return 0;
}

    
