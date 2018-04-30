#include <cstdio>

using namespace std;
int a[]={9,1,2,3,4,5,6,7,8};
/*把组成的数列按S1 S2·······这样每个一列写下了就可以发现，第i行有i个数字而数字的排列顺序都是1—9超过9的对9取余即可，
这样我们的任务就是找到你所要输出的第n个数是在第几层就可以了，
因为第i层有i个数所以只要每次让n分别减去1，2，3·······，直到n<=i时结束就可以了，然后再将此时的n对9取余，就是最后的结果了。*/
int main()
{
    int K;
    scanf("%d",&K);
    while(K--){
        int n;
        scanf("%d",&n);
        int s = 1;
        while(n>s)
        {
            n -= s;
            s++;
        }
        printf("%d\n",a[n%9]);
    }
    return 0;
}
