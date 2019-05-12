#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    node *left;
    node *right;

};

struct node* newNode(int data){
    struct node*  node = (struct node*) malloc(sizeof(struct node));

    node -> data = data;
    node -> left = NULL;
    node ->right = NULL;

    return(node);
}

void pre_order(struct node *node)
{
    if(node == NULL){
        return;
    }

    printf("%d ",node->data);

    pre_order(node->left);
    pre_order(node->right);
}


void post_order(struct node * node)
{

    if(node == NULL){
        return;
    }

    post_order(node -> left);
    post_order(node -> right);

    printf("%d ", node->data);
}


void in_order(struct node* node){

    if(node == NULL){
        return;
    }

    in_order(node -> left);
    printf("%d ", node->data);
    in_order(node -> right);
}


int main()
{
    struct node* root = newNode(1);

    root -> left = newNode(2);
    root -> right = newNode(3);
    root ->left->left = newNode(4);
    root -> left ->right = newNode(5);

    printf("Printing in pre_order: ");

    pre_order(root);

    printf("\n");

    printf("Printing in post_order: ");
    post_order(root);
    printf("\n");

    printf("Printing in in_order: ");
    in_order(root);

    printf("\n");


    return 0;
}
