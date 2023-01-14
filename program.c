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
	clock_t start,end;
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
	clock_t start, end;
	start =clock();
	int ans = binarySearch(arr,0,n-1,key);
	end = clock();
	if(ans == -1)
		printf("Element not found ");
	else
		printf("Element found at %d \n",ans);
	
	printf("\nTotal Time : %f", (double)(end-start)/CLOCKS_PER_SEC);
}


//program 3  =========================== mergesort =======================

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


// program 4 ============================== quick sort  ===================

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




// program 5 ============================== prims ============================
#include<stdio.h>
#include <time.h>
int n;
int cost[10][10];
void input()
{
    printf("\nEnter the adjacency matrix:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
}

void prims()
{
    int nodes_done = 1;
    int visited[10] = {0}, mincost = 0;

    visited[1]=1;
    while(nodes_done < n)
    {
        int min = 999, u = -1, v = -1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j]< min && visited[i])
                {
                    min=cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }       
        if(visited[u]==0 || visited[v]==0)
        {
            printf("\n Edge %d:(%d %d) cost:%d",nodes_done++,u,v,min);
            mincost+=min;
            visited[v]=1;
        }
        cost[u][v]=cost[v][u]=999;
    }
    printf("\n Minimun cost=%d",mincost);
}
void main() {
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    input();

  clock_t start = clock();
    prims();
  clock_t end = clock();
  printf("Time taken: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

}

//program 6 ======================= kruskal ==============================
#include<stdio.h> 
#include<time.h>

int n;
int cost[9][9],parent[9] ={0}; 

int find(int);
int uni(int,int); 

void input()
{
	printf("\nEnter the no. of vertices:"); 
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n"); 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			    cost[i][j]=999;
		}
	}
}

void kruskal()
{
    int ne = 1;
    int mincost = 0;
	while(ne < n)
	{
        int u = -1, v = -1;
        int min = 999;
		for(int i=1;i<=n;i++)
		{
			for(int j=1; j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					u=i;
					v=j;
				}
			}
		}
    
		int new_u = find(u); 
		int new_v = find(v);
		if(uni(new_u, new_v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,u,v,min); 
			mincost += min;
		}
		cost[u][v] = cost[v][u] = 999;
    }
    printf("\n\tMinimum cost = %d\n",mincost);
}

void main()
{
   	 input();
	printf("The edges of Minimum Cost Spanning Tree are\n");
	clock_t start=clock();
    	kruskal();
    	clock_t end=clock();
    double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTotal time is %f\n",totaltime);
}

int find(int i)
{
	while(parent[i])
		i=parent[i]; 
	return i;
}

int uni(int i,int j)
{
	if(i!=j)
	{
		parent[i]=j; 
		return 1;
	}
	return 0;
}


//program 7 ============================== floyd ==========================

#include<stdio.h>
#include<time.h>
int min(int a, int b)
{
    return (a<b) ? a:b; 
}
int main()
{
    int n;
    printf("Enter the number of nodes  : ");
    scanf("%d",&n);
    
    int matrix[n][n];
    printf("Enter the matrix : ");
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            scanf("%d",&matrix[i][j]);   
        }
    }
    
    clock_t start = clock();
    
    for(int k = 0; k<n; k++)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    clock_t end = clock();
    printf("reduced matrix is  : \n");
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTotal time is %f\n",totaltime);
}


//program8 =====================  0/1 knapsack ===============================

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
    double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Total time is %f\n",totaltime);
}


//program 9 ================= Travelling saleman problem =======================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int res = INT_MAX;
int mat[100][100];
int visited[100];
char path[100];
int path_idx = 0;
char final_path[100];
int size;

int is_every_city_visited(int n)
{
  for (int i = 0; i < n; i++)
    if (visited[i] == 0)
      return 0;
  return 1;
}

void tsp(int n, int pos, int total_cost)
{
  if (is_every_city_visited(n))
  {
    total_cost += mat[pos][0];
    if (total_cost < res)
    {
      res = total_cost;
       for (int i = 0; i < path_idx; i++)
       {
            final_path[i] = path[i] + 1;
            size = i;
       }
    }
  }

  for (int city = 0; city < n; city++)
  {
    if (visited[city] == 0)
    {
      visited[city] = 1;
       path[path_idx++] = city + '0';
      tsp(n, city, total_cost + mat[pos][city]);
       path[path_idx--] = 0;
      visited[city] = 0;
    }
  }
}

int main() {
  int n;
  printf("enter number of cities : ");
  scanf("%d", &n);

  printf("enter matrix: \n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &mat[i][j]);

  for (int i = 0; i < n; i++)
    visited[i] = 0;

  clock_t start = clock();
  tsp(n, 0, 0);
  printf("Minimum cost to travel: %d\n", res);
  printf("path: ");
  for(int i = 0; i<size; i++)
  {
      printf("%c->",final_path[i]);
  }
  printf("%c",final_path[size]);
  clock_t end = clock();
  printf("\nTime taken: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}

// program 10 ========================= LCS ===============================
#include<stdio.h>
#include<string.h>
#include<time.h>
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
	printf("\nEnter 1st Sequence : ");
	scanf("%s",x);
	printf("\nEnter the 2nd Sequence : ");
	scanf("%s",y);
	printf("\nLongest Common Subsequence is:\n");
	clock_t start = clock();
	lcs_length();
	clock_t end = clock();
	double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    	printf("\nTotal time is %f\n",totaltime);
}
