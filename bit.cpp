#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define siz 1000001
#define one(x) __builtin_popcount(x)
typedef long long li;

using namespace std;
li tree[siz],ar[siz];
li getsum(li n,li index)
{
    li sum=0;
    index=index+1;
    while(index>0)
    {
        sum+=tree[index];
        index -= index & (-index);
    }
    return sum;
}
// if we want to decrease value
li minus1(li n,li index ,li val)
{
    index=index+1;
    while(index<=n)
    {
        tree[index]-=val;
        index += index & (-index);
    }
}
//here increment value and build tree
li updateBIT(li n,li index,li val)
{
    index=index+1;

    while(index<=n)
    {
        tree[index]+=val;
        index += index & (-index);
    }
}
int  main()
{
    li i,j,n,s,m,x,y,z,s1,s2,t,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        memset(tree,0,sizeof tree);
        sc("%lld%lld",&n,&m);
        for(i=0; i<n; i++)
        {
            sc("%lld",&ar[i]);

            updateBIT(n,i,ar[i]);

        }
        pf("Case %lld:\n",cs++);
        for(i=0; i<m; i++)
        {
            sc("%lld",&x);
            if(x==1)
            {
                sc("%lld",&y);
                pf("%lld\n",ar[y]);
                minus1(n,y,ar[y]);
                ar[y]=0;
            }
            if(x==2)
            {
                sc("%lld%lld",&y,&z);
                ar[y]+=z;
                updateBIT(n,y,z);
            }
            if(x==3)
            {
                sc("%lld%lld",&y,&z);
                s1=getsum(n,y-1);
                s2=getsum(n,z);
                pf("%lld\n",s2-s1);
            }
        }
    }
}

