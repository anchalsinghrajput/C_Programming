#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
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

    return(0);
}
