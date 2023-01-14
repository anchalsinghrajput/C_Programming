#include <stdio.h>
#include <time.h>

int binarySearch(int start, int end, int *arr, int key)
{
    // calculating midpoint of the array 
    int mid = (start) + (end - start)/2;
    
    // if element not found in array
    if(start > end)
    {
        return(-1);
    }
    else if(key == arr[mid])
    {
        return (mid);
    }
    else if (key > arr[mid]) {
        return(binarySearch(mid + 1, end, arr, key)); 
    }

    return(binarySearch(start, mid - 1, arr, key));
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

    int key;
    printf("Enter the element to be found in the array: ");
    scanf("%d", &key);

    // calling the function
    start_time = clock();
    int find = binarySearch(0, n - 1, arr, key);
    end_time = clock();

    // output
    if(find > -1)
    {
        printf("Element found in %d postion\n", find);
    }
    else {
        printf("Element not found in array\n");
    }

    // execution time
    printf("The total time taken: %f\n", (double)(end_time -start_time)/CLOCKS_PER_SEC);

    return(0);
}
