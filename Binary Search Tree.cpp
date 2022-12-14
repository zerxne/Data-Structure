#include<iostream>
#include<queue>
using namespace std;

struct treeNode{
    treeNode *left;
    treeNode *right;
    treeNode *parent;
    int data;
};

treeNode *bst;
queue<int> q;

void inorder(treeNode *cur)
{
    if(cur)
    {
        inorder(cur->left);
        q.push(cur->data);
        inorder(cur->right);
    }
}

void insert_bst(int data)
{
    treeNode *parent=NULL;
    treeNode *current=bst;
    treeNode *insertNode=new treeNode();
    insertNode->data=data;
    while(current!=NULL&&current->data!=data)
    {
        parent=current;
        if(insertNode->data>current->data)
            current=current->right;
        else
            current=current->left;
    }
    if(current==NULL)
    {
        insertNode->parent=parent;
        if(parent==NULL)
            bst=insertNode;
        else if(insertNode->data<parent->data)
            parent->left=insertNode;
        else
            parent->right=insertNode;
    }
}
/*
void delete_bst(int data)
{
    treeNode *delNode=NULL;
    treeNode *cur=bst;
    while(cur!=NULL&&cur->data!=data)
    {
        if(data>cur->data) cur=cur->right;
        else cur=cur->left;
    }
    if(cur==NULL)
        cout<<"cannot delete"<<endl;
    else if(cur->data==data)
    {
        delNode=cur;
        treeNode *delPar=NULL;
        treeNode *l=NULL;
        treeNode *r=NULL;
        treeNode *m=NULL;
        if(delNode->parent!=NULL) delPar=delNode->parent;
        if(delNode->left!=NULL) l=delNode->left;
        if(delNode->right!=NULL) r=delNode->right;
        if(l==NULL&&r==NULL)
        {
            if(delPar==NULL)
            {
                delNode=bst=NULL;
                free(delNode);
            }
            else
            {
                if(delPar->left==delNode) delPar->left=NULL;
                else delPar->right=NULL;
                delNode=NULL;
                free(delNode);
            }
        }
        else if(l==NULL&&r!=NULL)
        {
            if(delPar==NULL)
            {
                r->parent=NULL;
                bst=r;
            }
            else
            {
                if(delNode==delPar->left) delPar->left=r;
                else delPar->right=r;
                r->parent=delPar;
            }
            delNode=NULL;
            free(delNode);
        }
        else if(l!=NULL&&r==NULL)
        {
            if(delPar==NULL)
            {
                l->parent=NULL;
                bst=l;
            }
            else
            {
                if(delNode==delPar->left) delPar->left=l;
                else delPar->right=l;
                l->parent=delPar;
            }
            delNode=NULL;
            free(delNode);
        }
        else
        {
            treeNode *tmp=l;
            while(tmp&&tmp->right!=NULL)
            {
                tmp=tmp->right;
            }
            m=tmp;
            if(m==l)
            {
                m->right=r; r->parent=m;
                m->parent=delPar;
                if(delPar->left==delNode) delPar->left=m;
                else delPar->right=m;
            }
            else
            {
                m->parent->right=NULL;
                m->parent=delPar;
                m->left=l; l->parent=m;
                m->right=r; r->parent=m;
                if(delPar->left==delNode) delPar->left=m;
                else delPar->right=m;
            }
            delNode=NULL;
            free(delNode);
        }
    }
}
*/

treeNode* delete_bst2(treeNode *root, int data)
{
    treeNode* current = NULL;
    treeNode* parent = NULL;
    bool hasLeft = false;

    if(root){
        current = root;
        while(current){

            if(data == current->data){
                break;
            }
            hasLeft = false;
            parent = current;
            if(data > current->data){
                current = current->right;
            }
            else{
                hasLeft = true;
                current = current->left;
            }
        }
        if(current){

            if(!current->left && !current->right){

                if(!parent){
                    return NULL;
                }

                if(hasLeft){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
            }

            else if(!current->left){

                if(!parent){
                    return current->right;
                }

                if(hasLeft){
                    parent->left = current->right;
                }
                else{
                    parent->right = current->right;
                }
            }

            else if(!current->right){

                if(!parent){
                    return current->left;
                }

                if(hasLeft){
                    parent->left = current->left;
                }
                else{
                    parent->right = current->left;
                }

            }
            else{
                treeNode *tmp=current->left;
                while(tmp&&tmp->right!=NULL)
                    tmp=tmp->right;
                treeNode *m=tmp;
                int replaceData = m->data;
                current->data = replaceData;
                current->left = delete_bst2(current->left, replaceData);
            }

            return root;
        }
    }

    cout << "cannot delete" << endl;
    return root;
}

void search_bst(treeNode *cur,int data)
{
    inorder(bst);
    if(!q.empty())
    {
        for(int i=0;i<data-1;i++)
        {
            q.pop();
        }
        cout<<q.front();
        while(!q.empty())
            q.pop();
    }
    cout<<endl;
}

int height(treeNode *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        if(leftHeight>=rightHeight)
            return leftHeight+1;
        else
            return rightHeight+1;
    }
}

void traversal()
{
    queue<treeNode*> q;
    if(bst!=NULL)
        q.push(bst);
    while(!q.empty())
    {
        treeNode *cur=q.front();
        q.pop();
        cout<<cur->data<<" ";
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
    cout<<endl;
}

int main()
{
    while(true)
    {
        string input;
        cin>>input;
        int data;
        if(input=="insert")
        {
            cin>>data;
            insert_bst(data);
        }
        else if(input=="delete")
        {
            cin>>data;
            //delete_bst(data);
            bst=delete_bst2(bst,data);
        }
        else if(input=="search")
        {
            cin>>data;
            search_bst(bst,data);
        }
        else if(input=="height")
        {
            cout<<height(bst)<<endl;
        }
        else if(input=="traversal")
        {
            traversal(); break;
        }
        else
            cout<<"error"<<endl;
    }
    return 0;
}
