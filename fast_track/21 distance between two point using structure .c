/*Write a program with four functions to find the distance between two points. Use appropriate structures. 

Input: 
2 1
3 1
Output: 
The distance between points (2,1) and ( 3,1) is 1.00*/


#include<stdio.h>
#include<math.h>
struct points
{
    float x,y;
};
struct points input(int x)
{
   struct points a;
    printf("Enter point x%d and y%d :\n",x,x);
    scanf("%f %f",&a.x,&a.y);
    return a;
   
}
float distance(struct points a , struct points b)
{
    float d;
      d=sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
      return d;
}
void output(float d)
{
    struct points a,b;
      printf("The distance between points (%.1f,%.1f) and (%.1f,%.1f) is %.2f ",a.x,a.y,b.x,b.y,d);
    
}
int main()
{
    int countx;  
    countx=1;
   
    struct points a, b;
    float d;
    a=input(countx);
    countx++;
    b=input(countx);
    d= distance(a,b);
    output(d);
return 0;
}

