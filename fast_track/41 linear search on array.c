//normal
#include<stdio.h>
int main()
{
 int i,n,s,p=-1;
 printf("Enter the number of element:\n");
 scanf("%d",&n);
 printf("Enter the elements:\n");
 int a[n];
 for(i=0;i<n;i++)
 {
     scanf("%d",&a[i]);
 }
 printf("Enter the search element:\n");
 scanf("%d",&s);
 
 for(i=0;i<n;i++)
 if(s==a[i])
 {
    p=i;
    break;
 }
 
 if(p!=-1)
 printf("Position of the element: %d",i);
 else
 printf("element is not present");
 
 return 0;
}

//using function

#include<stdio.h>
int input(int n,int a[n])
{
    int i,k;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched\n");
    scanf("%d",&k);
    return k;
}
int compute(int n,int k,int a[n])
{
    int i,l=-1;
    for(i=0;i<n;i++)
    if(a[i]==k)
        {
            l=i;
            break;
        }
        return l;
}
void display(int l)
{
    if(l!=-1)
    printf("Position of the search element is %d\n",l);
    else
    printf("Element not found\n");
}

int main()
{
    int n,k,l;
    printf("Enter the number of element\n");
    scanf("%d",&n);
    int a[n];
    k=input(n,a);
    l=compute(n,k,a);
    display(l);
    return 0;
}





// highly efficient way

#include<stdio.h>
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
void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}
int LinearSearch(struct Array *arr,int key)
{
int i;
for(i=0;i<arr->length;i++)
{
if(key==arr->A[i])
{
swap(&arr->A[i],&arr->A[0]);
return i;
}
}
return -1;
}

int main()
{
struct Array arr1={{2,23,14,5,6,9,8,12},10,8};
printf("%d",LinearSearch(&arr1,14));
Display(arr1);
return 0;
}
