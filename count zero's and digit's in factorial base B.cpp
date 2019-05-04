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
#define mod 100000009
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
double fac[2000004];
void lol()
{
    int i;
    fac[1]=log(1);
    for(i=2; i<2000001; i++)
        fac[i]=fac[i-1]+log(i);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int no,base,i,j,a,n,b,x,y,ck,t,r,ans_zero,ans_digit,rem,cnt,lo,hi,sum,cs=1;
    lol();
    while(si(n)==1)
    {
        si(base);
        ans_zero=999999999;
        b=base;
        for(i=2; i<=b; i++)
        {
            if(b%i==0)
            {
                r=0;
                while(b%i==0)
                {
                    r++;
                    b/=i;
                }
                x=n;
                sum=0;
                while(x)
                {
                    sum+=x/i;
                    x/=i;
                }
                ans_zero=min(ans_zero,sum/r);
            }
        }
        ans_digit=(fac[n]/log(base)+1);
        printf("%d %d\n",ans_zero,ans_digit);
    }
}
/*
Base = a^p1 * b^p2 * c^p3 * …
Then the number of trailing zeroes in N factorial in Base B is given by the formula 
min{1/p1(n/a + n/(a*a) + ….), 1/p2(n/b + n/(b*b) + ..), ….}.


And the number of digits in N factorial is :
floor (log(n!)/log(B) + 1)
*/
