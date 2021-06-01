/*Activity5: Write a program to calculate the distance given initial velocity, acceleration, and time.

s = ut + ½at2



Input:
Enter velocity: 2
Enter acceleration: 3
Enter time = 2

Output:
The distance in time 2 is 10 m..*/

#include<stdio.h>
int main()
{
int s=0,u,t,a;
    printf("enter velocity , acceleration and time\n");
    scanf("%d%d%d",&u,&a,&t); 
    
    s=(u*t)+(a*t*t)/2;
    
    printf(" The distance in time %d is %d" , t,s);
    return 0;
}
