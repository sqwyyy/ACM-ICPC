#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#define MAXN 200000+100
using namespace std;
int father[MAXN],p[MAXN];
int n,m;
struct node
{
    int v,e,c;
}G[MAXN];
int fa(int x)
{
    if(x!=father[x])
        father[x]=fa(father[x]);
    return father[x];
}
int cmp(node x,node y)
{
    return x.c<y.c;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        father[i]=i;
    for(int i=1;i<=m;i++)
        cin>>G[i].v>>G[i].e>>G[i].c;
    int ans=0;
    sort(G+1,G+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        //int e=r[i];
        int x=fa(G[i].v);int y=fa(G[i].e);
        if(x!=y)
        {
            ans+=G[i].c;
            father[x]=y;
        }
    }
    cout<<ans<<endl;
    return 0;
}
