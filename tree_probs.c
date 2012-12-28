#include <stdio.h>
#include <conio.h>
#include "BinarySearchTree.h"

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

/**print node**/
void print_node(tree* node){
     printf("%d\n", *((int*)node->elt));
}


void test_tree(){
     int i;
     int elts[10] = {5, 6, 1, 2, 10, 9, 3, 4, 7, 8};
     
     tree* root = NULL;
     
     for(i=0; i<10; i++)
         insert(&root, (void*)&elts[i], &compare_elt);
     
     printf("Min Element : ");
     print_node(min(root));

     printf("Max Element : ");
     print_node(max(root));
     
     printf("Search for 8 : \n");
     print_node(search(root, (void*)&elts[9], &compare_elt, &print_node));
          
     printf("========================\n");
     printf("Inorder Traversal : \n");
     printf("========================\n");
     inorder(root, &print_node);
     
     printf("========================\n");
     printf("preorder Traversal : \n");
     printf("========================\n");
     preorder(root, &print_node);
     
     printf("========================\n");
     printf("postorder Traversal : \n");
     printf("========================\n");
     postorder(root, &print_node);
}


int main(){
    
    test_tree();
    
    getchar();
    return 0;
}
