#include<stdio.h>
int main()
{
int a[25],n,sum;
float avg;
printf("Enter the number of terms: ") ;
scanf("%d",&n) ;
printf("\nEnter the numbers : \n") ;
for (int i=0;i<n;i++)
{
scanf("%d",&a[i]) ;
}
for (int i=0;i<n;i++)
{
sum=sum+a[i];
}
avg=sum/n;
printf("\nThe average of the entered numbers is : %f ",avg) ;
return ( 0 ) ;
}
