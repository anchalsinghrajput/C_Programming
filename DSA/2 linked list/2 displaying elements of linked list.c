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

//taking input untill enter is pressed
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//creating node of the link list

struct node
{
    int data;
    struct node *next;
}*new,*head,*tail,*temp;

int main()
{
    int value,i;
    char c;
    printf("Enter the elements : ");
    for(i=0; c!='\n'; i++)
    {
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d%c",&value,&c);
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
    }
    
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


// terminate at -1

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*new,*head,*tail,*temp;

int main()
{
    int value;
    printf("Enter the elements in the node and enter -1 to terminate : ");
    while(1)
    {
        scanf("%d",&value);
        new= (struct node*)malloc (sizeof(struct node));
   
        new->data = value ;
        new->next = NULL;
        if(value==-1)
        {
            break;
        }
        else
        {
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
        }
    }
   
    printf("Elements are : ");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    return 0;
   

}
