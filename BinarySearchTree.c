#include <stdio.h>
#include "BinarySearchTree.h"

int insert(tree** root, void* elt, int(*compare_elt)(void*, void*)){
    /**create the node**/
     tree* temp;
     tree* node = (tree*)malloc(sizeof(tree));

     if (node == NULL)
         return 0;
         
     node->elt = elt;
     node->left = NULL;
     node->right = NULL;
     
     /**empty tree*/
     if(*root == NULL){
         *root = node;
         return 1;
     }
     
     /**traverse and add at the correct location**/
     temp = *root;
     while(temp != NULL){
         if((*compare_elt)(temp->elt, elt) > 0){
             if(temp->left == NULL){
                 temp->left = node;
                 break;
             }
             temp = temp->left;
         }
         else{
             if(temp->right == NULL){
                 temp->right = node;
                 break;
             }
             temp = temp->right;
         }
     }
     
     return 1;
}

/**find an elt in the tree**/
tree* search(tree* root, void* elt, int(*compare_elt)(void*, void*), void(*print_node)(tree*)){
    tree* temp = root;
    int res;
    /**iterate until you find the element**/
    while(temp != NULL){
        res = (*compare_elt)(temp->elt, elt);
        if(res > 0){
            printf("Left at ");
            (*print_node)(temp);
            temp = temp->left;
        }
        else if (res < 0){
            printf("Right at ");
            (*print_node)(temp);
            temp = temp->right;
        else
            return temp;
    }
    return NULL;
}

/**delete an element**/
int delete_elt(tree** root, void* elt, int(*compare_elt)(void*, void*)){
    int res;
    tree* temp;
    
    /**empty case**/
    if(root == NULL)
        return 0;
        
    res = (*compare_elt)((*root)->elt, elt);
    if(res > 0)
        return delete_elt(&((*root)->left), elt, compare_elt);
    else if(res < 0)
        return delete_elt(&((*root)->right), elt, compare_elt);
    else{
         /**no children**/
         if((*root)->left == NULL && (*root)->right == NULL){
             temp = (*root);
             (*root) = NULL;
             free(temp);
         }
         /**no left child**/
         else if((*root)->right == NULL){
              temp = (*root);
              (*root) = temp->left;
              free(temp);
         }
         /** no right child **/
         /** find the smallest elt in the right sub tree and replace withit **/
         else if((*root)->left == NULL){
              temp = (*root)->right;
              /**has no left elt**/
              if(temp->left == NULL){
                  temp = (*root);
                  (*root) = temp->right;
                  free(temp);
              }
         }
    }
}
        


/**find the min elt in the tree**/
tree* min(tree* root){
    tree* temp = root;
    
    if(temp == NULL) 
        return NULL;
    
    while(temp->left != NULL)
        temp = temp->left;
        
    return temp;
}

/**find the max elt in the tree**/
tree* max(tree* root){
    tree* temp = root;
    
    if(temp == NULL)
        return NULL;
        
    while(temp->right != NULL)
        temp = temp->right;
        
    return temp;
}

/**inorder traversal**/
tree* inorder(tree* root, void(*print_node)(tree*)){
      if(root == NULL)
          return NULL;
          
      inorder(root->left, print_node);
      (*print_node)(root);
      inorder(root->right, print_node);
}

/**inorder successor **/
tree* inorder_successor(tree* root){
      tree* temp;
      
      /**no right child**/
      if(root == NULL || root->right == NULL)
          return NULL;
          
      temp = root->right;
      while(temp->left != NULL)
          temp = temp->left;
      return temp;
}

/**inorder predecessor **/
tree* inorder_predecessor(tree* root){
      tree* temp;
      
      /**no right child**/
      if(root == NULL || root->left == NULL)
          return NULL;
          
      temp = root->left;
      while(temp->right != NULL)
          temp = temp->right;
      return temp;
}


/**preorder traversal**/
tree* preorder(tree* root, void(*print_node)(tree*)){
      if(root == NULL)
          return NULL;
      
      (*print_node)(root);
      preorder(root->left, print_node);
      preorder(root->right, print_node);
}

/**preorder successor**/
tree* preorder_successor(tree* root){
      tree* temp;
      
      if(root == NULL)
          return NULL;

      if(root->left == NULL)
          return root->right;
      else
          return root->left;
}



/**postorder traversal**/
tree* postorder(tree* root, void(*print_node)(tree*)){
      if(root == NULL)
          return NULL;
      
      postorder(root->left, print_node);
      postorder(root->right, print_node);
      (*print_node)(root);
}
