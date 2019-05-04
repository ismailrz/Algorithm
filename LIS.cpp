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
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
int ar[siz],ar2[siz];
vector<int>vec,vec2;
int ind[siz];
int main()
{
    faster
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,b,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    si(n);
    r=0;
    memset(ind,-1,sizeof(ind));
    for(i=0; i<n; i++)
    {
        si(ar[i]);
        x=ar[i];
        vector<int>:: iterator it=lower_bound(vec.begin(),vec.end(),x);
        if(vec.end()==it)
        {
            vec.pb(x);
            ar2[r]=i;
            if(r-1>=0)
            {
                ind[i]=ar2[r-1];
            }
            r++;
        }
        else
        {
            vec[it-vec.begin()]=x;
            ar2[it-vec.begin()]=i;
            if(it-vec.begin()-1>=0)
            {
                ind[i]=ar2[it-vec.begin()-1];
            }
        }
    }
    cout<<"r="<<r<<endl;
    // cout<<vec.size()<<endl<<endl;
    // cout<<"r=="<<ar2[r-1]<<endl;
    x=ar2[r-1];
    cout<<ar[x]<<endl;
    while(ind[x]!=-1)
    {
        x=ind[x];
        cout<<ar[x]<<endl;
    }
}

/*
11
3 4 -1 5 8 2 3 12 7 10 1

20
15 5 8 18 4 18 14 2 14 9 10 16 14 7 1 18 18 4 10 3

12
4 3 4 5 1 2 5 10 4 5 1 12

*/
