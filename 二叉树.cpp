#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int mid[20];
int behind[20],tree[1000] ;
int n;
#define lson x << 1
#define rson (x << 1) + 1
void build(int x,int L1,int R1,int L2,int R2)
{
    if(L1>R1) return;
    int root=behind[R2];
    tree[x]=root;
    int p=L1;
    while(mid[p]!=root) p++;
    int cnt=p-L1;//左结点的个数
    if(L1<=p-1) build(lson,L1,p-1,L2,L2+cnt-1);
    if(p+1<=R1) build(rson,p+1,R1,L2+cnt,R2-1);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>behind[i];
    for(int i=1;i<=n;i++)
        cin>>mid[i];
    build(1,1,n,1,n);
    for(int i=1;i<100;i++)
    {
        if(tree[i]) cout<<tree[i]<<" ";
    }
   return 0;
}
