// Write a menu driven C program to implement singly linked list with options 1. Insert 2. Delete 3. Display 4. Exit.
// Each of the insert and delete option should contain further options with 1. At Beginning 2. At end 3. At given position. 
// After each operation, print the elements in the linked list.

#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node * next;
};

typedef struct Node NODE;

NODE * createNewNode(int data)
{
	NODE * newNode = (NODE *) malloc (sizeof(NODE));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

void display(NODE * head)
{
	NODE * current = head;
	while (current != NULL)
	{
		printf(" %d -->", current -> data);
		current = current -> next;
	}
	if(current==NULL)
	    printf(" NULL\n");
}

int length(NODE * head)
{
	// recursively determines the length of list
	return head == NULL ? 0 : 1 + length(head -> next);
}

NODE * insertAtFront(NODE * head, int data)
{
	NODE * newNode = createNewNode(data);
	newNode -> next = head;
	head = newNode;
	return head;
}

NODE * insertAtEnd(NODE * head, int data)
{
	NODE * newNode = createNewNode(data), * current = head;
	if (current == NULL)
		head = newNode;
	else
	{
		// traverse until end of list is reached
		while (current -> next != NULL) 
		    current = current -> next;
		current -> next = newNode;
	}
	return head;
}

NODE * insertAtAnyPosition(NODE * head, int data, int location)
{
	int len = length(head), i;
	if (location < 1 || location > len + 1)
		printf("\nInvalid Location to enter data\n");
	else if (location == 1)
		return insertAtFront(head, data);
	else 
	{
		NODE * newNode = createNewNode(data), * current = head;	
		for (i = 2; i != location; i++)
		    current = current -> next;
		newNode -> next = current -> next;
		current -> next = newNode;
	}
	return head;
}

NODE * deleteAtFront(NODE * head)
{
    NODE * current = head;
    if (current == NULL)
        printf("List is empty\n");
    else
    {
        head = head->next;
        free(current);
    }
    return head;
}

NODE * DeleteAtEnd(NODE * head)
{
    
    NODE * current = head,*ptr;
    if (current == NULL)
        printf("List is empty\n");
    else
    {
        while(current->next!=NULL)
        {
            ptr = current;
            current=current->next;
        }
        ptr->next=NULL;
        free(current);
    }
    return head;
}

NODE * deleteAtAnyPosition(NODE * head, int location)
{
	NODE * current = head, * previous;
	int curloc = 1, i, len = length(head);
	
	if (location < 1 || location > len)
		printf("\nInvalid Position\n");
	else
	{
		if (location == 1)
			head = head -> next;
		else
		{
			for (i = 1; i < location; i++)
			{
				previous = current;
				current = current -> next;
			}
			previous -> next = current -> next;
		}
		free(current);
	}
	return head;
}

int main() {
	NODE * head = NULL;
	int option, choice, data, location;
	while (1) {
	    printf("List : ");
	    display(head);
		printf("----------------------------------MENU-----------------------------------\n");
        printf("Enter 1 --> Insert \n");
        printf("Enter 2 --> Delete \n");
        printf("Enter 3 --> Display \n");
        printf("Enter 4 --> exit \n");
        int choice;
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            {
                printf("\nINSERTION : \n  1. Insert at beginning\n  2. Insert at end\n  3. Insert at any given position\n");
                printf("  Enter your choice : ");
                scanf("%d",&option);
                switch(option)
                {
                    case 1 : 
                    {
            			printf("Enter data to be inserted: ");
            			scanf("%d", &data);
            			head = insertAtFront(head, data);
                    }
                    break;
                    case 2 :
                    {
                        printf("Enter data to be inserted at end: ");
    			        scanf("%d", &data);
    			        head = insertAtEnd(head, data);
                    }
                    break;
                    case 3 :
                    {
                        printf("Enter data to be inserted: ");
            			scanf("%d", &data);
            			printf("Enter position to be inserted into: ");
            			scanf("%d", &location);
            			head = insertAtAnyPosition(head, data, location);
                    }
                    break;
                    default : printf("Enter correct choice\n");
                }
            }
            break;
            case 2 :
            {
                printf("\nDELETION : \n  1. Delete at beginning\n  2. Delete at end\n  3. Delete at any given position\n");
                printf("  Enter your choice : ");
                scanf("%d",&option);
                switch(option)
                {
                    case 1 : 
            			head = deleteAtFront(head);
                    break;
                    case 2 :
    			        head = DeleteAtEnd(head);
                    break;
                    case 3 :
                    {
            			printf("Enter position to be deleted into: ");
            			scanf("%d", &location);
            			head=deleteAtAnyPosition(head,location);
                    }
                    break;
                    default : printf("Enter correct choice\n");
                }
                break;
                case 3 : display(head);
                break;
                case 4 : exit(0);
                default : printf("Enter correct choice\n");
            }
        }
	}
    return 0;
}

