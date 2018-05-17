#include <stdlib.h>
typedef struct bst BST;

struct bst{
    int key;
    BST* parent;
    BST* left;
    BST* right;
};

BST* bst_create();
BST* bst_create_child(BST* parent, int key);
BST* bst_insert(BST* root, int key);
BST* bst_search(BST* root, int key);
BST* bst_remove(BST* root, int key);
void bst_print_preorder(BST* root);
void bst_print_inorder(BST* root);
void bst_print_postorder(BST* root);


