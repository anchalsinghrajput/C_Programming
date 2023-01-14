#include<stdio.h> 
#include<time.h>

int n;
int cost[9][9],parent[9] ={0}; 

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
    printf("Total time is %f\n",totaltime);
}