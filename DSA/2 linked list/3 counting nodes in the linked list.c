#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*new,*head,*tail;

int main()
{
    int value;
    printf("Enter the elements in the node and enter -1 to terminate : ");
    while(1)
    {
        scanf("%d",&value);
        new = (struct node*)malloc (sizeof(struct node));
   
        new->data = value ;
        new->next = NULL;
        if(value==-1)
        {
            break;
        }
        else
        {
            if(head==NULL)
                head=new;
            else
                tail->next=new;
            tail=new;
        }
    }
   
    printf("Elements are : ");
    struct node *temp;
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }
    
    printf("\nNumber of nodes in the linked list is : %d",count);
    
    return 0;
}
