
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
// light oj 1159 - Batman
// cpu 0.028 s

char st[60],st2[60],st3[60];
int dp[60][60][60];
int LCS(int n,int n2,int n3)
{
    int i,j,r;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n2; j++)
        {
            for(r=0; r<=n3; r++)
            {
                if(st[i]==st2[j]&&st2[j]==st3[r]) dp[i][j][r]=dp[i-1][j-1][r-1]+1;
                else
                    dp[i][j][r]=max(max(dp[i-1][j][r],dp[i][j-1][r]),dp[i][j][r-1]);
            }
        }
    }
    return dp[n][n2][n3];
}
int main()
{
    int i,j,n,n2,n3,x,t,cs=1;
    char sr[60],sr2[60],sr3[60];
    si(t);
    while(t--)
    {
        mem(dp);
        scanf("%s%s%s",sr,sr2,sr3);
        n=strlen(sr);
        for(i=0; i<n; i++) st[i+1]=sr[i];
        n2=strlen(sr2);
        for(i=0; i<n2; i++) st2[i+1]=sr2[i];
        n3=strlen(sr3);
        for(i=0; i<n3; i++) st3[i+1]=sr3[i];

        x=LCS(n,n2,n3);
        printf("Case %d: %d\n",cs++,x);
    }

}

