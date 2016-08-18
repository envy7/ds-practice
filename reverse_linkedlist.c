#include <stdio.h>
#include <stdlib.h>
 
// Link list node 
struct node
{
    int data;
    struct node* next;
};
 
// Function to reverse the linked list 
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;
      
    if (*head_ref == NULL)
       return;   
 
    first = *head_ref;  
    rest  = first->next;
 
    if (rest == NULL)
       return;   
 
    recursiveReverse(&rest);

    first->next->next  = first;  
    first->next  = NULL;          
    *head_ref = rest;              
}
 
void push(struct node** head_ref, int new_data)
{
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);    
    (*head_ref)    = new_node;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    
 

int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     printList(head);    
     reverse(&head);                      
     printf("\n Reversed Linked list \n");
     printList(head);
     recursiveReverse(&head);
     printf("\n Original List \n");
     printList(head);    
}