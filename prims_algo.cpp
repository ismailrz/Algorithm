#include<bits/stdc++.h>
using namespace std;
vector<int>G[1001];
vector<int>cost[1001];
int d[10001];
int vis[1001];
struct node
{
    int a,b;
    node(int x,int y)
    {
        a=x;
        b=y;
    }
    bool operator < (const node & p) const
    {
        return p.b<b;
    }
};
int prims(int src,int n)
{
    memset(d,63,sizeof(d));
    d[src]=0;
    int ans=0;
    int i, cnt=0;
    priority_queue<node>q;
    q.push(node(src,0));
    while(1)
    {
        node top=q.top();
        q.pop();
        int u=top.a;
        if(vis[u]==0)
        {
            for(i=0; i<G[u].size(); i++)
            {
                int v=G[u][i];
                q.push(node(v,cost[u][i]));
            }
            ans+=top.b;
            if(cnt==n-1)
                break;
            cnt++;
            vis[u]=1;
        }
    }
    cout<<ans;

}
int main()
{
    int i,j,n,m,x,y,cst;
    cin>>n>>m;
    for(i=1; i<=m; i++)
    {
        cin>>x>>y>>cst;
        G[x].push_back(y);
        G[y].push_back(x);
        cost[x].push_back(cst);
        cost[y].push_back(cst);
    }
    prims(1,n);
}
/*
3 3
1 2 10
1 3 1
3 2 5
*/
