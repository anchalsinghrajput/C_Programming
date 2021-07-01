#include<stdio.h>
int input(int n,int a[n])
{
    int i,s;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched\n");
    scanf("%d",&s);
    return s;
}
int compute(int n,int s,int a[n])
{
    int mid,l=0,u=n-1;
    
    while(l<=u)
    {
    mid=(l+u)/2;
    if(a[mid]==s)
       return mid;
    if (s>a[mid])
        l=mid+1;
        else
        u=mid-1;
    } 
    
    return -1;
    
}
void display(int p)
{
    if(p!=-1)
    printf("Position of the search element is %d\n",p);
    else
    printf("Element not found\n");
}

int main()
{
    int n,s,p;
    printf("Enter the number of element\n");
    scanf("%d",&n);
    int a[n];
    s=input(n,a);
    p=compute(n,s,a);
    display(p);
    return 0;
}

// efficient way

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
int BinarySearch(struct Array arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
    mid=(l+h)/2;
    if(key==arr.A[mid])
    return mid;
    else if(key<arr.A[mid])
    h=mid-1;
    else
    l=mid+1;
    }
    return -1;
}
int RBinSearch(int a[],int l,int h,int key)
{
    int mid=0;
    if(l<=h)
    {
    mid=(l+h)/2;
    if(key==a[mid])
    return mid;
    else if(key<a[mid])
    return RBinSearch(a,l,mid-1,key);
    }
    else
    return RBinSearch(a,mid+1,h,key);
    return -1;
}
int main()
{
    struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
    printf("%d",BinarySearch(arr1,16));
    Display(arr1);
    return 0;
}
