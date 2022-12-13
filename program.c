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



//program 7 ==============================  0/1 knapsack =====================================

#include<stdio.h>
#include<time.h>
int max(int a, int b)
{
    return (a>b)?a:b;
}
int main()
{
    int n;
    printf("Enter the number of items  : ");
    scanf("%d",&n);
    
    int profit[n];
    printf("Enter the profit  : ");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&profit[i]);
    }
    
    int weight[n];
    printf("Enter the weight : ");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&weight[i]);
    }
    
    int m;
    printf("Enter the maximum weight  : ");
    scanf("%d",&m);
    
    clock_t start = clock();
    
    int dp[n+1][m+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j<m+1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (j >= weight[i - 1])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + profit[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
     clock_t end = clock();
    
    printf("Maximum profit is  : %d",dp[n][m]);
    printf("\nTotal time : %lf",(double)end - start);
}

//program 8 =============================== Travelling saleman problem =======================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int is_every_city_visited(int* visited, int n)
{
  for (int i = 0; i < n; i++)
    if (visited[i] == 0)
      return 0;
  return 1;
}

int tsp(int** mat, int* visited, int n, int pos) {
  if (is_every_city_visited(visited, n)) {
    return mat[pos][0];
  }

  int res = INT_MAX;
  for (int city = 0; city < n; city++) {
    if (visited[city] == 0) {
      visited[city] = 1;
      int new_answer = mat[pos][city] + tsp(mat, visited, n, city);
      visited[city] = 0;
      res = new_answer < res ? new_answer : res;
    }
  }

  return res;
}

int main() {
  int n;
  printf("enter n: ");
  scanf("%d", &n);

  printf("enter matrix: ");
  int** mat = (int **) malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    mat[i] = (int *) malloc (n * sizeof(int));
    for (int j = 0; j < n; j++)
      scanf("%d", &mat[i][j]);
  }

  int* visited = (int *) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    visited[i] = 0;
  printf("min cost: %d\n", tsp(mat, visited, n, 0));

  return 0;
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
