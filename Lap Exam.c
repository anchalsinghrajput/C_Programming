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
