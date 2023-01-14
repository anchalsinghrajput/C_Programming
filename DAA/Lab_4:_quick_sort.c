#include <stdio.h>
#include <time.h>

void swap(int *temp_1, int *temp_2)
{
    int temp_swap = *temp_1;
    *temp_1 = *temp_2;
    *temp_2 = temp_swap;
}


int sort(int start, int end, int *arr)
{
    int pivot = arr[end];
    int i = start;

    for(int j = start; j <= end; j++)
    {
        if(pivot < arr[j])
        {
            swap(arr + i, arr + j);
            i += 1;
        }
    }

    swap(arr + i, arr + end);
    
    return(i);
}

void quicksort(int start, int end, int *arr)
{
    if(start < end)
    {
        // calculating partition postion based on pivot
        int pi = sort(start, end, arr);

        // splitting array based on partition
        quicksort(start, pi - 1, arr);
        quicksort(pi + 1, end, arr);
    }
}

int main()
{
    // n is size of the array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // input
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // to find the time taken to execute the program
    clock_t start_time, end_time;

    // calling the function
    start_time = clock();
    quicksort(0, n - 1, arr);
    end_time = clock();

    // ouput
    printf("The sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // execution time
    printf("The total time taken: %f\n", (double)(end_time -start_time)/CLOCKS_PER_SEC);

    return(0);
}
