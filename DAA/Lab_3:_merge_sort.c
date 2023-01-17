#include <stdio.h>
#include <time.h>

void merge(int *arr, int start, int mid, int end)
{
    int left_length = mid - start + 1;
    int right_length = end - mid;
  
    int temp_arr[end - start + 1];
  
    // storing all values in temp_arr
    for (int i = 0; i < (end - start + 1); i++)
    {
        temp_arr[i] = arr[i + start];
    }

    for (int i = 0, j = 0, k = start; k <= end; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_arr[i] <= temp_arr[j + left_length]))
        {
            arr[k] = temp_arr[i];
            i++;
        }
        else
        {
            arr[k] = temp_arr[j + left_length];
            j++;
        }
    }  
    
}


void mergeSort(int start, int end, int *arr)
{
    if(start < end)
    {
        int mid = start + (end - start)/2;
        
        // splits the arr into two halves based on based on mid points
        mergeSort(start, mid, arr);
        mergeSort(mid + 1, end, arr);
    
        // joins two arrays
        merge(arr, start, mid, end);
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

    // calling the function.
    start_time = clock();
    mergeSort(0, n - 1, arr);
    end_time = clock();
    
    
    // output
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
