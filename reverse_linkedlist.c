#include <stdio.h>
#include <stdlib.h>
 
// Link list node 
struct node
{
    int data;
    struct node* next;
};
 
// Function to reverse the linked list 
struct node* reverse(struct node* head)
{
    struct node* prev   = NULL;
    struct node* current = head;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// 1->2->3->4

// void recursiveReverse(struct node** head)
// {     
//     // printf("%d\n", head->data);
//     struct node* first;
//     struct node* rest;
      
//     /* empty list */
//     if (*head == NULL)
//        return;   
 
//     first = *head;  
//     rest  = first->next;
 
//      // List has only one node 
//     if (rest == NULL)
//        return;   
 
//     /* reverse the rest list and put the first element at the end */
//     recursiveReverse(&rest);
//     rest->next  = first;  
//     first->next  = NULL;          
//     *head = rest;    
// }
 
struct node* push(struct node* head, int new_data)
{
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = head;
    head = new_node;    
    return head;
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
   
     head = push(head, 20);
     head = push(head, 4);
     head = push(head, 15); 
     head = push(head, 85);      
     
     printList(head);    
     head = reverse(head);                      
     printf("\n Reversed Linked list \n");
     printList(head);
     // recursiveReverse(&head);
     // printf("\n Original List \n");
     // printList(head);    
}

