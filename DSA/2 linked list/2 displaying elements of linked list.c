#include<stdio.h>
#include<stdlib.h>

//creating node of the link list

struct node
{
    int data;
    struct node *next;
}*new,*head,*tail,*temp;

int main()
{
    int n,value,i=0;
    printf("Enter the numbers of elements in the node : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    do{
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&value);
        new->data=value;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            tail=new;
        }
        i++;
    }while(i<n);
    
    //displaying the elements of the linked list


    printf("Elements of the linked list are : ");
    temp=head;
    while(temp!=NULL)
    {
        printf("  %d",temp->data);
        temp=temp->next;
    }
  return 0;  
}
