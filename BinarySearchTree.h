/**tree node**/

typedef struct tree_t
{
    void* elt;
    struct tree_t* left;
    struct tree_t* right;
}tree;

int insert(tree** root, void* elt, int(*compare_elt)(void*, void*));
tree* search(tree* root, void* elt, int(*compare_elt)(void*, void*), void(*print_node)(tree*));
int delete_elt(tree** root, void* elt, int(*compare_elt)(void*, void*));
tree* min(tree* root);
tree* max(tree* root);
tree* inorder(tree* root, void(*print_node)(tree*));
tree* inorder_successor(tree* root);
tree* inorder_predecessor(tree* root);
tree* preorder(tree* root, void(*print_node)(tree*));
tree* preorder_successor(tree* root);
tree* postorder(tree* root, void(*print_node)(tree*));
