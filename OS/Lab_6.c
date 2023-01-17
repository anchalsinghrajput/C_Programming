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

int main()
{
    int choice;
    
    while(1)
    {
        printf("Enter your choice : \n1.Producer\n2.Consumer\n3.Exit\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                if(empty !=0 && mutex ==1)
                {
                    producer();
                }
                else
                {
                    printf("Buffer is full\n");
                }
            break;
            
            case 2:
                if(full !=0 && mutex == 1)
                {
                    consumer();
                }
                else
                {
                    printf("Buffer is empty\n");
                }
            break;

            default: 
            exit(1);
        }
    }

    return(0);
}
