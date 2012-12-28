#include <stdio.h>
#include <conio.h>
#include "DoublyLinkedList.h"

/**print integer values **/
void print_elt(void* elt){
    printf("%d\n", *((int *)elt));
}

/**reversing the linked_list**/
void reverse_prog(){
     /**create node **/
     node* head = NULL;
     
     int elts[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int i, status;
     
     /**add arbitrary elements to  the list and check**/
     for(i=0; i<10; i++){
         status = append_last(&head, (void*)&elts[i]);
     }
     
     /** print the list and check **/
     print_list(head, (&print_elt));
     
     /**reverse the linked list**/
     recursive_reverse_list(&head);
     
     /** print the list and check **/
     print_list(head, (&print_elt));
     printf("reversed using recursion..\n");

     /**reverse the linked list**/
     reverse_list(&head);
     
     /** print the list and check **/
     print_list(head, (&print_elt));
     printf("reversed without using recursion..\n");     
}


/**check the list funcitonality **/
void check_list(){
     /** create node **/
     node* head = NULL;
     int elts[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int i, status;
     
     /**add arbitrary elements to  the list and check**/
     for(i=0; i<10; i++){
         status = append_last(&head, (void*)&elts[i]);
     }
     
     /** print the list and check **/
     print_list(head, (&print_elt));
     
     /** delete elements and try **/
     for(i=0; i<10; i++){
         status = delete_at(&head, i);
         print_list(head, (&print_elt));
     }
     
}

/**get arbit list**/


/** main function **/
int main(){
    
    //check_list();
    reverse_prog();

    getchar();    
    return 0;
}
