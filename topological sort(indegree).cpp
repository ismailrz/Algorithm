#include<bits/stdc++.h>
using namespace std;
int indegree[109];
int main()
{
    int i,j,k,n,m,d,node,edge,x,y;
    cout<<"Enter the number of node and edge.\n";
    while(cin>>node>>edge)
    {
        if(node==0&&edge==0) break;
        memset(indegree,0,sizeof(indegree));
        vector<int>adj[109];
        cout<<"Enter the connected node.\n";
        for(i=0; i<edge; i++)
        {
            cin>>x>>y;
            indegree[y]++;
            adj[x].push_back(y);
        }
        queue<int>q;
        for(i=1; i<=node; i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        vector<int>topo;
        while(!q.empty())
        {
            int ff=q.front();
            q.pop();
            topo.push_back(ff);
            int sz=adj[ff].size();
            for(i=0; i<sz; i++)
            {
                int u=adj[ff][i];
                indegree[u]--;
                if(indegree[u]==0) q.push(u);
            }
        }
        //if node!=topo.size(), then no solution exists. Because an cycle occurs.
        int sz=topo.size();
        cout<<topo[0];
        for(i=1; i<sz; i++)
            cout<<" "<<topo[i];
        printf("\n");
    }
    return 0;
}
/*
4 3
1 2
2 3
4 3

*/
