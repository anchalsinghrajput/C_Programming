#include <stdio.h>
#include <time.h>

int min(int a, int b)
{
    if(a < b)
    {
        return(a);
    }
    return(b);
}

void floyd_warshall(int edges, int matrix[edges][edges])
{
    for(int k = 0; k < edges; k++)
    {
        for(int i = 0; i < edges; i++)
        {
            for(int j = 0; j < edges; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main()
{
    // no of edges create a square matrix
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // input
    int matrix[edges][edges];
    for(int i = 0; i < edges; i++)
    {
        for (int j = 0; j < edges; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // to find the time taken to execute the program
    clock_t start_time, end_time;

    // calling the function
    start_time = clock();
    floyd_warshall(edges, matrix);
    end_time = clock();
    
    // ouput
    printf("Reduced matrix is  : \n");
    for(int i = 0; i < edges; i++)
    {
        for(int j = 0; j < edges; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // execution time
    printf("The total time taken: %f\n", (double)(end_time -start_time)/CLOCKS_PER_SEC);

    return(0);
}
