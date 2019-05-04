//BISMILLAHIR RAHMANIR RAHIM
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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

map<ll,bool>visi;
struct node
{
    int val;
    node *next;
};
node *head=NULL, *last=NULL;
node *tmp;
void insert(int value)
{
    tmp=new node();
    tmp->val=value;
    if(head==NULL)
    {
        head=tmp;
        last=tmp;
    }
    else
    {
        last->next=tmp;// aktar pichone ar akta link kore dicci...
        last=tmp;
    }
}
void printlist()
{
    node *tmp;
    tmp=head;
    while(tmp!=NULL)
    {
        printf("%d\n",tmp->val);
        tmp=tmp->next;
    }
}
void insert1(int value,int value1)
{
    node *tmp,*tmp1,*tmp2;
    tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->val==value)
        {
            tmp1=new node();
            tmp1->val=value1;
            tmp2=tmp->next;
            tmp->next=tmp1;
            tmp1->next=tmp2;
            break;
        }
        tmp=tmp->next;
    }
}
void delete1(int value)
{
    node *tmp, *prev;
    tmp=head;
    prev=NULL;
    while(tmp!=NULL)
    {
        if(tmp->val==value)
        {
            if(prev==NULL)
                head=tmp->next;
            else
                prev->next=tmp->next;
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
}
int main()
{
    int value,i,j;
    insert(2);
    insert(4);
    insert(5);
    printlist();
    insert1(2,3); // akhane 2 ar pore 3 ke insert kora hocce ..
    printf("\n");
    printlist();
}
