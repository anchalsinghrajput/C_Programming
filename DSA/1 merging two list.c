/*Merging two sorted list such that the resulted list is also sorted */

#include<stdio.h>
int main()
{
    int m,n,i,j,k=0;
    printf("Enter the size of the first list \n ");
    scanf("%d",&m);
    printf("Enter the size of the second list \n");
    scanf("%d",&n);
    
    int a[n],b[m];
    printf("Enter the element of  the first list \n");
    for(i=0;i<m;i++)
    scanf("%d",&a[i]); 
    
    printf("Enter the element of  the second list \n");
    for(j=0;j<n;j++)
    scanf("%d",&b[j]);
    
    int c[m+n];
    i=0;j=0;
    while(i<m&&j<n)
    {
      if(a[i]>b[j])
      c[k++]=b[j++];
      else
      c[k++]=a[i++];
    }
    for(;i<m;i++)
    c[k++]=a[i];
    for(;j<n;j++)
    c[k++]=b[j];
    
    printf("Merged elements are \n ");
    
    for(k=0;k<(m+n);k++)
    {
        printf("\t%d",c[k]);
        
    }
    
    
    return 0;
}


// efficient way

#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
}
struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct
    Array));
    while(i<arr1->length && j<arr2->length)
    {
    if(arr1->A[i]<arr2->A[j])
    arr3->A[k++]=arr1->A[i++];
    else
    arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
    arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
    arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    return arr3;
}
int main()
{
    struct Array arr1={{2,9,21,28,35},10,5};
    struct Array arr2={{2,3,16,18,28},10,5};
    struct Array *arr3;
    
    arr3=Merge(&arr1,&arr2);
    Display(*arr3);
    return 0;
}


