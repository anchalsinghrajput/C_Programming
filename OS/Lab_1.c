#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 
    int pid = fork(); 
    
    if(pid<0) 
    { 
        printf("fork failed"); 
        exit(1); 
    } 
    else if(pid==0) 
    { 
        printf("\nNow in Child Process and it's o/p is \n"); 
        execlp("ls","ls",NULL); 
    } 
    else 
    { 
        printf("\nChild Process created successfully\n"); 
        printf("\nIt's Process id is %d\n",getpid()); 
        wait(NULL); 
        printf("\nReturn back to Parent process, now ready to exit\n"); 
    } 
    
    return(0);
}
