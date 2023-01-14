#include <stdio.h>
#include <time.h>
#include <string.h>

void lcs_length(char string_1[100], char string_2[100], int lcs_table[101][101])
{
	// calculating length of string_1 and string_2
    int m = strlen(string_1);
	int n = strlen(string_2);

    // plotting lcs table
	for(int i = 0; i <= m; i++)
    {
	    lcs_table[i][0]=0;
    }
	for(int j = 0; j <= n; j++)
    {
		lcs_table[0][j]=0;
    }
    for(int i = 1;i <= m; i ++)
	{
		for(int j = 1;j <= n; j++)
		{
			if(string_1[i-1] == string_2[j-1])
			{
                // diagonal arrow
				lcs_table[i][j] = lcs_table[i-1][j-1]+1;
			}
			else
			{
    			if(lcs_table[i-1][j] >= lcs_table[i][j-1])
    			{
    				// up arrow
                    lcs_table[i][j] = lcs_table[i-1][j];
    			}
    			else
    			{
    				// left arrow
                    lcs_table[i][j] = lcs_table[i][j-1];
    			}
			}
		}
	}
}

int main()
{
    char string_1[100], string_2[100];
    int lcs_table[101][101];

    // input of string_1 and string_2
    printf("Enter 1st String : ");
	scanf("%s", string_1);

	printf("Enter the 2nd String : ");
	scanf("%s", string_2);

    // to find the time taken to execute the program
    clock_t start_time, end_time;

    // calling the function
    start_time = clock();
    lcs_length(string_1, string_2, lcs_table);
    end_time = clock();
    
    // output
    int m = strlen(string_1);
	int n = strlen(string_2);

    int index = lcs_table[m][n];
    char lcs_algo[index + 1];
    lcs_algo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (string_1[i - 1] == string_2[j - 1])
        {
            lcs_algo[index - 1] = string_1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (lcs_table[i - 1][j] > lcs_table[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("String 1 : %s\nString 2 : %s\n", string_1, string_2);
    printf("LCS: %s\n", lcs_algo);

    // execution time
    printf("The total time taken: %f\n", (double)(end_time -start_time)/CLOCKS_PER_SEC);

    return(0);
}
