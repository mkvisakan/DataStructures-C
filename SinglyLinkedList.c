#include <stdio.h>
#include "SinglyLinkedList.h"

/**reverse the list using recursion**/
node* rc_reverse_list(node* cur, node* prev){
     node* temp;
     if(cur->next == NULL){
         cur->next = prev;
         return cur;
     }
     else{
         temp = rc_reverse_list(cur->next, cur);
         cur->next = prev;
         return temp;
     }
}

/**reverse a linked list**/
void recursive_reverse_list(node** head){
     *head = rc_reverse_list(*head, NULL);
}

/**reverse the linked list without recursion**/
void reverse_list(node** head){
     node* cur = *head;
     node* prev = NULL;
     node* next = NULL;
     
     while(cur != NULL){
         next = cur->next;
         cur->next = prev;
         prev = cur;
         cur = next;
     }
     
     *head = prev;
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
      
      /**head is null case**/
      if(*head == NULL){
          *head = new_node;
          return 1;
      }
      
      /**add to end**/
      while(temp->next != NULL)
          temp = temp->next;
          
      temp->next = new_node;

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
    *head             = new_node;
    
    return 1;
    
}

/**deletes a node**/
void delete_node(node** head, node* prev, node* cur){
     /**if the current node is the head**/
     if(cur == (*head))
         *head = (*head)->next;
     else
         prev->next = cur->next;
     free(cur);
}

/** deletes elt at an index**/
int delete_at(node** head, int index){
    node* temp = (*head);
    node* prev = NULL;
    int counter = 0;
    
    /**reach the correct index**/
    while(temp!=NULL && counter < index){
       prev = temp;
       temp = temp->next;
       counter++;
    }
    
    /**check if reached the correct index**/
    if(temp!=NULL && counter == index){
        delete_node(head, prev, temp);
        return 1;
    }
    
    return 0;
}

/** delete a specific element **/
int delete_elt(node** head, void* element){
    node* temp = (*head);
    node* prev = NULL;
    
    /**reach the correct node**/
    while(temp!=NULL && temp->elt != element){
        prev = temp;
        temp = temp->next;
    }
    
    /**check if reached and delete it **/
    if(temp!=NULL && temp->elt == element){
        delete_node(head, prev, temp);
        return 1;
    }
    return 0;
}


/** prints the elements **/
void print_list(node* head, void(*print_elt)(void*)){
     node* temp;
     printf("SINGLY LINKED LIST : \n");
     printf("-------\n");
     temp = head;
     
     while(temp != NULL){
          (*print_elt)(temp->elt);
          temp = temp->next;
     }
     printf("-------\n");
}
