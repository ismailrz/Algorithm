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
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define mod 100000007
 
#define faster      ios_base::sync_with_stdio(0);cin.tie(0);
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
map<ll,int>mp;
vector<ll>vec;
void lol()
{
    ll i,j,x;
    for(i=2; i<=100001; i++)
    {
        for(j=2; j<=100001; j++)
        {
            x=ceil(pow(i,j));
            if(x>10000000000)
                break;
            if(mp[x]==0)
            {
                vec.pb(x);
            }
            mp[x]=1;
        }
    }
    sort(vec.begin(),vec.end());
    //cout<<vec[vec.size()-1]<<endl;
}
inline ll  bigmod ( ll  a, ll  p, ll  m )
{
    ll  res = 1 % m, x = a % m;
    while ( p )
    {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
ll modInv2(ll a,ll m) //2nd away.
{
    return bigmod(a,m-2,m);
}
ll ansp[siz];
void pre()
{
    int i,j,n;
    ansp[1]=ansp[0]=1;
    for(i=2; i<=100001; i++)
    {
        ansp[i]=(ansp[i-1]*i)%mod;
    }
    //cout<<ansp[17];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    // faster;
    lol();
    pre();
    ll i,j,a,b,x,y,n,ck,t,m,r,ans,rem,lo,hi,cnt,cs=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        x=UB(vec,a);
        y=LB(vec,b);
        //  cout<<x<<"  "<<y<<endl;
        if(vec[x-1]==a)
            x--;
        if(vec[y]!=b)
            y--;
        // cout<<x<<"  "<<y<<endl;
        n=y-x+1;
        // cout<<"n="<<n<<endl;
        if(n<=0)
        {
            printf("Case %lld: 0\n",cs++);
            continue;
        }
        r=n;
        n=2*r;
        hi=ansp[n];
        lo=(ansp[r]*ansp[n-r])%mod;
        rem=(hi*modInv2(lo,mod))%mod;
        ans=(rem*modInv2(r+1,mod))%mod;
        printf("Case %lld: %lld\n",cs++,ans);
    }
 
}
