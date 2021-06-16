/*Design a program that takes three coefficients (a, b, and c) of a Quadratic equation (ax^2+bx+c=0) 
as input and compute all possible roots. 
Implement the program to output the possible roots for the given set of coefficients with appropriate messages shown in the sample output. 
Make sure to write 3 test cases of your own when you submit your PDF.

Test case 1: 
Input the coefficients of a, b, c value are: 2, 6, 2
Output: The roots are real and different. root1=-0.38  root2=-2.62

Test case 2: 
Input the coefficients of a, b, c value are: 2, 4, 2
Output:  The roots are real and equal. root1=root2=-1.00

Test case 3: 
Input the coefficients of a, b, c value are: 2.3, 4, 5.6
Output: The roots are complex.    root1= -0.87+1.30 root2=-0.87-1.30i*/


#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,r1,r2,dis;
    
        printf("Enter the coefficient of  a, b, c :\n");
        scanf("%f%f%f",&a,&b,&c);
        
        dis=(pow(b,2)-(4*a*c));
        
        if(dis==0)
            {
               r1=-b/(2.0*a);
               r2=r1;
               printf("Roots are real and equal.\nroot1=root2=%.2f ",r1);
            }
        else if(dis>0)
            {
                r1=(-b+sqrt(dis))/(2*a);
                r2=(-b-sqrt(dis))/(2*a);
                printf("Roots are real and different.\nroot1=%.2f \t root2=%.2f",r1,r2);
            }
        else
            {
                float real=-b/(2*a);
                float img=sqrt(-dis)/(2*a);
                printf("Root are complex and different.\nroot1=%.2f+%.2fi \t root2=%.2f-%.2fi",real,img,real,img);
            }
    return 0;
}



