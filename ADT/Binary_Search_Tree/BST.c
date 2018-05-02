#include "BST.h"
#include<stdio.h>

BST* bst_create(){
    return NULL;
}


BST* bst_create_child(BST* parent, int key){
    BST* node = (BST*)malloc(sizeof(BST));
    node->key = key;
    node->parent = parent;
    node->left = node->right = NULL;
    return node;
}

BST* bst_insert(BST* root, int key){
    if(root==NULL)
        return bst_create_child(root, key);
    else if(key < root->key){
        if(root->left==NULL)
            root->left = bst_create_child(root, key);
        else root->left = bst_insert(root->left, key);
    }
    else if(key > root->key){
        if(root->right==NULL)
            root->right = bst_create_child(root, key);
        else root->right = bst_insert(root->right, key);
    }
    return root;
}

BST* bst_search(BST* root, int key){
    if(root == NULL)
        return NULL;
    else if(key < root->key)
        return bst_search(root->left, key);
    else if(key > root->key)
        return bst_search(root->right, key);
    else return root;
}

BST* bst_remove(BST* root, int key){
    if(root==NULL) return NULL;
    else if(key < root->key)
        root->left = bst_remove(root->left, key);
    else if(key > root->key)
        root->right = bst_remove(root->right, key);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            BST* aux = root;
            root = root->right;
            root->parent = aux->parent;
            free(aux);
        }
        else if(root->right == NULL){
            BST* aux = root;
            root = root->left;
            root->parent = aux->parent;
            free(aux);
        }
        else{
            BST* successor = root->right;
            while(successor->left!=NULL)
                successor = successor->left;
            root->key = successor->key;
            successor->key = key;

            if(successor->parent->left == successor)
                successor->parent->left = successor->right;
            else successor->parent->right = successor->right;
            if(successor->right!=NULL)
                successor->right->parent=successor->parent;
            free(successor);
        }
    }
    return root;
}


void bst_print_preorder(BST* root){
    if(root!=NULL){
        printf("%d\t", root->key);
        bst_print_preorder(root->left);
        bst_print_preorder(root->right);
    }
}
void bst_print_inorder(BST* root){
    if(root!=NULL){
        bst_print_inorder(root->left);
        printf("%d\t", root->key);
        bst_print_inorder(root->right);
    }
}
void bst_print_postorder(BST* root){
    if(root!=NULL){
        bst_print_postorder(root->left);
        bst_print_postorder(root->right);
        printf("%d\t", root->key);
    }
}

