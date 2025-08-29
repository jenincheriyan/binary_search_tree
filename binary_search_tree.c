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
   
    if (root==NULL){
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


void main(){
    int value;
    int choice=1;

    while (choice !=0){
        printf("Enter your choice\n");
        printf("1 to insert the value: ");
        if(scanf("%d", &choice)!=1){
            while(getchar()!='\n');
        }
        switch (choice)
        {
        case 0:
            printf("....Exit....");
            choice=0;
        case 1:
        printf("Enter the value to insert: ");
        scanf("%d", &value);
            insert(root, value);
            break;
        
        default:
        printf("Invalid Choice\n");
            break;
        }
    }
}