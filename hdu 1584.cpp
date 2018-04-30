#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
/*参考的代码
*/
const int INF=100000000;
int vis[12];
int a[12],ans;
void DFS(int cur,int temp)//cur代表已经移动了几张牌，temp代表目前移动耗费的步数，把步数写在这里解决了我一直的疑惑
{
    if(temp>=ans)return;  //剪枝 太重要了！！
    if(cur==9)     //原来写成10，只用移动9次 10是固定不变的 这里需要思考 我原先做的时候什么都没想 就一个劲儿的枚举
    {
        ans=temp; //原来temp=0，既然进入了这个语句 就已经确保当前值比原来的要优化
        return;   //回溯，可以自然解决改temp的问题
    }
     for(int i=1;i<10;i++)//递归里写上这句就是一个全排列了（+下面的判重）
     {
        if(!vis[i])
        {
            for(int k=i+1;k<=10;k++)//这个用来确定i牌要移到什么位置
            {
                if(!vis[k])//比如要移1了，如果2,3,4,5都已经被移动过了 那么这几张牌必定叠放在6的下面，所以要移到6的位置
                {
                    vis[i]=1;
                    DFS(cur+1,temp+abs(a[i]-a[k]));
                    break;//注意不要再这个地方回溯 如果回溯了 就像是又一个全排列 而且牌得移动不合理，比如2移到6了，结果回溯就直接跳过3~6到了7的下面
                }
            }
            vis[i]=0;//这里回溯
        }
     }
    return ;
}
int main()
{
    int cas,s;
    cin>>cas;
    while(cas--)
    {
        for(int i=1;i<=10;i++)
        {
             cin>>s;
             a[s]=i;//牌面为s的牌所在的位置
        }
        memset(vis,0,sizeof(vis));

        ans=INF;
        DFS(0,0);
        cout<<ans<<endl;

    }
}
