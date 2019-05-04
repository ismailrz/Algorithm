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

#define MAXN 100000
#define SQRSIZE  1000

int arr[MAXN],input[siz];
int block[SQRSIZE];
int blk_sz;
void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}
int query(int l, int r)
{
    int sum = 0;
    while (l<r and l%blk_sz!=0 and l!=0)
    {
        sum += arr[l];
        l++;
    }
    while (l+blk_sz <= r)
    {
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while (l<=r)
    {
        sum += arr[l];
        l++;
    }
    return sum;
}

void preprocess(int input[], int n)
{
    int blk_idx = -1;

    blk_sz = sqrt(n);
    for (int i=0; i<n; i++)
    {
        arr[i] = input[i];
        if (i%blk_sz == 0)
        {
            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
}
int main()
{
    int i,j,n,k;
    si(n);
    for(i=0; i<n; i++) si(input[i]);
    preprocess(input, n);
    cout << "query(3,8) : " << query(3, 8) << endl;
    cout << "query(1,6) : " << query(1, 6) << endl;
    update(8, 0);
    cout << "query(9,9) : " << query(9, 9) << endl;
    return 0;
}
/*
10
2 3 2 1 2 3 1 2 3 2
*/
