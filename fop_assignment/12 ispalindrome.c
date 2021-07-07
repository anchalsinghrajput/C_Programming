/*Write a program using functions to check if a given(user entered) number is a palindrome.
Your code must contain a function checkpalindrome().*/

#include<stdio.h>
int checkPalindrome(int n)
{
    static int rev=0;  
    if(n>0)
    {
    rev=(rev*10)+(n%10);
    checkPalindrome(n/10);
    return rev;
    }
    else 
    return 0;
    
}

int main()
{
    int n,rev;
    printf("Enter the Number :\n");
    scanf("%d",&n);
    rev=checkPalindrome(n);
    if(rev==n)
    {
        printf("Entered number is a palindrome");
    }
   else
    {
        printf("Entered number is not a palindrome");
    }
   return 0;
}
