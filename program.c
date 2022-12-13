// program 1 ======================== tower of hanoi ==================
#include<stdio.h>
#include<time.h>
void toh(int n, char A, char B, char C)
{
	if(n>0)
	{
		toh(n-1,A,C,B);
		printf("Move %c to %c \n",A,C);
		toh(n-1,B,A,C);
	}
}

int main()
{
	int n;
	double totalTime;
	__clock_t start,end;
	start = clock();
	printf("Enter the number of disk : ");
	scanf("%d", &n);
	toh(n,'A','B','C');
	end = clock();
	totalTime = (double)(end - start)/CLOCKS_PER_SEC;	
	printf("total time : %f", totalTime);
}


//program 2 ======================== binary search ====================
#include<stdio.h>
#include<time.h>
int binarySearch(int arr[], int l, int r, int key)
{
	if(l>r)
		return -1;
	else
	{
		int mid = l + (r-l)/2;
		if(arr[mid] == key)
			return mid+1;
		else if(key > arr[mid])
			binarySearch(arr,mid+1,r,key);
		else
			binarySearch(arr,l,mid-1,key);
	}
}

int main()
{
	int n;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter the elements : ");
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int key;
	printf("Enter the key : ");
	scanf("%d",&key);
	
	double totalTime;
	__clock_t start, end;
	start =clock();
	int ans = binarySearch(arr,0,n-1,key);
	end = clock();
	if(ans == -1)
		printf("Element not found ");
	else
		printf("Element found at %d \n",ans);
	
	printf("\nTotal Time : %f", (double)(end-start)/CLOCKS_PER_SEC);
}


//program 3  =========================== mergesort ============================

#include<stdio.h>
#include<time.h>

int temp[25];
void merge(int arr[], int start, int mid, int end)
{
	
	int i = start, j = mid+1, k = start;
	while(i<=mid && j<=end)
	{
		if(arr[i]>arr[j])
		{
			temp[k++] = arr[j++];
		}
		else
		{
			temp[k++] = arr[i++];
		}
	}
	
	while(i<=mid)
	{
		temp[k++] = arr[i++];
	}
	
	while(j<=end)
	{
		temp[k++] = arr[j++];
	}
	
	for(int i = start; i<k; i++)
	{
		arr[i] = temp[i];
	}
}

void mergeSort(int arr[], int start, int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}

int main()
{

	double totalTime;
	__clock_t start,end;
	start = clock();
	
	int n;
	printf("Enter the number of element in the array : ");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter the elements : ");
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	mergeSort(arr,0,n-1);
	printf("Sorted array is : ");	
	for(int i = 0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	
	end = clock();
	totalTime = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nTotal Time  : %f",totalTime);
}


// program 4 ============================== quick sort ==========================
#include<stdio.h>
#include<time.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int sort(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low-1;
	for(int j = low; j<high; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr+i,arr+j);
		}
	}
	swap(arr+i+1, arr+high);
	return i+1;
}

void quickSort(int arr[], int low , int high)
{
	if(low<high)
	{
		int pi = sort(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}


int main()
{

	double totalTime;
	clock_t start,end;
	start = clock();
	
	int n;
	printf("Enter the number of element in the array : ");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter the elements : ");
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	quickSort(arr,0,n-1);
	printf("Sorted array is : ");	
	for(int i = 0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	
	end = clock();
	totalTime = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nTotal Time  : %f",totalTime);
}

