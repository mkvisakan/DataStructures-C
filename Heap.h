//structure of heap
typedef struct heap_t {
    void** elts;
    int size;
    int item_count;
    int(*compare)(void*, void*);
    void(*print_elt)(void*);
} heap;

heap* initialize(int initial_capacity, int(*compare)(void*, void*), void(*print_elt)(void*));
int insert(heap** h, void* elt);
void display_heap(heap* h);
void* pop(heap** h);
int size(heap* h);
        
