/*Design a C program to Convert Celsius to Fahrenheit and vice versa, The input entered must converted based on the choice entered by the user. Choice and the entered input is sent to the Convert function to return the converted value to be printed in main().

Input:
Press 1 to Convert Celsius to Fahrenheit
Press 2 to Convert Fahrenheit to Celsius
Enter choice:
Enter temperature in (mention chosen parameter here) :

output:
The temperature converted to (mention chosen parameter here) is :*/

#include<stdio.h>
int choice(int i)
{ 
    printf("Press 1 to Convert Celsius to Fahrenheit.\n");
    printf("Press 2 to Convert Fahrenheit to Celsius.\n");
  
    printf("Enter choice : ");
    scanf("%d",&i);
  
    return i;
}
float input(float a)
{
    int i;
     if (i==1)
    {
        printf("\n Enter temperature in Celsius : ");
        scanf("%f",&a);
        
    }
     else if(i==2)
    {
        printf("\n Enter temperature in Fahrenheit : ");
        scanf("%f",&a);
       
    }
    else 
    printf("Invalid choice");
    return a;
}

float conversion(float a)
{  
   int i;
    if(i==1)
      {
      a=(a*9/5)+32;
      }
    else 
      {
      a=(a-32)*5/9;
      }
    return a;
}
int main()
{
    int i;
    float a,ans;
  
    i=choice(i);
    a=input(a);
    ans=conversion(a);
  
    if (i==1)
      {
        printf("\nThe temperature converted to Fahrenheit is : %.2f",ans);
      }
    else if(i==2)
      {
        printf("\nThe temperature converted to Celsius is : %.2f",ans);
      }
  
return 0;    
}
