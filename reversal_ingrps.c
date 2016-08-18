#include <stdio.h>
#include <stdlib.h>
 
// Link list node 
struct node
{
    int data;
    struct node* next;
};
 

struct node *reverseInGrp(struct node *head, int k)
{   
    int count = 0;  
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
       
    while(current != NULL && count < k){
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next != NULL){
        head->next = reverseInGrp(next, k);
    }

    return prev;

}
 
struct node *push(struct node* head, int new_data)
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
     head = push(head, 35);
     head = push(head, 92);
     head = push(head, 17);

     printList(head);    
     head = reverseInGrp(head, 3);                      
     printf("\n Reversed Linked list \n");
     printList(head);  
}

