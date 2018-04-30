#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a,c[20],n;
int update(int pos,int x)
{
	int ans=0;
	for(;pos>0;pos-=pos&(-pos))
	{
		ans+=c[pos];
	}
	return ans;
}
void add(int pos,int x)
{
	for(;pos<=n;pos+=pos&(-pos))
	{
		c[pos]+=x;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		add(i,a);
	}
	add(1,3);
	for(int i=1;i<=n;i++)
	    cout<<c[i]<<" ";
 } 
