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
#define siz 104001
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


#define MAX_NODES 999
#define INF 2147483646
#define UNINITIALIZED -1

using namespace std;

int capacities[MAX_NODES][MAX_NODES];
int flowPassed[MAX_NODES][MAX_NODES];
vector<int> graph[MAX_NODES];
int parentsList[MAX_NODES];
int currentPathCapacity[MAX_NODES];
int bfs(int startNode, int endNode)
{
    memset(parentsList, UNINITIALIZED, sizeof(parentsList));
    memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
    queue<int> q;
    q.push(startNode);
    parentsList[startNode]=-2;
    currentPathCapacity[startNode]=INF;
    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for(int i=0; i<graph[currentNode].size(); i++)
        {
            int to = graph[currentNode][i];
            if(parentsList[to] == UNINITIALIZED)
            {
                if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0)
                {
                    parentsList[to] = currentNode;
                    currentPathCapacity[to] = min(currentPathCapacity[currentNode],
                                                  capacities[currentNode][to] - flowPassed[currentNode][to]);
                    if(to == endNode) return currentPathCapacity[endNode];
                    q.push(to);
                }
            }
        }
    }
    return 0;
}
ll  edmondsKarp(int startNode, int endNode)
{
    ll maxFlow=0;
    while(true)
    {
        int flow=bfs(startNode, endNode);
        if(flow==0)
        {
            break;
        }
        //   cout<<"flow=="<<flow<<endl<<endl;
        maxFlow +=flow;
        int currentNode=endNode;
        while(currentNode != startNode)
        {
            //  cout<<currentNode<<" ";
            int previousNode = parentsList[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode=previousNode;
        }
        // cout<<endl<<endl;
    }
    return maxFlow;
}
int main()
{
    // freopen("A.txt","w",stdout);
    int nodesCount, edgesCount ,x,y,source, sink,t,from, to,i,capacity,cs=1;
    ll maxFlow;
    si(t);
    while(t--)
    {
        mem(flowPassed);
        mem(capacities);
        si(nodesCount);
        for(i=1; i<=nodesCount; i++)
        {
            si(x);
            graph[i].pb(104+i);
            capacities[i][104+i]=x;
        }
        si(edgesCount);
        for(int edge=0; edge<edgesCount; edge++)
        {
            si(from),si(to),si(capacity);
            capacities[from+104][to]=capacity;
            capacities[to][from+104]=0;
            graph[from+104].push_back(to);
            graph[to].pb(from+104);
        }
        si(x),si(y);
        source =500;
        sink =501;
        for(i=0; i<x; i++)
        {
            si(from);
            graph[source].pb(from);
            capacities[source][from]=99999999;
        }
        for(i=0; i<y; i++)
        {
            si(from);
            graph[from+104].pb(sink);
            capacities[from+104][sink]=99999999;
        }
        maxFlow = edmondsKarp(source, sink);
        printf("Case %d: %lld\n",cs++,maxFlow);
        for(i=1; i<=nodesCount+600; i++) graph[i].clear();
        // graph[500].clear();
    }
    return 0;
}
/*

4
10 20 30 40
6
1 2 5
1 3 10
1 4 13
2 3 5
2 4 7
3 4 20
3 1
1 2 3 4

*/

