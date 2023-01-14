#include <stdio.h>
#include <time.h>

int max(int a, int b)
{
    if (a > b)
    {
        return(a);
    }
    return(b);
}

int main()
{
    
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

   

    // user input values
    int profit[n], weight[n];
    printf("Enter the profit: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }
    
    printf("Enter the weight: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    int max_weight;
    printf("Enter the maximum weight: ");
    scanf("%d", &max_weight);

    // to find the time taken to execute the program
    clock_t start_time, end_time;

    // knapsack code
    start_time = clock();
    int knapsack[n + 1][max_weight + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < max_weight + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                knapsack[i][j] = 0;
            }
            else if (j >= weight[i - 1])
            {
                knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i - 1][j - weight[i - 1]] + profit[i - 1]);
            }
            else
            {
                knapsack[i][j] = knapsack[i-1][j];
            }
        }
    }
    end_time = clock();

    // output
    printf("Maximum profit is: %d\n", knapsack[n][max_weight]);
    
    // execution time
    printf("The total time taken: %f\n", (double)(end_time -start_time)/CLOCKS_PER_SEC);

    return(0);
}
