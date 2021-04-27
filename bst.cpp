#include<bits/stdc++.h>
using namespace std;
class bst
{
    public:
    int data;
    bst *left;
    bst *right;
    bst(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
bool search(bst *root,int data)
{
    if(!root){return false;}
    if(root->data==data){
        return true;
    }
    else if(root->data<data)
    {
        return search(root->right,data);
    }
    else if(root->data>=data)
    {
        return search(root->left,data);
    }
    return false;
}
bst* insert(bst *root,int data)
{
    if(!root){
        return new bst(data);
    }
    else if(root->data<data)
    {
        root->right=insert(root->right,data);
    }
    else
    {
        root->left=insert(root->left,data);
    }return root;
}
void preorder(bst *root)
{
    if(!root){return;}
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(bst* root)
{
    if(!root){return;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(bst* root)
{
    if(!root){return;}
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelorder(bst* root)
{
    queue<bst*> q;
    if(!root){return;}
    q.push(root);
    while(!q.empty()){
        bst* c=q.front();
        cout<<c->data<<" ";
        if(c->left!=NULL){
            q.push(c->left);
        }
        if(c->right!=NULL){
            q.push(c->right);
        }
        q.pop();//REMOVING ELEMENT FROM THE QUEUE
    }
}
bst* min(bst *root)
{
    if(!root){return NULL;}
    while(root->left!=NULL)
    {root=root->left;
    }return root;
}
bst* max(bst *root)
{
    if(!root){return NULL;}
    while(root->right!=NULL)
    {root=root->right;
    }return root;
}
bst* Delete(bst* root,int data)
{
    if(!root){return root;}
    else if(data<root->data){root->left=Delete(root->left,data);}
    else if(data>root->data){root->right=Delete(root->right,data);}
    else//IF THE INTENDED ELEMENT IS FOUND
    {
        if(root->left==NULL && root->right==NULL)//CASE 1:NO CHILD(LEAF NODE)
        {delete root;root=NULL;}
        else if(root->left==NULL)//CASE 2:ONE CHILD:THERE'S NO LEFT CHILD
        {
            bst* temp=root;root=root->right;
            delete temp;
        }
        else if(root->right==NULL)//CASE 2:ONE CHILD:THERE'S NO RIGHT CHILD
        {bst* temp=root;
        root=root->left;
        delete temp;}
        else//CASE 3:TWO CHILDREN
        {
            bst* temp=min(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }return root;
}
int main()
{
    int n;int d;bst* root=NULL;
    cout<<"Enter number of nodes ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        root=insert(root,d);
    }int s;
    cout<<"Enter the element to be searched ";cin>>s;
    cout<<"Found(1) or Not Found(0): "<<search(root,s)<<endl;
    cout<<"Preorder traversal: ";preorder(root);cout<<endl;
    cout<<"Inorder traversal: ";inorder(root);cout<<endl;
    cout<<"Postorder traversal: ";postorder(root);cout<<endl;
    cout<<"Levelorder traversal: ";levelorder(root);cout<<endl;
    cout<<"Minimum element in BST: "<<min(root)->data<<endl;
    cout<<"Maximum element in BST: "<<max(root)->data<<endl;
    int de;cout<<"Enter element to be deleted ";cin>>de;
    root=Delete(root,de);
    inorder(root);
}