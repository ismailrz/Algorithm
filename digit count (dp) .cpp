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

#define sc scanf
#define si(t) scanf("%d",&t)

#define sll(t) scanf("%lld",&t)

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

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


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
ll dp[10],dp2[11];
void digit_count(ll n)
{
    ll i,d,sum,msd,rem,sum2;

    if(n<10)
    {
        for(i=1; i<=n; i++)
            dp[i]++;
        return ;
    }

    d=log10(n);
    sum=ceil(pow(10,d-1));
    sum=sum*d;
    //  cout<<sum<<endl;
    rem=ceil(pow(10,d));
    msd=n/rem;
    rem=n%rem;
    //cout<<msd<<endl;
    sum2=ceil(pow(10,d));

    for(i=1; i<=msd-1; i++)
        dp[i]+=(sum2);

    for(i=1; i<=9; i++)
        dp[i]+=sum*(msd);
    dp[msd]+=(rem+1);
    digit_count(rem);

}
void digit_count_2(ll n)
{
    ll i,d,sum,msd,rem,sum2;

    if(n<10)
    {
        for(i=1; i<=n; i++)
            dp2[i]++;
        return ;
    }

    d=log10(n);
    sum=ceil(pow(10,d-1));
    sum=sum*d;
    // cout<<sum<<endl;
    rem=ceil(pow(10,d));
    msd=n/rem;
    rem=n%rem;
    //  cout<<msd<<endl;
    sum2=ceil(pow(10,d));

    for(i=1; i<=msd-1; i++)
        dp2[i]+=(sum2);

    for(i=1; i<=9; i++)
        dp2[i]+=sum*(msd);
    dp2[msd]+=(rem+1);
    digit_count_2(rem);

}
ll ans;
ll cal(ll n)
{
    if(n<100)
    {
        ans+=n/10;
        return ans;
    }
    ll d=log10(n);
    ll r=1;
    ll rem,sum;
    if(d==2)
        sum=9;
    else if(d==1) sum=0;
    else
    {
        sum=d-2;
        d=d-2;
        //cout<<"d="<<d<<endl;
        while(d)
        {
            sum*=10;
            sum+=8;
            d--;
        }
    }
    if(sum!=9&&sum!=0)
        sum=(sum*10)+9;
    // cout<<sum<<endl;
    d=log10(n);
    rem=ceil(pow(10,d-1));
    rem=d*rem;
    //cout<<rem<<endl;


    ll p = ceil(pow(10, d));

    int msd = n/p;
    //cout<<"msd="<<msd<<endl;

    ans+=(sum+(msd-1)*rem);
    rem=n%p;
    //cout<<"rem="<<rem<<endl;
    ll s;
    s=9;

    ans+=d;
    d--;
    ll mul=9;
    while(d)
    {
        if(s<=rem)
        {
            ans+=(d*mul);
            s=((s*10)+9);
            mul=mul*10;

        }
        else
        {
            s/=10;
            ll r=rem-s;

            ll an=(r*d);
            // cout<<"s=="<<s<<"  "<<ans<<"  "<<an<<endl;
            ans+=an;
            break;
        }
        d--;
    }
    // cout<<"ans=="<<ans<<endl;
    cal(rem);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll  i,j,m,a,n,c,b,d,ck,t,r,rem,cnt,lo,hi,sum,cs=1;
    while(1)
    {
        mem(dp),mem(dp2);
        sll(n),sll(m);
        if(n==0&&m==0) break;
        cal(m);
        a=ans;
        ans=0;
        b=cal(n-1);
        ans=0;
        digit_count(m);
        digit_count_2(n-1);
        printf("%lld ",a-b);
        for(i=1; i<=9; i++)
        {
            printf("%lld",dp[i]-dp2[i]);
            //  cout<<dp[i]-dp2[i];
            if(i<9)
                printf(" ");
        }
        printf("\n");
    }

}
