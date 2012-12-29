#include <stdio.h>
#include "Heap.h"

//heap initialization
heap* initialize(int initial_capacity, int(*compare)(void*, void*), void(*print_elt)(void*)){
      heap* h = (heap*)malloc(sizeof(heap));
      if(h == NULL)
          return NULL;
          
      h->size = initial_capacity;
      h->compare = compare;
      h->print_elt = print_elt;
      h->item_count = 0;
      return h;
}

//swim operation
void swim(heap** h, int index){
     int i;
     void* temp;
     
     if((*h) == NULL)
         return;
     
     for(i=index; i > 0 && (*((*h)->compare))((*h)->elts[i], (*h)->elts[i/2]) < 0; i=i/2){
         temp = (*h)->elts[i];
         (*h)->elts[i] = (*h)->elts[i/2];
         (*h)->elts[i/2] = temp;
     }
}

//sink operation
void sink(heap** h, int index){
     int i;
     int child;
     void* temp;
     int swap;
     
     if((*h) == NULL)
         return;
         
     for(i=index; 2 * i + 1 < (*h)->item_count; ){
                  
         child = 2 * i + 1;
         swap = i;
         
         if((*(*h)->compare)((*h)->elts[swap], (*h)->elts[child]) > 0)
             swap = child;
             
         child = child + 1;
         if((*(*h)->compare)((*h)->elts[swap], (*h)->elts[child]) > 0)
             swap = child;
             
         if(swap != i){
             temp = (*h)->elts[i];
             (*h)->elts[i] = (*h)->elts[swap];
             (*h)->elts[swap] = temp;
             i = swap;
         }
         else
             break;
             
     }
}

//heap insertion
int insert(heap** h, void* elt){
    //null case
    if(*h == NULL)
        return 0;
        
    //reallocation phase
    if((*h)->size == (*h)->item_count){
        (*h)->size *= 2;
        (*h)->elts = (void*)realloc((*h)->elts, sizeof(void*)*(*h)->size);
    }
    
    //empty case
    if((*h)->item_count == 0){
        (*h)->elts = (void*)malloc(sizeof(void*)*(*h)->size);
    }
    
    //add the element to the heap
    (*h)->item_count++;
    (*h)->elts[(*h)->item_count - 1] = elt;
    swim(h, (*h)->item_count - 1);
}

//pop method
void* pop(heap** h){
    void* head;      

    //null case
    if((*h) == NULL)
        return NULL;
        
    //get head elt
    head = (*h)->elts[0];
    (*h)->elts[0] = (*h)->elts[(*h)->item_count - 1];
    (*h)->item_count--;
    sink(h, 0);
    
    //shrink phase
    if((*h)->size / 4 == (*h)->item_count){
        (*h)->size = (*h)->size/4;
        (*h)->elts = (void*)realloc((*h)->elts, sizeof(void*)*(*h)->size);
    }
    
    return head;
}

//get heap size
int size(heap* h){
    return h->size;
}

//display heap
void display_heap(heap* h){
     int i;
     printf("---------------\n");
     printf("HEAP DATA : \n");
     printf("---------------\n");
     for(i=0; i<h->item_count; i++)
         (*(h->print_elt))(h->elts[i]);
     printf("---------------\n");
}
