#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*new,*head,*tail;

void create()
{
    int i,value;
    printf("Enter -1 to terminate \nEnter the elements : ");
    for(i=0;value!=-1;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
        new->data=value;
        new->next=NULL;
        
        if(head==NULL)
            head=new;
        else
            tail->next=new;
        tail=new;
    }
}

int sum()
{
    int sum=0;
    while(head)
    {
        sum+=head->data;
        head=head->next;
    }
    return sum;
}

void display(struct node *p,int s)
{
    printf("elements are : ");
    while(p->data!=-1)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    
    printf("\nSum of the elements in the node is : %d",s+1);
}

int main()
{
    create();
    int s;
    struct node *p=head;
    s=sum();
    display(p,s);
    return 0;
}
