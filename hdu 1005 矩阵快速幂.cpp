#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
typedef long long ll;
using namespace std;
int n,k;
const ll mod =1e9+7;
struct node
{
    ll a[15][15];
}sy;
node muilt(node c, node b)
{
    node d;
    memset(d.a,0,sizeof(d.a));
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
                for(int k=1;k<=2;k++)
                    d.a[i][j]=(d.a[i][j]+c.a[i][k]*b.a[k][j])%mod;
    return d;
}
node fast(node sw,int b)
{
    node ss;
    memset(ss.a,0,sizeof(ss.a));
    for(int i=1;i<=2;i++)
        ss.a[i][i]=1;

    while(b)
    {
        if(b&1) ss=muilt(ss,sw);
        sw=muilt(sw,sw);
        b>>=1;
    }
    return ss;
}
int main()
{
    while(scanf("%d %d",&n,&k)!=EOF)
    {
      node nn;
      memset(nn.a,0,sizeof(nn.a));
      nn.a[1][1]=0;nn.a[1][2]=k-1;nn.a[2][1]=1;nn.a[2][2]=k-2;
      node w=fast(nn,n);
      cout<<(w.a[1][1]%mod)<<endl;
    }
}
