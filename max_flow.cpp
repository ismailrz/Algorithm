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


#define MAX_NODES 106
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
        maxFlow +=flow;
        int currentNode=endNode;
        while(currentNode != startNode)
        {
            int previousNode = parentsList[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode=previousNode;
        }
    }
    return maxFlow;
}
int main()
{
    int nodesCount, edgesCount ,source, sink,t,from, to,i,capacity,cs=1;
    ll maxFlow;
    si(t);
    while(t--)
    {
        mem(flowPassed);
        mem(capacities);
        si(nodesCount);
        si(source),si(sink),si(edgesCount);
        for(int edge=0; edge<edgesCount; edge++)
        {
            si(from),si(to),si(capacity);
            capacities[from][to]+=capacity;
            capacities[to][from]+=capacity;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        maxFlow = edmondsKarp(source, sink);
        printf("Case %d: %lld\n",cs++,maxFlow);
        for(i=1; i<=nodesCount; i++) graph[i].clear();
    }
    return 0;
}
/*
light oj 1153 solved

2
4
1 4 2
4 1 232
1 4 490

3
1 2 2
3 2 188
2 1 100

1 10 14
1 2 1
1 3 1
1 4 1
1 5 1
2 6 1
2 7 1
2 8 1
2 9 1
3 6 1
4 6 1
6 10 1
7 10 1
8 10 1
9 10 1

*/
