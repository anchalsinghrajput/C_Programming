/*Implement a Program in C language to Multiply Two Matrices Using Multi-dimensional Arrays.
The matrices should be accepted from the user. */

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,r1,c1,r2,c2;
    
        printf("Enter the order of the 1st matrix : \n");
        scanf("%d%d",&r1,&c1);
    
        printf("Enter the order of the 2nd matrix : \n");
        scanf("%d%d",&r2,&c2);
    
    int a[r1][c1],b[r2][c2],s[r1][c2];
    
    if(r2!=c1)
    {
        printf("Matrix can not be multiplied. \n");
        exit(0);
    }
    else
    {
        printf("Enter the element of the 1st matrix : \n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
                scanf("%d",&a[i][j]);
        }
        
        printf("Enter the element of the 2nd matrix : \n");
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
                scanf("%d",&b[i][j]);
        }
    }
    
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            s[i][j]=0;
            for(k=0;k<c1;k++)
            {
                s[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    
    printf("Product of the two given matrix is :\n");
    
    for(i=0;i<r1;i++)
    {
        {
            for(j=0;j<c2;j++)
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }

    return 0;
    
}
