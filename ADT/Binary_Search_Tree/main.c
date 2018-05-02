#include <stdio.h>
#include "BST.h"
int main()
{
    int x;
    BST* tree = bst_create();
    x = 7;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 4;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 9;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 2;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 5;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 6;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 1;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 8;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 3;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    x = 10;
    printf("insert %d\n", x);
    tree = bst_insert(tree, x);
    printf("tree in preorder:\n");
    bst_print_preorder(tree);
    printf("\ntree in inorder:\n");
    bst_print_inorder(tree);
    printf("\ntree in postorder:\n");
    bst_print_postorder(tree);

    x = 5;
    printf("\nSearch for %d:\n", x);
    BST* aux = bst_search(tree, x);
    int key;
    int left;
    int right;
    if(aux!=NULL){
        key = aux->key;
        if(aux->left!=NULL)
            left = aux->left->key;
        else left = -1;
        if(aux->right!=NULL)
            right = aux->right->key;
        else right = -1;
        printf("key: %d, left: %d, right: %d\n", key, left, right);
    }else printf("not found!\n");

    x = 3;
    printf("remove %d\n", x);
    tree = bst_remove(tree, x);
    printf("tree in preorder:\n");
    bst_print_preorder(tree);
}
