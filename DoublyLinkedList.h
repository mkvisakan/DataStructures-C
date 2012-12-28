/** Node **/
typedef struct node_t {
        void* elt;
        struct node_t* next;
        struct node_t* prev;
} node;


int append_last(node**, void*);
int append_first(node**, void*);
int delete_at(node**, int);
int delete_elt(node**, void*);
void print_list(node* head, void (*print_elt)(void*));
void reverse_list(node**);
void recursive_reverse_list(node**);
