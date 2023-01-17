#include <stdio.h>
#include <time.h>

// a is first rob
// b is the auxilary rod
// c is the last rod
void toh(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", a, c);
        return;
    }
    toh(n-1, a, c, b);
    printf("Move disk %d from rod %c to rod %c\n", n, a, c);
    toh(n-1, b, a, c);
}

int main()
{
    // n of disks
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // to find the time taken to execute the program
    clock_t start_time, end_time;

    // calling the function
    start_time = clock();
    toh(n, 'A', 'B', 'C');
    end_time = clock();

    // execution time
    printf("The total time taken: %f\n", (double)(end_time -start_time)/CLOCKS_PER_SEC);

    return(0);
}
