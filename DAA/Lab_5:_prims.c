#include <stdio.h>
#include <time.h>

void prim(int edges, int arr[edges][edges])
{
    int selected[edges];
    // filling the selected array with zeros
    for (int i = 1; i < edges; i++) 
    {
        selected[i] = 0;
    }

    int no_of_selected_edges = 0;
    int x, y;

    // making sure that the edge 0 is always selected as it starts from 0
    selected[0] = 1;

    // finds the minimum span tree consisting vertices = edges-1 
    while (no_of_selected_edges < edges - 1) 
    {
        int minimum = 999;

        for (int i = 0; i < edges; i++)
        {
            for (int j = 0; j < edges && selected[i] == 1; j++) 
            {
                if (selected[j] == 0 && arr[i][j]) 
                {  
                    
                    // the edge should not in selected
                    if (minimum > arr[i][j]) 
                    {
                        minimum = arr[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, arr[x][y]);
        selected[y] = 1;
        no_of_selected_edges++;
    }
}

int main()
{
    // no of edges create a square matrix
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Weights of the vertices
    int arr[edges][edges];
    for(int i = 0; i < edges; i++)
    {
        for (int j = 0; j < edges; j++) 
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // to find the time taken to execute the program
    clock_t start_time, end_time;

    // calling the function.
    start_time = clock();
    prim(edges, arr);
    end_time = clock();
    
    // execution time
    printf("The total time taken: %f\n", (double)(end_time -start_time)/CLOCKS_PER_SEC);

    return(0);
}
