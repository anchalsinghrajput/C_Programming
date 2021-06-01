/*Activity20: Write a program using four functions to distinguish between vowels and consonants. 

Input: a
Output: vowel
Input: d
Output: not a vowel*/


#include<stdio.h>
char input(char a)
{
    printf("Enter the letter: \n");
    scanf("%c",&a);
    
    return a;
}
int compute(char a)
{ 
    int i=0;
    char vowel[10]={'a','e','i','o','u','A','E','I','O','U'};
    for(i=0;i<10;i++)
    {
        if(a==vowel[i])
        i=1;
    }
    return i;
}
void output(int i)
{
    if (i==1)
      printf(" the entered letter is a vowel . ");
    else
      printf("the entered letter is not a vowel.");
}
int main()
{
    char a;
    int l;
    a=input(a);
    l=compute(a);
    output(l);
    return 0;
    
}

