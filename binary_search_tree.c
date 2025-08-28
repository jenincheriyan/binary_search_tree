# include <stdio.h>
# include <stdlib.h>


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

};
struct Node* root = NULL;

struct Node* insert(struct Node*root, int value)
{   
    struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
   
    if (root= NULL){
        newnode->data= value;
        newnode->left= NULL;
        newnode->right=NULL;
        return newnode;
    }
    
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else{
        root->right=insert(root->right,value);
    }
    return root;
}
