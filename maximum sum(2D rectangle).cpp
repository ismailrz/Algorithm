/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
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
int row,col,ar[1001][1001],tarr[10001],up,dw,lft,rght;
int anssum=-99999999;
int kadans_alg(int n,int lt,int rt)
{
    int i,j;
    int maxsum,st,nd,endsum,hs;

    maxsum=tarr[0];
    endsum=0;
    st=nd=hs=1;
    for(i=1; i<=n; i++)
    {
        endsum+=tarr[i];
        if(endsum>maxsum)
        {
            maxsum=endsum;
            st=hs;
            nd=i;
        }
        if(endsum<0)
        {
            hs=i+1;
            endsum=0;
        }
    }
    if(anssum<maxsum)
    {
        anssum=maxsum;
        lft=lt;
        rght=rt;
        up=st;
        dw=nd;
    }

}
int rectangle()
{
    int i,j,r;
    for(i=1; i<=col; i++)
    {
        mem(tarr);
        for(j=i; j<=col; j++)
        {
            for(r=1; r<=row; r++)
                tarr[r]+=ar[r][j];
            kadans_alg(row,i,j);
        }
    }
}
int main()
{

    int i,j;
    si(row),si(col);
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=col; j++)
            si(ar[i][j]);
    }
    rectangle();
    cout<<anssum<<endl;
    cout<<"Max rectangle:\n";
    for(i=up; i<=dw; i++)
    {
        for(j=lft; j<=rght; j++)
            cout<<ar[i][j]<<" ";
        cout<<endl;
    }
}
/*
4 5
2 1 -3 -4 5
0 6 3 4 1
2 -2 -1 4 -5
-3 3 1 0 3

3 4
1 2 -34 3
-1 -4 -4 120
200 3 4 -4



*/
