#include<stdio.h>
#include<stdlib.h>

int main()
{
    int index_block[50], idx, index[50],n;
    
    for(int i =0; i<50; i++)
        index_block[i] = 0;
    
    x:printf("\nEnter the index block : ");
    scanf("%d",&idx);
    
    if(index_block[idx])
    {
        printf("\nindex is already allocated ");
        goto x;
    }
  
    printf("Enter the block needed : ");
    scanf("%d",&n);
    printf("Enter the number of files for the index %d on the disk : ",idx);
    int count  = 0;
    
    for(int i = 0; i<n; i++)
    {   
        scanf("%d",&index[i]);
        if(index_block[index[i]] == 0)
        {
            count++;
        }
    }
        
    if(count == n)
    {
        for(int i = 0; i<n; i++)
        index_block[index[i]] = 1;
        
        printf("allocated");
        printf("\nfile indexed");
            
        for(int i=0; i<n; i++)
        {
            printf("\n%d ------------ %d : %d",idx,index[i],index_block[index[i]]);
        }
    }
    else
    {
        printf("File in the index is already allocated");
        goto x;
    }
    
    int c;
	printf("\nDo you want to enter more files(Yes - 1/No - 0):"); 
	scanf("%d", &c); 
	
    if(c == 1)
    {
		goto x; 
    }
    else
    {
		exit(0);
    }

    return(0);
}
