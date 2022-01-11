#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
};

typedef struct node n;

n * createNode(int x)
{
    n* newNode = (n*) malloc(sizeof(n));
    newNode->data = x;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void display(n *head)
{
    n *temp=head;
    if(head==NULL)
      printf("List : NULL\n");
    else
    {
      printf("Element in the list are : ");
      while(temp!=NULL)
      {
        printf("%d ",temp->data);
        temp=temp->next;
      }  
    }
    printf("\n");
}

n* insertAtFront(n *head , int x)
{
   n *newNode=createNode(x);
   if(head==NULL)
   {
      head=newNode;
   }
   else
   {
     head->prev=newNode;
     newNode->next=head;
     head=newNode; 
   }
  return head;
}

n* insertAtEnd(n *head, int x)
{
    n* temp = head;
    n* newNode = createNode(x);
    if(head==NULL)
        head=newNode;
   else
   {
       while(temp->next!=NULL)
       {
         temp=temp->next;
       }
       temp->next=newNode;
       newNode->prev=temp;
   }
   return head;
}

int len(n *head)
{
    n* temp = head;
    int count = 0;
    while(temp!=NULL)
    {
      temp = temp->next;
      count++;
    }   
    return count;
}

n* insertAtPosition(n *head, int x, int pos)
{
    if (pos<0 || pos>len(head))
        printf("Invalid position\n");
    else
    {
        n* ptr = head;
        if(pos==1)
            insertAtFront(head,x);
        else
        {
            for(int i=1;i<pos-1;i++)
                ptr=ptr->next;
            if(ptr->next==NULL)
                insertAtEnd(head,x);
            else
            {
                n *newNode, *ptr1;
                newNode=createNode(x);
                ptr1=ptr->next;
                newNode->next=ptr1;
                newNode->prev=ptr;
                ptr->next=newNode;
                ptr1->prev=newNode;
            }
        }
    }
    return head;
}

n* deleteAtFront(n *head)
{
    if(head==NULL)
        printf("List is empty\n");
    else if(head->next == NULL)
        free(head);
    else
    {
        n *ptr = head;
        head = head->next;
        head->prev=NULL;
        printf("Deleted element is %d \n",ptr->data);
        free(ptr);
    }
    return head;
}

n* deleteAtEnd(n *head)
{
    if(head==NULL)
        printf("List is empty");
    else if(head->next==NULL)
        free(head);
    else
    {
        n *ptr = head,*ptr1;
        while(ptr->next->next!=NULL)
            ptr = ptr->next;
        ptr1 = ptr->next;
        ptr->next=NULL;
        printf("Deleted element is %d \n",ptr1->data);
        free(ptr1);
    }
    return head;
}

n *deleteAtPosition(n *head, int pos)
{
    if(pos<0||pos>len(head))
        printf("Invalid position\n");
    else
    {
        if(pos==1)
            deleteAtFront(head);
        else if(pos==len(head))
            deleteAtEnd(head);
        else
        {
            n* ptr = head,*ptr1;
            for(int i = 1; i < pos ; i++)
                ptr = ptr->next;
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            printf("Deleted element is %d \n",ptr->data);
            free(ptr);
        }
    }
    return head;
}

int main()
{
   n *head;
   head=NULL;
  
   while(1)
   {
      display(head);
      printf("---------------------------MENU------------------------\n");
      printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
      
      int choice;
      printf("Enter your choice : ");
      scanf("%d",&choice);

     switch(choice)
     {
      case 1: 
        {  
            int x;
            printf("\nINSERTION : \n1. Insert at beginning\n2. Insert at end\n3. Insert at any given position\n");
            int option;
            printf("Enter your choice : ");
            scanf("%d",&option);
            printf("Enter an element : ");
            scanf("%d",&x);
            switch(option)
            {
                case 1:   
                    head=insertAtFront(head,x);
                    break;
                case 2:  
                    head=insertAtEnd(head,x);
                    break;
                case 3:
                    {
                        int pos;
                        printf("Enter the position where element need to be inserted : ");
                        scanf("%d",&pos);
                        head=insertAtPosition(head,x,pos);
                    }
                    break;
                default : 
                    printf("Enter correct choice\n");
                    break;
            }
        }
        break;
      case 2:
        {
            int option,pos;
            printf("\nDELETION : \n1. Delete at beginning\n2. Delete at end\n3. Delete at any given position\n");
            printf("Enter your choice : ");
            scanf("%d",&option);
            switch(option)
            {
                case 1 : 	
                    head = deleteAtFront(head);
                    break;
                case 2 :
                    head = deleteAtEnd(head);
                    break;
                case 3 :
                    {
                		printf("Enter position where element need to be deleted : ");
                		scanf("%d", &pos);
                		head=deleteAtPosition(head,pos);
                    }
                    break;
                default : 
                    printf("Enter correct choice\n");
                    break;
            }
        }
        break;
      case 3: 
        display(head);
        break;
      case 4: 
        exit(0);
        break;
      default: 
        printf("Enter correct choice : ");
        break;
     }
   }
   return 0;
}
