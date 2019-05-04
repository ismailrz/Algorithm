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
#include<limits>
#include<limits.h>
 
#define all(v) v.begin(),v.end()
 
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
 
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 300001
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
 
//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
 
 
//upper bound and lower bound
 
#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector
 
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
/* -a%b---------
long long  mod(long long  a, long long  b)
{
    long long  c = a % b;
    return (c < 0) ? c + b : c;
}
*/
int ar[siz],kth;
vector<int>vec[siz];
void inttia(int node,int b,int e)
{
    if(b==e)
    {
        vec[node].pb(ar[b]);
        return;
    }
    int L=2*node;
    int R=L+1;
    int mid=(b+e)/2;
    inttia(L,b,mid);
    inttia(R,mid+1,e);
    int i,j,rt,lt;
    lt=vec[node*2].size();
    rt=vec[node*2+1].size();
    i = 0;
    j = 0;
    while(i<lt && j<rt)
    {
        if(vec[node*2][i]< vec[node*2+1][j])
            vec[node].pb(vec[node*2][i++]);
        else
            vec[node].pb(vec[node*2+1][j++]);
    }
    while(i <lt)
        vec[node].pb(vec[node*2][i++]);
    while(j <rt)
        vec[node].pb(vec[node*2+1][j++]);
}
int query(int node,int b,int e,int i,int j,int value)
{
    if(i>e||j<b) return 0;
    if(kth<=0) return 0;
    if(b>=i&&e<=j)
    {
        return UB(vec[node],value);
 
    }
    int L=2*node;
    int R=L+1;
    int mid=(b+e)/2;
    int a=query(L,b,mid,i,j,value);
    int c=query(R,mid+1,e,i,j,value);
    // cout<<a<<" "<<c<<endl;
    return a+c;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,n,m,b,x,y,ck,t,r,low,high,ans,rem,cnt,lo,hi,mid,sum,cs=1;
    si(n),si(m);
    lo=hi=0;
    lo=999999999;
    for(i=1; i<=n; i++) si(ar[i]),hi=max(hi,ar[i]),lo=min(lo,ar[i]);
    inttia(1,1,n);
    while(m--)
    {
        low=lo,high=hi;
        si(x),si(y),si(kth);
        while(low<=high)
        {
            mid=(low+high)/2;
            if(query(1,1,n,x,y,mid)>=kth)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        printf("%d\n",ans);
    }
    //// for(i=0; i<=hi; i++)
    // vec[i].clear();
 
}
/*
5 3
2 1 3 4 2
1 3 1
 
*/
