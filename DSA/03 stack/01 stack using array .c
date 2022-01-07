#include <stdio.h>
#include <stdlib.h>
struct Stack 
{
  
int size;
   
int top;
   
int *S;
 
};

void create (struct Stack *st) 
{
  
    printf ("Enter Size of the stack : ");
      
    scanf ("%d", &st->size);
      
    st->top = -1;
      
    st->S = (int *) malloc (st->size * sizeof (int));

} 
void Display (struct Stack st) 
{
  
    int i;
      
    for (i = st.top; i >= 0; i--)
        
    printf ("%d ", st.S[i]);
      
    printf ("\n");

}


void push (struct Stack *st, int x) 
{
  
    if (st->top == st->size - 1)
        
        printf ("Stack overflow\n");
      
    else
        
    {
          
        st->top++;
              
        st->S[st->top] = x;
        
    }

 
}


int pop (struct Stack *st) 
{
  
    int x = -1;
      
    if (st->top == -1)
        
        printf ("Stack Underflow\n");
      
    else
        
    {
          
        x = st->S[st->top--];
        
    }
      
    return x;

}


int peek (struct Stack st, int index) 
{
  
    int x = -1;
      
    if (st.top - index + 1 < 0)
        
        printf ("Invalid Index \n");
      
    x = st.S[st.top - index + 1];
      
    return x;

}


int isEmpty (struct Stack st) 
{
  
    if (st.top == -1)
        
        return 1;
      
    return 0;

}


int isFull (struct Stack st) 
{
  
    return st.top == st.size - 1 ? 1 : 0;

}


int stackTop (struct Stack st) 
{
  
    if (!isEmpty (st))
    
        return st.S[st.top];
      
    return -1;

}


 
int main () 
{
  
struct Stack st;
  
    create (&st);
      
    push (&st, 10);
      
    push (&st, 20);
      
    push (&st, 30);
      
    push (&st, 40);
  
    printf ("%d is the value at index 2 \n ", peek (st, 2));

    Display (st);
  
    return 0;

}



// Menu driven program

#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int a[100];
    int top;
};

void push(struct stack *s)
{
    int x;
    if(s->top==s->size)
        printf("Stack overflow");
    else
    {
        printf("Enter an element to push into the stack : ");
        scanf("%d",&x);
        s->top++;
        s->a[s->top]=x;
        printf("An element is pushed\n");
    }
}
void pop(struct stack *s)
{
    int x;
    if(s->top==-1)
        printf("stack underflow");
    else
    {
        x=s->a[s->top];
        s->top--;
        printf("Poped out element is : %d\n",x);
    }
    
}
void display(struct stack *s)
{
    printf("elements in the stack are : ");
    for(int i = 0; i<=s->top; i++)
        printf("%d ",s->a[i]);
    printf("\n");
}

int main()
{
    struct stack *s;
    s->top = -1;
    printf("Enter size of the stack : ");
    scanf("%d",&s->size);
    while(1)
    {
        printf("\n------------------------MENU------------------------\n");
        printf("1. push\n2. pop\n3. display\n4. exit\n");
        int c;
        scanf(" %d",&c);
        switch(c)
        {
            case 1: 
                push(s);
                break;
            case 2: 
                pop(s);
                break;
            case 3: 
                display(s);
                break;
            case 4: 
                exit(0);
            default:
                printf("Invalid input ");
                break;
        }
    }
}



