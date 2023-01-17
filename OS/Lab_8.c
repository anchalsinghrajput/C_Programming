#include<stdio.h>

int hitOrMiss(int num, int frames, int sf[])
{
    for(int i = 0; i<frames; i++)
    {
        if(num == sf[i])
        {
            return(1);
        }
    }

    return(0);
}

int fcfs(int n, int frames, int a[], int sf[])
{
    int hit = 0, miss = 0, top = 0;
    for(int i=0; i<n; i++)
    {
        if(hitOrMiss(a[i],frames,sf))
        {
            hit++;
        }
        else
        {
            miss++;
            sf[top%frames] = a[i];
            top++;
        }
    }

    return(miss);
}

int main()
{
    int n;
    printf("Enter the number of pages : ");
    scanf("%d",&n);
    
    int frames;
    printf("Enter number of frames : ");
    scanf("%d",&frames);
    
    int a[n];
    printf("Enter pages number : ");
    
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    int sf[frames];
    
    for(int i = 0; i<frames; i++)
    {
        sf[i] = -1;
    }
    printf("page fault : %d",fcfs(n,frames,a,sf));
  
    return(0);
}
