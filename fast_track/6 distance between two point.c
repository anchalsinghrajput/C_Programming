/*Activity6: Write a program to the find distance between two points on x, y plane


Input:
Enter (x,y) of point 1: 1,1
Enter (x,y) of point 2: 2,2

Output:
The distance between (1.00,1.00) and (2.00,2.00) is 1.14

ANSWER:

d=root of ((x2-x1)^(2)+(y2-y1)^(2))

for finding the root we have to include #include<math.h> header file.*/


Program:
#include<stdio.h>
#include<math.h>
int main()
{
float x1 , x2 , y1 ,y2 , d=0;
    printf("enter x1 and y1 \n");
    scanf("%f%f",&x1,&y1);
    printf("enter x2 and y2\n");
    scanf("%f%f",&x2,&y2);
  
    d=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
  
    printf("The distance between ( %f ,%f) and (%f,%f) is:%f" , x1,y1,x2,y2,d);
    return 0;
}

