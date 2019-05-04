#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void Preorder(struct Node *root)
{
    if(root == NULL) return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node *root)
{
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void Postorder(Node *root)
{
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

Node* Insert(Node *root,int data)
{
    if(root == NULL)
    {
        root = new Node(); // for C++ if you using C write (struct node *)malloc(sizeof(node)) instead of new node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data)
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);
    return root;
}

int main()
{
    Node* root = NULL;
    int i,j,n,k,val;
    printf("How many element insert into a binary tree..\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&val);
        root=Insert(root,val);
    }
    printf("Preorder: ");
    Preorder(root);
    printf("\n");
    printf("Inorder: ");
    Inorder(root);
    printf("\n");
    printf("Postorder: ");
    Postorder(root);
    printf("\n");
}
