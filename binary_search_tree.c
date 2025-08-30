# include <stdio.h>
# include <stdlib.h>


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

};
struct Node* root = NULL;

struct Node*min_value(struct Node* node){
    struct Node*current= node;
    while(current&&current->left!=NULL){
        current=current->left;
    }
    return current;
}

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

struct Node* delete_node(struct Node*root,int  value){
    if (root==NULL){
        return root;
    }

    if (root->data<value){
        root->right = delete_node(root->right,value);
        }
    else if (root->data>value){
        root->left= delete_node(root->left,value);
        }
    else {
        if (root->left==NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            struct Node* sucessor= min_value(root->right);
            root->data= sucessor->data;
            root->right= delete_node(root->right,sucessor->data);

        }
    }
    return root;
}
struct Node* search(struct Node*root, int value){
    if(root==NULL || root->data==value){
        return root;
    }
    if(root->data<value){
        return search(root->right,value);
    }
    
    return search(root->left,value);
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main(){
    int value;
    int choice=1;

    while (choice !=0){
        printf("Enter your choice\n");
        printf("1 to insert the value\n"
        "2 to delete\n3 to search\n4: Display (Inorder)\n0: Exit\n");
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
            root=insert(root, value);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root= delete_node(root,value);
            break;
        case 3:
            printf("Enter the value to search ");
            scanf("%d", &value);
            struct Node* result= search(root,value);
            if (result != NULL)
                    printf("%d found in tree.\n", value);
                else
                    printf("%d not found in tree.\n", value);
           
            break;
        case 4:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        default:
        printf("Invalid Choice\n");
            break;
        }
    }
}