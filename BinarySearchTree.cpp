#include <iostream>
#include <queue>
using namespace std ;

struct Node
{
    int data;
    Node* left;
    Node* right;
} ;

Node* GetNewNode(int data)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node* InsertNode(Node* root, int data)
{
    if (root == NULL){root = GetNewNode(data); return root;   }
    else if (root->data<=data){root->right = InsertNode(root->right,data);}
    else{ root->left =  InsertNode(root->left,data);}
}

Node** InsertNode(Node** root,int data)
{
    if(*root == NULL){ *root = GetNewNode(data); return root;  }
    else if( (**root).data <=data ){(**root).right=InsertNode((**root).right,data);}
    else{(**root).left=InsertNode((**root).left,data);}
}

void Preorder(Node* TreeRoot)
{
    if(TreeRoot==NULL) return;
    cout<<TreeRoot->data<<" ";
    Preorder(TreeRoot->left);
    Preorder(TreeRoot->right);
}
void Inorder(Node* TreeRoot)
{
    if(TreeRoot==NULL) return;
    Preorder(TreeRoot->left);
    cout<<TreeRoot->data<<" ";
    Preorder(TreeRoot->right);
}
void Postorder(Node* TreeRoot)
{
    if(TreeRoot==NULL) return;
    Preorder(TreeRoot->left);
    Preorder(TreeRoot->right);
    cout<<TreeRoot->data<<" ";
}

int FindMin(Node* root)
{
    if(root==NULL) return -1;
    else if(root->left ==NULL) return root.data;
    return FindMin(root->left);
}

int FindMax(Node* root)
{
    if(root==NULL) return -1;
    else if(root->right ==NULL) return root.data;
    return FindMax(root->right);
}

void LevelOrder(Node* TreeRoot)
{
    queue<Node*> Que;
    if(TreeRoot==NULL) return;
    Que.push(root);
    while(!Q.empty()) {
        /* code */
    Node* current = Que.front();
    if(current->left != NULL) Que.push(TreeRoot->left);
    if(current->right!= NULL) Que.push(TreeRoot->right);
    Que.pop();
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    Node* root;
    root = NULL;
    InsertNode(&root,20);
    InsertNode(&root,30);
    InsertNode(&root,5);

    Preorder(root); cout<<": Preorder"<<"\n";
    Inorder(root);  cout<<": Inorder"<<"\n";
    Postorder(root);cout<<": Postorder"<<"\n";

    return 0;
}
