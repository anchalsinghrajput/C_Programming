#include<stdio.h>
#include<string.h>

int main()
{
    char root_dir[10];
    printf("Enter the root directory : ");
    scanf("%s", root_dir);
    
    int n;
    printf("Enter the number of files : ");
    scanf("%d",&n);
    
    char sub_dir[n][10];
    int count = 0;
    
    while(1)
    {
        int choice;
        printf("do you want to create files? (1 - yes, any - no : ");
        scanf("%d",&choice);
        
        if(choice !=1 )
            break;
        
        char filename[10];
        printf("Enter filename : ");
        scanf("%s",filename);
        
        int found = 0;
        for(int i = 0; i<n; i++)
        {
            if(strcmp(filename,sub_dir[i]) == 0)
            {
                found = 1;
                break;
            }
        }
        
        if(found)
        {
                printf("File already exist! ");
        }
        else if(count == n)
        {
            printf("Number of file exceeded \n");
        }
        else
        {
            strcpy(sub_dir[count++],filename);
        }
        
    }
    printf("directory name: %s\n", root_dir);
    printf("file names:\n");
        
    for (int i = 0; i < n; i++)
    {
        printf("%s  ", sub_dir[i]);
    }
    
    return(0);
}
