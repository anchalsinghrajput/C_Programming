/*Design a C program to find the simple interest by accepting integers p (principal), t(time), r (rate). Your program should use the below concepts
[Integer division issues (data loss), Explicit typecasting, when p, t, r are integers and SI is float.]


Input:
Enter Principal:
Enter Time in years:
Enter rate%:


output:
The simple interest accumulated is:*/

#include<stdio.h>
int main()
{
    int p,t,r;
    float si;
  
        printf("Enter Principle :\n");
        scanf("%d",&p);
  
        printf("Enter times in years :\n");
        scanf("%d",&t);
  
        printf("Enter rate%%:\n");
        scanf("%d",&r);
  
        si=(float)(p*r*t)/100;  //explicit typecasting
  
        printf("The Simple interest acumulated is : %.2f",si); 
  
    return 0;
}
