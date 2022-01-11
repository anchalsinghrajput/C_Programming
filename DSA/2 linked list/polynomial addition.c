//  Implement addition of two polynomials using linked list
#include<stdio.h>
#include<stdlib.h>

struct poly{
    int coef;
    int expo;
    struct poly *next;
};

typedef struct poly p;

p *createNode(p *head, int coef, int expo)
{
    p *newNode = (p*)malloc(sizeof(p));
    newNode->coef=coef;
    newNode->expo=expo;
    newNode->next=NULL;
    if(head==NULL)
        head=newNode;
    else
    {
        p *temp = head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    return head;
}

p *createPolyExpre(p *head)
{
    int coef,expo;
    int flag=1;
    while(flag==1)
    {
        printf("Enter the coefficient and exponenets : ");
        scanf("%d%d",&coef,&expo);
        head=createNode(head,coef,expo);
        printf("Enter 1 to continue and 0 to end : ");
        scanf("%d",&flag);
    }
    return head;
}

void display(p *head)
{
    p *temp = head;
    printf("\n%dx^%d ",temp->coef,temp->expo);
    temp = temp->next;
    while(temp!=NULL)
    {
        if(temp)
        {
            if(temp->coef>0)
                printf("+ ");
        }
        printf("%dx^%d ",temp->coef,temp->expo);
        temp=temp->next;
    }
    printf("\n");
}

p *summation(p *head1, p *head2)
{
    p *sum=NULL;
    while(head1&&head2)
    {
        if(head1->expo > head2->expo)
        {
            sum = createNode(sum,head1->coef,head1->expo);
            head1=head1->next;
        }
        else if(head2->expo > head1->expo)
        {
            sum = createNode(sum,head2->coef,head2->expo);
            head2=head2->next;
        }
        else if (head1->expo==head2->expo)
        {
            int newCoef;
            newCoef=head1->coef+head2->coef;
            sum = createNode(sum,newCoef,head1->expo);
            head1=head1->next;
            head2=head2->next;
        }
    }
    while(head1)
    {
        sum=createNode(sum,head1->coef,head1->expo);
        head1=head1->next;
    }
    while(head2)
    {
        sum=createNode(sum,head2->coef,head2->expo);
        head2=head2->next;
    }
    return sum;
}

int main()
{
    p *firstExpre = NULL;
    p *secondExpre = NULL;
    p *Sum = NULL;
    
    printf("Enter your expression in decreasing order of their exponenets.\n\n");
    
    printf("Enter your first polynomial expression : \n");
    firstExpre = createPolyExpre(firstExpre);
    display(firstExpre);
    
    printf("\nEnter your second polynomial expression : \n");
    secondExpre = createPolyExpre(secondExpre);
    display(secondExpre);
    
    Sum = summation(firstExpre,secondExpre);
    printf("\nAddition of your two polynomial is : \n\n");
    display(Sum);
    return 0;
}

