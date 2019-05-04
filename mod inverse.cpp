#include <cstdio>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
typedef long long ll;
pii extEuclid(int a,int b)
{
    if(b==0)
    {
        return pii(1,0);
    }
    else
    {
        pii d=extEuclid(b,a%b);
        return pii(d.y,d.x-d.y*(a/b));
    }
}
int modInv(int a,int n)
{
    pii d =extEuclid(a,n);
    return ((d.x%n)+n)%n;
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
ll modInv2(ll a,ll m)
{
    return bigmod(a,m-2,m);
}
int main()
{
    int b ,n;
    while(scanf("%d%d",&b,&n)==2)
    {
        ll ret= 2ll*modInv(b,1000000007); //(a/b)%mod b inverse represent modInv(b,1000000007) 221 value of a
        printf("%d\n",ret%1000000007);
    }
    return 0;
}
