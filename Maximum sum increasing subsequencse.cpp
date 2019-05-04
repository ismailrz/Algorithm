
/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ******************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65, 'a'=97 '0'=48


map<ll,bool>visi;
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int maxarray[1001],maxindex[1001],ar[1001];
int maxans;
int msis(int n)
{
    int i,j,xx,yy;
    for(i=2; i<=n; i++)
    {
        for(j=1; j<i; j++)
        {
            if(ar[j]<ar[i])
            {
                xx=maxarray[j]+ar[i];
                if(xx>maxarray[i])
                {
                    maxarray[i]=xx;
                    if(maxans<maxarray[i]) maxans=maxarray[i];
                    maxindex[i]=j;
                }
            }
        }
    }
    /*
    for(i=1; i<=n; i++)
        cout<<maxarray[i]<<" ";
    cout<<endl;
    */

}
void sequence(int n)
{
    int i,xx,yy=-1;
    for(i=1; i<=n; i++)
    {
        if(maxarray[i]>yy)
        {
            yy=maxarray[i];
            xx=i;
        }
    }
    while(1)
    {
        cout<<ar[xx]<<" ";
        if(xx==maxindex[xx]) break;
        xx=maxindex[xx];
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,b,d,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    si(n);
    maxans=-1;
    for(i=1; i<=n; i++)
    {
        si(x);
        ar[i]=x;
        maxarray[i]=x;
        maxindex[i]=i;
        maxans=max(maxans,x);

    }
    msis(n);
    cout<<maxans<<endl;
    sequence(n);


}
/*
7
4 6 1 3 8 4 6
*/
