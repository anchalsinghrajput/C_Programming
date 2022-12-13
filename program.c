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

#include<stdio.h>
#include<string.h>
char x[100000],y[100000],b[1000][1000];
int i,j,m,n,a,c[1000][1000];
void print_lcs(int i,int j)
{
	if(i==0 || j==0)
		return ;
	if(b[i][j]=='d')
	{
		print_lcs(i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j]=='u')
	{
		print_lcs(i-1,j);
	}
	else
	{
		print_lcs(i,j-1);
	}
}
void lcs_length()
{
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(j=0;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='d';     //diagonal arrow
			}
			else
			{
    			if(c[i-1][j]>=c[i][j-1])
    			{
    				c[i][j]=c[i-1][j];
    				b[i][j]='u';      //upper arrow
    			}
    			else
    			{
    				c[i][j]=c[i][j-1];
    				b[i][j]='s';       // side arrow
    			}
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d  ",c[j][i]);
		}
		printf("\n");
	}
	print_lcs(m,n);
}

int main()
{
	printf("Welcome to the LCS Implementation in C");
	printf("\nEnter 1st Sequence : ");
	scanf("%s",x);
	printf("\nEnter the 2nd Sequence : ");
	scanf("%s",y);
	printf("\nLongest Common Subsequence is:\n");
	lcs_length();
}


// program 9 ================================ LCS ===============================
#include<stdio.h>
#include<string.h>
char x[100000],y[100000],b[1000][1000];
int i,j,m,n,a,c[1000][1000];
void print_lcs(int i,int j)
{
	if(i==0 || j==0)
		return ;
	if(b[i][j]=='d')
	{
		print_lcs(i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j]=='u')
	{
		print_lcs(i-1,j);
	}
	else
	{
		print_lcs(i,j-1);
	}
}
void lcs_length()
{
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(j=0;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='d';     //diagonal arrow
			}
			else
			{
    			if(c[i-1][j]>=c[i][j-1])
    			{
    				c[i][j]=c[i-1][j];
    				b[i][j]='u';      //upper arrow
    			}
    			else
    			{
    				c[i][j]=c[i][j-1];
    				b[i][j]='s';       // side arrow
    			}
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d  ",c[j][i]);
		}
		printf("\n");
	}
	print_lcs(m,n);
}

int main()
{
	printf("Welcome to the LCS Implementation in C");
	printf("\nEnter 1st Sequence : ");
	scanf("%s",x);
	printf("\nEnter the 2nd Sequence : ");
	scanf("%s",y);
	printf("\nLongest Common Subsequence is:\n");
	lcs_length();
}
