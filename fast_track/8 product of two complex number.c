/*Activity8: Write a program to multiply two complex numbers.

Input:
Enter real and imaginary part of complex number 1 : 1 1
Enter real and imaginary part of complex number 2 : 1 2
Output:
The product of complex number 1 + 1i and 1 + 2i is  -1+3i
*/


#include<stdio.h>
int main()
{
float a1,a2,b1,b2,p1,p2;
  printf("Enter real and imaginary part of complex number 1 : \n");
  scanf("%f%f ", &a1,&b2);
  printf("Enter real and imaginary part of complex number 2 : \n");
  scanf("%f%f", &a2,&b2);
  
  p1=(a1*a2)-(b1*b2);
  p2=(a2*b2)+(b1*a2);
  
  printf("The product of complex number %.0f + %.0fi  and %.0f + %.0fi is   %.0f+%.0fi  \n ", a1,b1,a2,b2,p1,p2);
  return 0;
}


