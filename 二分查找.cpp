#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];
/*先对a数组进行排序
在a[1]到a[n]之间取中间数a[mid]
如果寻找的数t>a[mid] i=mid+1;
t<a[mid] j=mid-1;
在循环i<=j中去寻找a[mid]==t的数字*/ 
int erfen(int l,int r,int t)
{
    int i=l,j=r;
    while(i<=j)
    {
    	int mid=(i+j)/2;
        if(t==a[mid]) return mid;
        if(t>a[mid]) i=mid+1;
        if(t<a[mid]) j=mid-1;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int q;
    cin>>q;
    int m=erfen(1,n,q);
    cout<<m<<endl;
}

