/*Activity10: Write a program to compute new clock time when you add time in hours and minutes to a given clock time in 24 hours clock .

Given time : 23 10
Time to add: 1 40
Output: 23: 10 + 1:40 is 0:50*/



#include <stdio.h>

int main(){
    int h1, m1, h2, m2;

    printf("given time: ");
    scanf("%d %d", &h1, &m1);
    printf("time to add: ");
    scanf("%d %d", &h2, &m2);

    int finalMin = m1 + m2;
    int finalHour = (h1 + h2 + finalMin/60)%24;                
    finalMin = finalMin % 60;
    printf("Sum: %d:%d", finalHour, finalMin);
    return 0;
}
