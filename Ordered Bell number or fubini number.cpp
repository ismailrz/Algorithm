#include<bits/stdc++.h>
 
#define all(v) v.begin(),v.end()
#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
 
#define sii(a,b) scanf("%d%d",&a,&b)
 
#define pt(a) printf("%d\n",a)
#define PLN(a) printf("%I64d\n",a)
#define pf printf
 
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
 
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 300001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define mod  10056
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
ll  Mod(ll  a,ll  b)
{
    ll  c = a % b;
    return (c < 0) ? c + b : c;
}
/*
ll  power(ll num,ll p)
{
    int i;
    ll sum=1;
    for(i=1; i<=p; i++)
        sum*=num;
    return sum;
}
*/
int dp[1001][1001],dp2[siz];
int nCr(int n,int r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1)
    {
        return dp[n][r];
    }
    ll ret;
    ret=(nCr(n-1,r))+nCr(n-1,r-1);
    return dp[n][r]=ret%mod;
}
int solve(int n)
{
    if(n==0) return 1;
    if(dp2[n]!=-1) return dp2[n];
    int ret=0;
    for(int i=1; i<=n; i++)
    {
        ret+=(nCr(n,i)*solve(n-i));
        ret%=mod;
    }
    return dp2[n]=ret;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,a,n,b,x,y,ck,t,r,ans,rem,cnt,lo,hi,sum,cs=1;
    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);
    si(t);
    while(t--)
    {
        si(n);
        printf("Case %d: %d\n",cs++,solve(n));
    }
 
}
 
