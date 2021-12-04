/******************************************************************************

1. Write a program to add, subtract, multiply and divide two integers using user defined type function with return type.

*******************************************************************************/
#include <stdio.h>

int add(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

float divide(int a, int b) {
    return (b!=0)?(float)a/b:-99999;
}

int main()
{
    int ch=1,a,b;
    while(ch=1) 
    {
        printf("0:Exit the program\n1: add two integers\n2:subtract two integers\n3: multiply two integers\n4: divide two integers.\nYour choice is: ");
        scanf("%d", &ch);
        if(ch==0)
            break;
            
        printf("Enter num1 and num2 with a space in between: ");
        scanf("%d%d",&a,&b);
        
        switch(ch)
        {
            case 1:
                printf("The sum of %d and %d is: %d",a,b,add(a,b));
                break;
            case 2:
                printf("%d subtracted from %d is: %d",a,b,subtract(a,b));
                break;
            case 3:
                printf("The product of %d and %d is: %d",a,b,multiply(a,b));
                break;
            case 4:
                printf("%d divided by %d is (Math error prints -99999): %f",a,b,divide(a,b));
                break;
            default:
                printf("Invalid choice.\n");
            }
        printf("\n\n");
    }
    return 0;
}


/******************************************************************************

2. Write a program to find the sum of digits of the number and print the reverse of that number using Recursive Function.

*******************************************************************************/
#include <stdio.h>

int sumOfDigit(int n) 
{
    if(n==0)
        return 0;
    else
    {
        printf("%d",n%10);
        return (n%10)+sumOfDigit(n/10);
    }
}

int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    
    printf("Reversed number :");
    printf("\nSum : %d", sumOfDigit(n));
    return 0;
}

/******************************************************************************

3. Write a program to add and multiply two matrices using (pointers?).

*******************************************************************************/
#include <stdio.h>

#define ROW 3
#define COL 3


/* Function declarations */
void matrixInput(int mat[][COL]);
void matrixPrint(int mat[][COL]);
void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL]);
void matrixSum(int mat1[][COL], int mat2[][COL], int sum[][COL]);


int main()
{
    int mat1[ROW][COL];
    int mat2[ROW][COL];
    int sum[ROW][COL];
    int product[ROW][COL];

    printf("Enter elements in first matrix of size %dx%d\n", ROW, COL);
    matrixInput(mat1);

    printf("Enter elements in second matrix of size %dx%d\n", ROW, COL);
    matrixInput(mat2);

    matrixSum(mat1, mat2, sum);
    // Call function to multiply both matrices
    matrixMultiply(mat1, mat2, product);

    printf("Sum of both matrices is : \n");
    matrixPrint(sum);

    // Print product of both matrix
    printf("Product of both matrices is : \n");
    matrixPrint(product);

    return 0;
}

void matrixInput(int mat[][COL])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            scanf("%d", (*(mat + row) + col));
        }
    }
}

void matrixPrint(int mat[][COL])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            printf("%d ", *(*(mat + row) + col));
        }

        printf("\n");
    }
}

void matrixSum(int mat1[][COL], int mat2[][COL],int sum[][COL])
{
    int r , c,i;
    for(r=0; r<ROW; r++)
    {
        for(c=0; c<COL; c++)
        {
            *(*(sum+r)+c) = *(*(mat1+r)+c) +  *(*(mat2+r)+c);
        }
    }
}

void matrixMultiply(int mat1[][COL], int mat2[][COL],int res[][COL])
{
    int row, col, i;
    int sum;
    
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            sum = 0;
            for (i = 0; i < COL; i++)
            {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }
            *(*(res + row) + col) = sum;
        }
    }
}

/******************************************************************************

4. Write a C program to search elements in data structure with different search methods

*******************************************************************************/

#include <stdio.h>

void bsort(int n, int arr[n])
{
    int i, j, t;

    for (i = 0; i < n; i++) {
  
        for (j = i + 1; j < n; j++) {
  
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int bin(int arr[],int b,int l,int x)
{
    if(l>=b)
    {
       int m = (b + l)/2; 
       //printf("\n middle= %d",m);
       
       if(arr[m]==x) return m; // Element found at middle index 
       
       if(arr[m]>x) return bin(arr,b,m-1,x); // Element is lesser than the middle Element so,
                                            //we send left part of the array, so last is previous Element of middle
       
       return bin(arr,m+1,l,x); // Element is greater than the middle Element so, we send right part of the array, 
                                //so beginning is next Element of middle
                                // bin(arr, 4,6,60)
    }
    return -1;
}
int linearSearch(int a[], int n, int val) {  
  // Going through array sequencially  
  for (int i = 0; i < n; i++)  
    {  
        if (a[i] == val)  
        return i;  
    }  
  return -1;  
}  

int main()
{
    int i,n,arr[100];
    int ch,x,index;
    
    printf("Enter the Number of Elements:");
    scanf("%d", &n);
    
    printf("\nEnter Array unique Elements:");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    printf("\nEnter the Element to be searched:");
    scanf("%d", &x);
    
    printf("\n1.Linear Search\t2. Binary Search\nMake your choice:");
    scanf("%d",&ch);
    
    if(ch==1)
        index= linearSearch(arr,n,x);//function call to linearSearch search 
    else if(ch==2)
        {   
            bsort(n,arr);
            index=bin(arr,0,n-1,x);// function call to binary search ( array, beginning index, last index, quest Element)
        }
    if(index!=-1)
        printf("\n\nElement found at Index: %d",index);
    else printf("\nElement Not found in Array!");
    
    printf("\nArray Elements:");
    for (i = 0; i < n; i++)  
        printf("%d ",arr[i]);
    
    
    
    return 0;
}


/* INFIX TO POSTFIX
*******************************************************************************/

#include <stdio.h>
#include<ctype.h>
#define MAX 15
char stack[MAX],top=-1;

void isempty()
{
    if(top==-1)
        printf("STACK UNDERFLOW");
}

void isfull()
{
    if(top==MAX)
        printf("STACK OVERFLOW");
}

void push(char x)
{
    if(top==MAX)
        isfull();
    else
        stack[++top]=x;
}

char pop()
{
    if(top==-1)
        isempty();
    else
        return stack[top--];
}

int priority(char x)
{
    if(x=='(') return 0;
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    if(x=='^') return 3;
}

int main()
{   
    char X[MAX];
    char *e,x;
    int ch=1;
    
    while(ch)
    {
        printf("\nEnter INFIX Expression:");
        scanf("%s",X);
        e=X;
        
        printf("\nThe POSTFIX Expression:");
        
        while(*e!='\0')
        {
            if(isalnum(*e))
                printf("%c",*e);
            else if(*e == '(') 
                push(*e);
            else if(*e==')')
            {
                while((x=pop()!='('))
                    printf("%c",x);
            }
            else
            {
                while(priority(stack[top])>= priority(*e))
                    printf("%c",pop());
                push(*e);
            }
            e++;
        }
        while(top!=-1)
            printf("%c",pop());
    }
    return 0;
}

/******************************************************************************
IMPLEMENTING A SIMPLE STACK DATA STRUCTURE
*******************************************************************************/
#include <stdio.h>
int stack[10],top=-1;

void isempty()
{
    if(top==-1)
        printf("STACK UNDERFLOW");
}

void isfull()
{
    if(top==9)
        printf("STACK OVERFLOW");
}

void push()
{
    if(top==9)
        isfull();
    else
        {
            printf("\nEnter the element to be pushed:");
            scanf("%d",&stack[++top]);
        }
}

void pop()
{
    if(top==-1)
        isempty();
    else
    {
        printf("\nThe element popped is: %d", stack[top--]);
    }
}

void peek()
{
    if(top==-1)
        printf("\n STACK is EMPTY");
    else printf("\nElement at the TOP:%d", stack[top]);
    
}

void display()
{
    if(top==-1)
        printf("\n STACK is EMPTY");
    printf("\nElements of the stack:");
    for(int i=0;i<=top;i++)
        printf("%d\t",stack[i]);
}

int main()
{   
    int ch=1;
    
    while(ch)
    {
        printf("\n1>PUSH\t2>POP\n3>PEEK\t4>DISPLAY\n0>EXIT\nEnter Choice:");
        scanf("%d",&ch);
        if(ch==1)
            push();
        else if(ch==2)
             pop();
        else if(ch==3)
            peek();
        else if(ch==4)
            display();
    }
    return 0;
}

/******************************************************************************
Evaluate POSTFIX 
*******************************************************************************/
#include <stdio.h>
#include<ctype.h>
#define MAX 20
int stack[20],top=-1;

void isempty()
{
    if(top==-1)
        printf("STACK UNDERFLOW");
}

void isfull()
{
    if(top==MAX)
        printf("STACK OVERFLOW");
}

void push(int x)
{
    if(top==MAX)
        isfull();
    else
        stack[++top]=x;
}

int pop()
{
    if(top==-1)
        isempty();
    else
        return stack[top--];
}

int posteval(char exp[])
{
    char *e;
    int num,n1,n2,tn;
    e=exp;
    
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            num=*e-48;
            push(num);
        }
        else
        {
          n1=pop();
          n2=pop();
          switch(*e)// +
          {
              case '+':tn=n1+n2;
                        break;
              
              case '-':tn=n1-n2;
                        break;
              case '*':tn=n1*n2;
                        break;
              case '/':tn=n1/n2;
                        break;
              //case '^':tn=power(n1,n2);
                      //  break;
              default: printf("\nOperator Unknown!"); return 0;
             
          }
          push(tn);
        }
        e++;      
    }
    return pop();
}

/* Tower of honoi */

int main()
{   
    int ch=1;
    char exp[MAX];
    
    printf("Enter the expression: ");
    scanf("%s",exp);
    
    printf("\n The Value of entered postfix %s expression is: %d",exp,posteval(exp));
    return 0;
}

#include <stdio.h>
int c=0;
void tower(int n, char beg, char mid, char end)
{
    printf("%d.",++c);
    if(n==1)
    {
        printf("Move Disk 1 from Peg %c to Peg %c\n",beg,end);
        return;
    }
    
    tower(n-1,beg,end,mid);
    printf("Move disk %d from Peg %c to Peg %c\n",n,beg,end);
    tower(n-1,mid,beg,end);
}


int main()
{
    int n;
    printf("\n Enter number of disks in A:");
    scanf("%d",&n);
    
    printf("Follow these steps to Achieve the target position:");
    tower(n,'A','B','C');

    return 0;
}

