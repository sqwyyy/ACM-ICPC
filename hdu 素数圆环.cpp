#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[20+5];
bool vis[20+5];
int n;
/*水题加回溯注意输出的格式末尾不能有空格 
bool is_prime(int x)
{
	for(int i=2;i<=(int)sqrt(x);i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
void dfs(int step)
{
	if(step==n+1&&is_prime(a[1]+a[n]))
	{
		for(int i=1;i<n;i++)
		    cout<<a[i]<<" ";
		cout<<a[n]<<endl;
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(is_prime(a[step-1]+i)&&!vis[i])
		{
			vis[i]=true;
			a[step]=i;
			dfs(step+1);
			//a[step]=0;
			vis[i]=false;
		}
	}
}
int main()
{
	int t=1;
	while(scanf("%d",&n)!=EOF)
	{
		memset(vis,false,sizeof(vis));
		memset(a,0,sizeof(a));
		a[1]=1;
		vis[1]=true;
		cout<<"Case "<<t++<<":"<<endl;
		dfs(2);
		cout<<endl;
	}
	return 0;
 } 
