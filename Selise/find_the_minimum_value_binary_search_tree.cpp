#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;

   struct node* left;
   struct node* right;

};


struct node* newNode(int data)
{
        struct node* node = (struct node*) malloc(sizeof(struct node));

        node -> data = data;
        node -> left = NULL;
        node -> right = NULL;

        return (node);
}


struct node* insert_node(struct node* node, int data)
{

        if(node == NULL){
            return(newNode(data));
        }

        else{
            if(data <= node->data){
                node ->left = insert_node(node->left, data);
            }
            else{
                node-> right = insert_node(node->right, data);
            }

            return node;
        }
}


int min_value(struct node* node)
{
    struct node* current = node;

    while(current ->left != NULL){
       // printf("----%d ", current->data);
        current = current->left;
    }

    return (current -> data);
}


int main()
{
    struct node* root = NULL;

    root = insert_node(root,5);

    for(int i = 1; i <= 6  ; i++){
        insert_node(root, i);
    }

    insert_node(root,1);
    insert_node(root,6);

    int mn = min_value(root);

     printf("%d\n", mn);


    return 0;
}


