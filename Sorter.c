#include "Sorter.h"
#include <stdio.h>


/** 
Bubble sort :
    - Compare adjacent pairs and swap if necessary, continue until no swaps have occurred
    - Time Complexity : O(n^2) 
**/
void bubble_sort(void* elts[], int count, int(*compare_elt)(void*, void*)){
     void* temp;
     int i, swaps = 0;
     int iter = count;
     /**iterate until no swaps has occured previously**/
     do{
        swaps = 0;
        /**iterate in pairs from the beginning**/
        /**optimize by not looking at the last n-1 items, 
        as at each iteration the nth largest elt posiyion is fixed**/
        for (i=0; i<iter - 1; i++){
            if((*compare_elt)(elts[i], elts[i+1]) > 0){
                temp = elts[i];
                elts[i] = elts[i + 1];
                elts[i + 1] = temp;
                swaps += 1;
            }
        }
        /**optimization**/
        iter = iter - 1;
     }while(swaps != 0);
}


/**
Selection Sort :
          - Iterate and find the min elt
          - replace the first elt
          - iterate over the remaining array and dod the same
          - Time Complexity : O(n^2)
**/
void selection_sort(void* elts[], int count, int(*compare_elt)(void*, void*)){
     int i, j, min_elt_index;
     void* temp;
     /**iterate over the array**/
     for(i=0; i<count; i++){
         /**find the min elt and replace with the first elt in the iteration**/
         min_elt_index = i;
         for(j=i+1; j<count; j++){
             if ((*compare_elt)(elts[min_elt_index], elts[j]) > 0){
                 min_elt_index = j;
             }
         }
         /**replace the min elt with the first element in the iteration**/
         if(min_elt_index != i){
             temp = elts[i];
             elts[i] = elts[min_elt_index];
             elts[min_elt_index] = temp;
         }
     }
}

/**
Insertion Sort :
          - sort it while insertion itself
          - Create a hole and do swaps until all k-1 entries are sorted
          - Time complexity : O(n^2)
          - Worst Case Comparisons and swaps: O(n^2)
          - Best Case Comparison and swaps : O(n) and 1
**/
void insertion_sort(void* elts[], int count, int(*compare_elt)(void*, void*)){
     int i, j, k;
     void* hole_elt;
     /**iterate over each entry - outer loop**/
     for(i=1; i<count; i++){
          j = 0;
         /**get the position for the hole**/
         while(((*compare_elt)(elts[i], elts[j]) > 0) && (j < i)){
             j++;
         }
         if(j!=i){
             /**swaps to fill hole**/
             k = i;
             hole_elt = elts[i];
             while(k > j){
                 elts[k] = elts[k-1];
                 k--;
             }
             elts[j] = hole_elt;
         }
     }
}


/**
Shell Sort :
      - Sort based on gaps as indices
      - Worst case time complexity : O(n^2)
      - Best Case time complexity : depends
        - 4^k + 3.2^(k-1) + 1 : O(n^(4/3))
**/
void shell_sort(void* elts[], int count, int(*compare_elt)(void*, void*)){
     int gaps[6] = {23, 19, 8, 5, 3, 1};
     int gap_count  = 6;
     int i,j,k,l,iter_gap;
     void* temp;
     
     /**do it for each gap item**/
     for(i=0; i<gap_count; i++){
         iter_gap = gaps[i];
         if (iter_gap > count)
             continue;
         /**start from the first element and swap it with the correpsonding gap elt**/
         for(l=0; l<count; l++){
                  for(j=l + iter_gap; j<count; j+=iter_gap){
                                  k = j;
                                  while((k-iter_gap >= 0) && ((*compare_elt)(elts[k], elts[k - iter_gap]) < 0)){
                                                    temp = elts[k];
                                                    elts[k] = elts[k-iter_gap];
                                                    elts[k-iter_gap] = temp;
                                                    k-=iter_gap;
                                  }
                  }
         }
     }
}

/**
Merge Sort :
      - Sort by splitting the array sorting it and merging it
      - Time Complexity : O(nlogn)
**/

void merge(void* elts[], int start, int middle, int end, int count, int(*compare_elt)(void*, void*)){
     void** temp = (void**)malloc(sizeof(void*) * count);
     
     int arr1 = start;
     int arr2 = middle + 1;
     int tempIndex = arr1;
     
     /**merge phase**/
     while(arr1 <= middle && arr2 <= end){
         if((*compare_elt)(elts[arr1], elts[arr2]) > 0){
             *(temp + tempIndex) = elts[arr2];
             arr2++;
         }
         else{
              *(temp + tempIndex) = elts[arr1];
              arr1++;
         }
         tempIndex++;
     }
     /**copy remaining elts**/
     while(arr1 <= middle){
         *(temp + tempIndex) = elts[arr1];
         arr1++;
         tempIndex++;
     }
     while(arr2 <= end){
         *(temp + tempIndex) = elts[arr2];
         arr2++;
         tempIndex++;
     }
     /**copy back to original array **/
     for(tempIndex=start; tempIndex<=end; tempIndex++){
         elts[tempIndex] = *(temp + tempIndex);
     }
     
     free(temp);
}

void m_sort(void* elts[], int start, int end, int count, int(*compare_elt)(void*, void*)){
     /**single element case**/
     if (end <= start)
         return;
     
     int middle = start + ( (end - start) / 2 );
     m_sort(elts, start, middle, count, compare_elt);
     m_sort(elts, middle + 1, end, count, compare_elt);
     merge(elts, start, middle, end, count, compare_elt);
}

void merge_sort(void* elts[], int count, int(*compare_elt)(void*, void*)){
     m_sort(elts, 0, count - 1, count, compare_elt);
}


/**
Heap Sort :
     - build a heap first
     - pop from the heap and form the sorted result
     - Time complexity : O(nlogn)
**/
void swap(void* elts[], int a, int b){
     void* temp;
     temp = elts[a];
     elts[a] = elts[b];
     elts[b] = temp;
}


void sink(void* elts[], int start, int end, int(*compare_elt)(void*, void*)){
     int root = start;
     int swap_index = root;
     int child;
     while(2*root + 1 <= end){
         child = 2*root + 1;
         swap_index  = root;
         if((*compare_elt)(elts[swap_index], elts[child]) < 0)
             swap_index = child;
         if (child + 1 <= end && ((*compare_elt)(elts[swap_index], elts[child + 1]) < 0))
             swap_index = child + 1;
         if (swap_index != root){
             swap(elts, swap_index, root);
             root = swap_index;
         }
         else
             return;
     }
}

void heapify(void* elts[], int count, int(*compare_elt)(void*, void*)){
     int start = (count - 2) / 2;
     
     while (start >= 0){
           sink(elts, start, count -1, compare_elt);
           start--;
     }
}

void heap_sort(void* elts[], int count, int(*compare_elt)(void*, void*)){
     //build a heap firstly
     heapify(elts, count, compare_elt);
     
     //form the sorted array from the heap
     int end = count - 1;
     while(end > 0){
         swap(elts, 0, end);
         sink(elts, 0, --end, compare_elt);
     }
}

/**quick sort (FIX IT !!!)
    - choose a pivot and arrange elts to left and right to fix it
    - recursively sort both sub-arrays
    - Time Complexity : O(nlogn)
**/

void q_sort(void* elts[], int start, int end, int(*compare_elt)(void*, void*)){
     int lo = start;
     int hi = end;
     
     /**first elt is the pivot**/
     int pivot = lo;
     int left = lo + 1;
     int right = hi;
     
     if (lo >= hi || end - start <= 0)
         return;
     
     while(left <= right){
         
         while((*compare_elt)(elts[pivot], elts[left]) >= 0){
             left++;
             if (left > right)
                 break;
         }
         
         while((*compare_elt)(elts[pivot], elts[right]) < 0){
             right--;
             if(right < left)
                 break;
         }
         
         if(left < right){
             swap(elts, left, right);
             left++;
             right--;
         }
         
     }
     
     swap(elts, pivot, right);
     q_sort(elts, lo, pivot-1, compare_elt);
     q_sort(elts, pivot+1, hi, compare_elt);
}

void quick_sort(void* elts[], int count, int(*compare_elt)(void*, void*)){
     q_sort(elts, 0, count - 1, compare_elt);
}


