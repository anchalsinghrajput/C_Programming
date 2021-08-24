#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter size : ");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}
void push(struct Stack *st,int x)
{
    if(st->top==st->size -1)
        printf("Stack overflow ");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}
void display(struct Stack st)
{
    int i;
    for(i=st.top;i<=0;i--)
        printf("%d",st.S[i]);
    printf("\n");
}
int main()
{
   struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    
    display(st);
    return 0; 
}
