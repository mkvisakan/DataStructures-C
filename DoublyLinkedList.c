#include <stdio.h>
#include "DoublyLinkedList.h"

/**reverse the linked list without recursion**/
void reverse_list(node** head){
     node* cur = *head;
     node* prev = NULL;
     
     if(*head == NULL)
         return;
     
     while(cur != NULL){
         prev = cur->prev;
         cur->prev = cur->next;
         cur->next = prev;
         cur = cur->prev;
     }
     
     *head = prev->prev;
}

/**add node to the last**/
int append_last(node** head, void* element){

    /**create node and assert it**/
      node* new_node = (node*) malloc(sizeof(node));
      node* temp = *head;
      
      if (new_node == NULL)
         return 0;
      
      /**add values**/   
      new_node->elt     = element;
      new_node->next    = NULL;
      new_node->prev    = NULL;
      
      /**head is null case**/
      if(*head == NULL){
          *head = new_node;
          return 1;
      }
      
      /**add to end**/
      while(temp->next != NULL)
          temp = temp->next;
          
      temp->next = new_node;
      new_node->prev = temp;

      return 1;
}

/**add node to the first**/
int append_first(node** head, void* element){
    
    /**create node**/
    node* new_node = (node*)malloc(sizeof(node));
    
    if(new_node == NULL)
        return 0;
        
    /**add values**/
    new_node->elt     = element;
    new_node->next    = *head;
    new_node->prev    = NULL;

    if(*head != NULL)
        (*head)->prev     = new_node;
        
    *head             = new_node;
    
    return 1;
    
}

/**deletes a node**/
void delete_node(node** head, node* cur){
     /**if the current node is the head**/
     if(cur == (*head)){
         *head = (*head)->next;
         if(*head != NULL)
             (*head)->prev = NULL;
     }
     else{
         cur->prev->next = cur->next;
         if (cur->next != NULL)
             cur->next->prev = cur->prev;
     }
     free(cur);
}

/** deletes elt at an index**/
int delete_at(node** head, int index){
    node* temp = (*head);
    int counter = 0;
    
    /**reach the correct index**/
    while(temp!=NULL && counter < index){
       temp = temp->next;
       counter++;
    }
    
    /**check if reached the correct index**/
    if(temp!=NULL && counter == index){
        delete_node(head, temp);
        return 1;
    }
    
    return 0;
}

/** delete a specific element **/
int delete_elt(node** head, void* element){
    node* temp = (*head);
    
    /**reach the correct node**/
    while(temp!=NULL && temp->elt != element){
        temp = temp->next;
    }
    
    /**check if reached and delete it **/
    if(temp!=NULL && temp->elt == element){
        delete_node(head, temp);
        return 1;
    }
    return 0;
}

/**swap elt **/
void swap(node** node1, node** node2){
     node* temp;
     temp = *node1;
     *node1 = *node2;
     *node2 = temp;
}

/**reverse the list using recursion**/
node* rc_reverse_list(node* cur){
     if(cur == NULL)
         return;
     
     swap(&(cur->next), &(cur->prev));

     if(cur->prev == NULL)
         return cur;
         
     return rc_reverse_list(cur->prev);
}

/**reverse a linked list**/
void recursive_reverse_list(node** head){
    *head = rc_reverse_list(*head);
}


/** prints the elements **/
void print_list(node* head, void(*print_elt)(void*)){
     node* temp;
     node* prev = head;
     printf("DOUBLY LINKED LIST : \n");
     printf("-------\n");
     temp = head;
     
     while(temp != NULL){
          (*print_elt)(temp->elt);
          prev = temp;
          temp = temp->next;    
     }
     printf("-------\n");
     
     while(prev != NULL){
         (*print_elt)(prev->elt);
         prev = prev->prev;
     }
     printf("-------\n");
}
