#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
typedef long long ll;
using namespace std;
/*贪心题目
先按照分数排序然后以结束的那天开始写
如果当天已经有作业则往前移若是没有位置的话
则sum+=w[i].b;
*/
int n,t,l,j;
int k=0x7f7f7f7f;
struct node
{
    int a,b;
}w[1000+100];
int vis[1000+100];
int cmp(node x, node y)
{
    if(x.b==y.b) return x.a<y.a;
    return x.b>y.b;
}
int main()
{
    while(cin>>t)
    {
        while(t--)
        {
            memset(vis,0,sizeof(vis));
            cin>>n;
            for(int i=1;i<=n;i++)
                cin>>w[i].a;
            for(int i=1;i<=n;i++)
                cin>>w[i].b;
            sort(w+1,w+n+1,cmp);
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                for(j=w[i].a;j>=1;j--)
                {
                    if(!vis[j])
                    {
                        vis[j]=1;
                        break;
                    }
                }
            if(j==0) sum+=w[i].b;
            }
            cout<<sum<<endl;
        }
    }
}

