#include<iostream>
using namespace std;

typedef struct treeNode *treePointer;
typedef struct treeNode
{
    int data;
    treePointer leftChild, rightChild;
};

void preorder(treePointer root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

void inorder(treePointer root)
{
    if(root)
    {
        inorder(root->leftChild);
        cout<<root->data<<" ";
        inorder(root->rightChild);
    }
}

void postorder(treePointer root)
{
    if(root)
    {
        postorder(root->leftChild);
        postorder(root->rightChild);
        cout<<root->data<<" ";
    }
}

int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        treeNode tree[1000];
        for(int j=1;j<=m;j++)
        {
            cin>>tree[j].data;
            if(j*2 <= m){
                tree[j].leftChild = &tree[j*2];
                if(j*2+1 <= m){
                    tree[j].rightChild = &tree[j*2+1];
                }
                else tree[j].rightChild = NULL;
            }
            else tree[j].leftChild = NULL;
        }
        preorder(&tree[1]);
        cout<<endl;
        inorder(&tree[1]);
        cout<<endl;
        postorder(&tree[1]);
        cout<<endl;
    }
    return 0;
}
