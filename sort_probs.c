#include "Sorter.h"
#include <conio.h>

/**compare elts**/
int compare_elt(void* elt1, void* elt2){
    int a = *((int*)elt1);
    int b = *((int*)elt2);
    
    if(a<b)
        return -1;
    else if(a==b)
        return 0;
    else
        return 1;
}

/**print array elts **/
void print_elts(void* elts[], int count){
     int i;
     printf("------------\n");
     printf("Elements : \n");
     printf("------------\n");
     for(i=0; i<count; i++)
         printf("%d\n", *((int*)(elts[i])));
     printf("------------\n");
}



/**test sort**/
void test_sort(void* elts[], int count, void(*sort)(void*[], int, int(*compare_elt)(void*, void*))){
     (*sort)(elts, count, (&compare_elt));
     printf("Results after sort\n");
     print_elts(elts, count);
}




int main(){
    
    /**create the void array and intialize**/
    int int_elts[10] = {10, 9, 8, 9, 4, 5, 6, 1, 7, 9};
    int i;
    int count = 10;
    void* elts[10];
    
    for (i=0; i<10; i++)
        elts[i] = (void*)&int_elts[i];
        
    /**print and check**/    
    print_elts(elts, count);
    
    /**test bubble sort**/
    //printf("BUBBLE SORT : \n");
    //test_sort(elts, count, (&bubble_sort));
    
    /**test selection sort**/
    //printf("SELECTION SORT : \n");
    //test_sort(elts, count, (&selection_sort));

    /**test insertion sort**/
    //printf("INSERTION SORT : \n");
    //test_sort(elts, count, (&insertion_sort));

    /**test shell sort**/
    //printf("SHELL SORT : \n");
    //test_sort(elts, count, (&shell_sort));

    /**test merge sort**/
    //printf("MERGE SORT : \n");
    //test_sort(elts, count, (&merge_sort));

    /**test heap sort**/
    //printf("HEAP SORT : \n");
    //test_sort(elts, count, (&heap_sort));
    
    /**test quick sort**/
    printf("QUICK SORT : \n");
    test_sort(elts, count, (&quick_sort));

    getchar();
    return 0;
}
