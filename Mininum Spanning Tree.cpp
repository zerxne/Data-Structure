#include<iostream>
#include<algorithm>
using namespace std;

struct Edge
{
    int u,v,w;
};
Edge edge[500000];
int num[2000],parent[2000]; //num:記集合的數字

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

int findParent(int a)
{
    while(a!=parent[a])
    {
        a=parent[a];
    }
    return a;
}

int main()
{
    int n,m,ans=0,cnt=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        num[i]=1;
    }
    sort(edge,edge+m,cmp);
    for(int i=0;i<m&&n>cnt;i++)
    {
        int a,b;
        a=findParent(edge[i].u);
        b=findParent(edge[i].v);
        if(a!=b)
        {
            if(num[a]>num[b])
            {
                parent[b]=a;
                num[a]+=num[b];
            }
            else
            {
                parent[a]=b;
                num[b]+=num[a];
            }
            ans+=edge[i].w;
            cnt++;
        }
    }
    if(cnt==(n-1)) cout<<ans<<endl;
    else cout<<"error"<<endl;
    return 0;
}
