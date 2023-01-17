#include<stdio.h>

int main()
{
    int n, tq, bt[10], at[10],bt1[10],wt = 0,tat = 0;
    float awt,atat;
    
    printf("Enter the number of process :  ");
    scanf("%d",&n);
    
    for(int i = 0; i<n; i++)
    {
        printf("Enter burst and arrival time for process [%d] \n", i+1);
        printf("Enter arrival time : ");
        scanf("%d",&at[i]);
        printf("Enter burst time : ");
        scanf("%d",&bt[i]);
        bt1[i] = bt[i];
    }
    
    printf("Enter time quantum : ");
    scanf("%d",&tq);
    
    int noOfProcessDone = 0;
    int count = 0;
    int i = 0;
    int sum = 0;
    
    printf("\nProcess\t\t Burst time \t\t TAT \t\t WT \n");
    while(noOfProcessDone!=n)
    {
        if(bt1[i]<=tq && bt1[i]>0)
        {
            sum += bt1[i];
            bt1[i] = 0;
            count = 1;
        }
        else if(bt1[i]>0)
        {
            bt1[i] -= tq;
            sum += tq;
        }
        
        
        if(bt1[i] == 0 && count == 1)
        {
            noOfProcessDone++;
            printf("process[%d]\t\t %d  \t\t  %d \t\t %d \n", i+1, bt[i],sum-at[i],sum-at[i]-bt[i]);
            tat += sum - at[i];
            wt += sum - at[i] - bt[i];
            count = 0;
        }
        
        if(i == n-1)
        {
            i = 0;
        }
        else if(at[i+1]<=sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    
    atat = tat * 1.0 / n;
    awt = wt * 1.0 /n;
    printf("Average turn around time  : %f \n",atat);
    printf("Average waiting time : %f",awt);

    return(0);
}
