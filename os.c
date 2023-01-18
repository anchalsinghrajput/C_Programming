// ===================== program 1 ====================

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
    int pid;
    pid=fork();
    if(pid==0)
    {
        printf("Child process...");
        printf("\n\nChild PID : %d",getpid());
        printf("\nParent PID : %d",getppid());
        printf("\n\nFinished with child\n");
    }
    else
    {
        wait(NULL);
        printf("\nParent process");
        printf("\nPARENT PID : %d",getpid());
        printf("\nChild PID : %d",pid);
    }
}



output : 
Child process...

Child PID : 6612
Parent PID : 6608

Finished with child

Parent process
PARENT PID : 6608
Child PID : 6612
  
  
// ================ program 2 ===============
  
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
void main()
{
	char buff;
	int fd1,fd2;
	fd1 = open("one.txt", O_RDONLY);
	fd2 = open("two.txt", O_WRONLY|O_CREAT);
	
	while(read(fd1,&buff,1))
	{
	    write(fd2,&buff,1);
	}

    printf("the copy is successful ");
    close(fd1);
    close(fd2);
}

output : 
the copy is successful

// ================ program 3 ====================


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void main(int argc,char *arg[])
{
    int pid;
    pid=fork();
    if(pid<0)
    {
        printf("fork failed");
        exit(1);
    }
    else if(pid==0)
    {
        printf("\nNow in Child Process and it's o/p is \n");
        execlp("ls","ls",NULL);
        exit(0);
    }
    else
    {
        printf("\nChild Process created successfully");
        printf("\nIt's Process id is %d\n",getpid());
        wait(NULL);
        printf("\nReturn back to Parent process, now ready to exit\n");
        exit(0);
    }
}

output : 
Child Process created successfully
It's Process id is 108
Now in Child Process and it's o/p is 
a.out  main.c  one.txt  two.txt

Return back to Parent process, now ready to exit

// ================ program 4 ======================
  
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int g = 0;
void *myThreadFun(void *vargp)
{
	int *myid = (int*)vargp; //address covert to thread id 
	static int s = 0;
	++s,++g;
	printf("Thread ID : %u, static : %d, Global:%d\n", *myid,++s,++g);
}

int main()
{
	int i;
	pthread_t tid;
	for(int i=0; i<3; i++)
	{
		pthread_create(&tid,NULL,myThreadFun,(void*)&tid);
	}
	pthread_exit(NULL);
	return 0;
}

output :
Thread ID : 10995456, static : 2, Global:2
Thread ID : 10995456, static : 4, Global:4
Thread ID : 10995456, static : 6, Global:6
  
// ================= program 5 ====================

#include<stdio.h>

void main()
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
}
 
output:
Enter the number of process :  5
Enter burst and arrival time for process [1] 
Enter arrival time : 0 
Enter burst time : 5
Enter burst and arrival time for process [2] 
Enter arrival time : 1
Enter burst time : 3
Enter burst and arrival time for process [3] 
Enter arrival time : 2
Enter burst time : 1
Enter burst and arrival time for process [4] 
Enter arrival time : 3
Enter burst time : 2
Enter burst and arrival time for process [5] 
Enter arrival time : 4
Enter burst time : 3
Enter time quantum : 2

Process          Burst time              TAT             WT 
process[3]               1                3              2 
process[4]               2                4              2 
process[2]               3                11             8 
process[5]               3                9              6 
process[1]               5                14             9 
Average turn around time  : 8.200000 
Average waiting time : 5.400000
  
// ================ program 6 ==================

#include<stdio.h>
#include<stdlib.h>
int mutex=1 ,empty = 3,  full = 0, x = 0;

int wait(int s)
{
    return --s;
}

int signals(int s)
{
    return ++s;
}

void producer()
{
    mutex = wait(mutex);
    full = signals(full);
    empty = wait(empty);
    x++;
    printf("producer produces an item %d\n\n",x);
    mutex = signals(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signals(empty);
    printf("consumer consumes an item %d\n\n",x);
    x--;
    mutex = signals(mutex);
}

void main()
{
    int choice;
    while(1)
    {
        printf("Enter your choice : \n1.Producer\n2.Consumer\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(empty !=0 && mutex ==1) producer();
                    else printf("Buffer is full\n");
            break;
            case 2: if(full !=0 && mutex == 1) consumer();
                    else printf("Buffer is empty\n");
            break;
            default: exit(1);
        }
    }
}

// ================== program 7 ===============
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Max[10][10], need[10][10], alloc[10][10], avail[10],
    completed[10], safeSequence[10];
    int p, r, i, j, process, count;
    count = 0;
    
    printf("Enter the no of processes : ");
    scanf("%d", &p);
    
    for(i = 0; i< p; i++)
        completed[i] = 0;
        
    printf("\n\nEnter the no of resources : ");
    scanf("%d", &r);
    
    printf("\n\nEnter the Max Matrix for each process :");
    for(i = 0; i < p; i++)
    {
        printf("\nFor process %d : ", i + 1);
        for(j = 0; j < r; j++)
        scanf("%d", &Max[i][j]);
    }
    
    printf("\n\nEnter the allocation for each process : ");
    for(i = 0; i < p; i++)
    {
        printf("\nFor process %d : ",i + 1);
        for(j = 0; j < r; j++)
        scanf("%d", &alloc[i][j]);
    }
    printf("\n\nEnter the Available Resources : ");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);
        
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j];
            
    do
    {
        printf("\n Max matrix:\tAllocation matrix:\n");
        for(i = 0; i < p; i++)
        {
            for( j = 0; j < r; j++)
                printf("%d ", Max[i][j]);
            printf("\t\t");
            for( j = 0; j < r; j++)
                printf("%d ", alloc[i][j]);
            printf("\n");
        }
        
        process = -1;
        for(i = 0; i < p; i++)
        {
            if(completed[i] == 0)//if not completed
            {
                process = i ;
                for(j = 0; j < r; j++)
                {
                    if(avail[j] < need[i][j])
                    {
                        process = -1;
                        break;
                    }
                }
            }
            
            if(process != -1)
                break;
        }
        
        
        if(process != -1)
        {
            printf("\nProcess %d runs to completion!", process + 1);
            safeSequence[count] = process + 1; count++;
            for(j = 0; j < r; j++)
            {
                avail[j] += alloc[process][j];
                alloc[process][j] = 0;
                Max[process][j] = 0;
                completed[process] = 1;
            }
        }
    }
    while(count != p && process != -1);
    
    if(count == p)
    {
        printf("\nThe system is in a safe state!!\n");
        printf("Safe Sequence : < ");
        for( i = 0; i < p; i++)
            printf("%d ", safeSequence[i]);
        printf(">;\n");
    }
    else
        printf("\nThe system is in an unsafe state!!");
}

//=================program 8 ==================
#include<stdio.h>
int hitOrMiss(int num, int frames, int sf[])
{
    for(int i = 0; i<frames; i++)
    {
        if(num == sf[i])
        {
            return 1;
        }
    }
    return 0;
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
    return miss;
}

void main()
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
    
}

output:
Enter the number of pages : 14
Enter number of frames : 4
Enter pages number : 7 0 1 2 0 3 0 4 2 3 0 3 2 3
page fault : 7

// ================== program 9 ===============
#include<stdio.h>
#include<string.h>

void main()
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
            printf("%s  ", sub_dir[i]);
}

output :
Enter the root directory : anchal
Enter the number of files : 5
do you want to create files? (1 - yes, any - no) : 1
Enter filename : one
do you want to create files? (1 - yes, any - no) : 1
Enter filename : two
do you want to create files? (1 - yes, any - no) : 1
Enter filename : three
do you want to create files? (1 - yes, any - no) : 1
Enter filename : four
do you want to create files? (1 - yes, any - no) : 1
Enter filename : five
do you want to create files? (1 - yes, any - no) : 1
Enter filename : d
Number of file exceeded
do you want to create files? (1 - yes, any - no) : 1
Enter filename : r
Number of file exceeded
do you want to create files? (1 - yes, any - no) : 0
directory name: anchal
file names:
one two three four five

// ======================= program 10 ==================
#include<stdio.h>
#include<stdlib.h>
void main()
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
        count++;
    }
        
    if(count == n)
    {
        for(int i = 0; i<n; i++)
        index_block[index[i]] = 1;
        
        printf("allocated");
        printf("\nfile indexed");
            
        for(int i=0; i<n; i++)
            printf("\n%d ------------ %d : %d",idx,index[i],index_block[index[i]]);
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
		goto x; 
	else
		exit(0); 
}

output :
Enter the index block : 5
Enter the block needed : 4
Enter the number of files for the index 5 on the disk : 1 2 3 4
allocated
file indexed
5 ------------ 1 : 1
5 ------------ 2 : 1
5 ------------ 3 : 1
5 ------------ 4 : 1
Do you want to enter more files(Yes - 1/No - 0):1

Enter the index block : 6
Enter the block needed : 2 
Enter the number of files for the index 6 on the disk : 1 2
File in the index is already allocated
Enter the index block : 7
Enter the block needed : 3
Enter the number of files for the index 7 on the disk : 7 8 9
allocated
file indexed
7 ------------ 7 : 1
7 ------------ 8 : 1
7 ------------ 9 : 1
Do you want to enter more files(Yes - 1/No - 0):0
