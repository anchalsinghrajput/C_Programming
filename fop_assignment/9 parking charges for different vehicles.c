/*Design a C program to read the vehicle type (User can enter c or C for car, b or B for bus, t or T for Tempo for vehicle type)
and Duration (in whole hours) of customer vehicle parked in parking slot.
Parking fare is calculated as per the rates given below, print the total parking charges.
Your program should contain separate input, compute and output functions.
Make sure to write 3 test cases of your own when you submit your PDF.

Vehicle
First Rate    
Second Rate

Car
Rs 30/hr for first 2hr
Rs 20/hr for next 

Bus
Rs 50/hr for first 2hr
Rs 40/hr for next 

Tempo
Rs 40 /hr for first 2hr
Rs 30/hr for next 

Input:
Input the type of vehicle : c
Input duration of parking : 8

Output:
The charges for first 2 hours : 60
The charges for next 6 hours : 120
Total parking charges are Rs.180*/





#include<stdio.h>
#include<stdlib.h>
struct point{
    char type;
    int duration;
};
struct point input()
{
    struct point a;
        printf("Enter the type of vehicles\nEnter c or C for car, b or B for bus, t or T for Tempo.\n");
        scanf("%c",&a.type);
        printf("Enter the duration of parking\n");
        scanf("%d",&a.duration);
        return  a;
}
void compute(int *amt, int *next_amt,int *final_amt)
{   
    struct point a;
        if((a.type=='c') || (a.type=='C'))
        {
           if(a.duration>2)
           {
                *amt=30*2;
                *next_amt=20*(a.duration-2);
                *final_amt=(*amt)+(*next_amt);
           }
           else
           {
               *amt=30*(a.duration);
           }
        }
        
        else if ((a.type=='b') || (a.type=='B'))
        {
            if(a.duration>2)
           {
                *amt=50*2;
                *next_amt=40*(a.duration-2);
                *final_amt=(*amt)+(*next_amt);
           }
           else
           {
               *amt=50*(a.duration);
           }
        }
        
        else if ((a.type=='t') || (a.type=='T'))
        {
            if(a.duration>2)
           {
                *amt=40*2;
                *next_amt=30*(a.duration-2);
                *final_amt=(*amt)+(*next_amt);
           }
           else
           {
               *amt=40*(a.duration);
           }
            
        }
}
void output(int amt, int next_amt,int final_amt)
{   
        struct point a; 
        if(a.duration>2)
        {
            printf("The charges for first 2 hours : %d \n",amt);
            printf("The charges for next %d hours : %d \n",(a.duration-2),next_amt);
            printf("Total parking charges are : %d",final_amt);
        }
        else
        {
           printf("The charges for  %d hour is : %d \n",a.duration,amt); 
        }
}
int main()
{
    struct point a;
    int amt,next_amt,final_amt;
    a=input();
    compute(&amt,&next_amt,&final_amt);
    output(amt,next_amt,final_amt);
    return 0;
}


