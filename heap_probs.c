#include <stdio.h>
#include <conio.h>
#include "Heap.h"
/**compare elts**/
int compare(void* elt1, void* elt2){
    int a = *((int*)elt1);
    int b = *((int*)elt2);
    
    if(a<b)
        return -1;
    else if(a==b)
        return 0;
    else
        return 1;
}

/**print elts**/
void print_elt(void* elt){
    printf("%d\n", *((int*)elt));
}

int main(){
    int choice;
    int input;
    int exit = 0;
    int *elt;
    void* k;
    heap* h = initialize(4, &compare, &print_elt);
    
    do{
        printf("**************\n");
        printf("OPTIONS :\n");
        printf("**************\n");
        printf("1 -> Insert Element\n");
        printf("2 -> Display Heap\n");
        printf("3 -> Pop Heap\n");
        printf("4 -> Heap Size\n");
        printf("5 -> Exit\n");
        printf("**************\n");
        printf("CHOICE : \n");
        
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                     elt = (int*)malloc(sizeof(int));
                     printf("Enter element to be inserted\n");
                     scanf("%d", &input);
                     *elt = input;
                     insert(&h, (void*)elt);
                     break;
            case 2:
                     display_heap(h);
                     break;
            case 3:
                     k = pop(&h);
                     printf("ELEMENT POPPED : ");
                     print_elt(k);
                     free(k);
                     break;
            case 4:
                     input = size(h);
                     printf("HEAP SIZE : %d\n", input);
                     break;
            case 5:
                     exit = 1;
                     break;
            default:
                     printf("Enter a valid choice...\n");
        }
        
    }while(exit == 0);
    
    return 0;
}
