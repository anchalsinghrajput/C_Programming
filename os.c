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
    
    x : printf("\nEnter the index block : ");
    scanf("%d",&idx);
    
    if(index_block[idx])
    {
        printf("\nindex is already allocated ");
        goto x;
    }
  
    printf("Enter the block needed : ");
    scanf("%d",&n);
    printf("Enter the number of files for the index %d on the disk : ",idx);
    for(int i = 0; i<n; i++)
        scanf("%d",&index[i]);
    
    for(int i = 0; i<n; i++)
        index_block[index[i]] = 1;
        
    printf("allocated");
    printf("\nfile indexed");
        
    for(int i=0; i<n; i++)
        printf("\n%d ------------ %d : %d",idx,index[i],index_block[index[i]]);
    
    int c;
	printf("\nDo you want to enter more files(Yes - 1/No - 0):"); 
	scanf("%d", &c); 
	if(c == 1) 
		goto x; 
	else
		exit(0); 
}
