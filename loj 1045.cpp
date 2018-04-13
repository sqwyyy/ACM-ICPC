#include <iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
/*求 n 的阶乘在 base 进制下的位数，这里有一个简单的方法，就是log10（n）+ 1就是 n 的在十进制下的位数，
由此可知 log base（n） 就是n在base 进制下的位数，再根据换底公式，log base（n） == log（n）/ log（base），这里让求的是阶乘，根据log的原理呢，
就有log base （n！） == （ log（n） + log（n-1） + log（n-2） + 。。。。+ log（1）） / log（base）。用 sum 数组存一下 log（n！) 就可以快速的求出了
*/double a[1000];
void pre(int x)
{
	for(int i=1;i<=x;i++)
		a[i]=a[i-1]+log((double)i);
}
int f(int x,int y)
{
	int m=(int)(a[x]/log((double)y))+1;
	return m;
}
int main()
{
    int t,w=0;
	cin>>t;
	while(t--)
	{
	    memset(a,0,sizeof(a));
		int n,m;
		cin>>n>>m;
		pre(n);
		cout<<"Case "<<++w<<": "<<f(n,m)<<endl;
	}

}
