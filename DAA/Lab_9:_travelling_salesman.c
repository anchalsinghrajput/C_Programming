#include <stdio.h>
#include <time.h>
#include<string.h>

int is_every_city_visited(int* visited, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            return(0);
        }
    }
    return(1);
}

int tsp(int n, int pos, int matrix[n][n], int visited[n])
{
    if (is_every_city_visited(visited, n))
    {
        return matrix[pos][0];
    }

    int res = 999;
    for (int city = 0; city < n; city++)
    {
        if (visited[city] == 0)
        {
            visited[city] = 1;
            int new_answer = matrix[pos][city] + tsp(n, city, matrix, visited);
            visited[city] = 0;
            res = new_answer < res ? new_answer : res;
        }
    }

    return(res);
}


int main()
{
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // input
    int matrix[n][n], visited[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    
    // to find the time taken to execute the program.
    clock_t start_time, end_time;

    // calling the function
    tsp(n, 0, matrix, visited);
    
    // execution time
    printf("The total time taken: %f\n", (double)(end_time -start_time)/CLOCKS_PER_SEC);

    return(0);
}
