#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

typedef struct treeNode* treePointer;
typedef struct treeNode{
    char data;
    treePointer leftChild, rightChild;
};

treeNode tree[4000000];

long long calculate(treePointer ptr,long long ans,queue<long long> q)
{
    long long num1=0,num2=0;
    if(ptr)
    {
        q.push(calculate(ptr->leftChild,ans,q));
        q.push(calculate(ptr->rightChild,ans,q));
        switch(ptr->data)
        {
            case '+':
                num1=q.front();q.pop();
                num2=q.front();q.pop();
                ans+=(num1+num2);
                cout<<num1<<"+"<<num2<<endl;
                return ans;
            case '-':
                num1=q.front();q.pop();
                num2=q.front();q.pop();
                ans+=(num1-num2);
                cout<<num1<<"-"<<num2<<endl;
                return ans;
            case '*':
                num1=q.front();q.pop();
                num2=q.front();q.pop();
                ans+=(num1*num2);
                cout<<num1<<"*"<<num2<<endl;
                return ans;
            case '/':
                num1=q.front();q.pop();
                num2=q.front();q.pop();
                ans+=(num1/num2);
                cout<<num1<<"/"<<num2<<endl;
                return ans;
            default: return (ptr->data - 48);
        }
    }
    return ans;
}

int main()
{
    int height;
    cin>>height;
    long long ans=0;
  	queue<long long> q;
    for(long long i=1;i<=pow(2,height)-1;i++)
    {
        string str;
        cin>>str;
        if(str!="-1")
        {
            tree[i].data=str[0];
            if(i*2 <= pow(2,height)-1)
            {
                tree[i].leftChild = &tree[i*2];
                if(i*2+1 <= pow(2,height)-1)
                    tree[i].rightChild = &tree[i*2+1];
                else tree[i].rightChild = NULL;
            }
            else tree[i].leftChild = NULL;
        }
        else
        {
            if(i%2==0)
                tree[i/2].leftChild=NULL;
            else if(i%2==1)
                tree[i/2].rightChild=NULL;
        }
    }
    cout<<calculate(&tree[1],ans,q);
    return 0;
}
