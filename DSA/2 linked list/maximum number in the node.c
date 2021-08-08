#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*temp,*head,*tail;


int main()
{
    int i, ele;
    printf("Enter -1 to terminate \nEnter the elements ");
    for(i=0;ele!=-1;i++)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&ele);
        
        temp->data=ele;
        temp->next=NULL;
        if(ele==-1)
        {
            break;
        }
        else
        {
            if(head==NULL)
                head=temp;
            else
                tail->next=temp;
            tail=temp;
        }
    }
    
    int m=-32768;
    while(head)
    {
        if(m<head->data)
            m=head->data;
        head=head->next;
    }
    
    printf("Maximum element of the list is : %d",m);
    
    return 0;
}
