//solution of uva 11060

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
int indegree[1009];
vector<int>adj[1009];
char str[100],str2[1001];
map<string,int>mpp;
map<int,string>ans;
int vis[1001];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,k,n,m,d,node,edge,x,y,cnt,cs=1;
    while(si(n)==1)
    {
        mem(vis);
        mpp.clear(),ans.clear();
        mem(indegree);
        node=n;
        cnt=1;
        for(i=0; i<n; i++)
        {
            scanf("%s",str); // name of task in string
            if(mpp[str]==0)
            {
                mpp[str]=cnt;
                ans[cnt]=str;
                cnt++;
            }
        }
        si(n);
        for(i=0; i<n; i++)
        {
            scanf("%s %s",str,str2); // which task are connected
            x=mpp[str],y=mpp[str2];
            // cout<<x<<" "<<y<<endl;
            indegree[y]++;
            adj[x].push_back(y);
        }
        set<int>q;
        for(i=1; i<=node; i++)
        {
            if(indegree[i]==0)
            {
                q.insert(i);
            }
        }
        vector<int>topo;
        set<int>::iterator it;
        /*
        while(!st.empty())
        {
        it=st.begin();
        cout<<*it<<" ";
        st.erase(st.find(*it));
        }
        */

        while(!q.empty())
        {
            it=q.begin();
            int rr=*it;
            // cout<<"00="<<*it<<endl;
            q.erase(q.find(rr));
            topo.push_back(rr);
            int sz=adj[rr].size();
            for(i=0; i<sz; i++)
            {
                int u=adj[rr][i];
                //  cout<<u<<endl;
                indegree[u]--;
                if(indegree[u]==0) q.insert(u);
            }
        }
        //if node!=topo.size(), then no solution exists. Because an cycle occurs.
        int sz=topo.size();
        printf("Case #%d: Dilbert should drink beverages in this order: ",cs++);
        //print ordering in task in accending order
        for(i=0; i<sz; i++)
        {
            cout<<ans[topo[i]];
            if(i==sz-1) printf(".");
            else if(i<sz-1) printf(" ");
        }
        for(i=0; i<=node; i++) adj[i].clear();
        printf("\n\n");
    }
    return 0;

}
/*
4 3
1 2
2 3
4 3

*/

