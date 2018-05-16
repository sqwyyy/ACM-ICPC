#include <cstdio>
#include <cstring>
/*瑟夫环（约瑟夫问题）是一个数学的应用问题：
已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。
从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；
依此规律重复下去，直到圆桌周围的人全部出列。通常解决这类问题时我们把编号从0~n-1，最后 [1]  结果剩下的那个人即为原问题的解
有数学公式：N=1: f[N]=0; N>1 : f[N]=(f[N-1]+M)%N;
最后的结果加1即可
*/
int main()
{
    int t;
    scanf("%d",&t);
   for(int ca=1;ca<=t;ca++)
    {
        int bj=0;
        int n,m,last=0;
        scanf("%d %d",&n,&m);
        for(int i=2;i<=n;i++)
            last=(last+m)%i;
        printf("Case %d: %d\n",ca,last+1);
    }
    return 0;
}
