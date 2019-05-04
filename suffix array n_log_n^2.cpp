#include<bits/stdc++.h>
using namespace std;

struct info
{
    int x,y,indx;
};
struct data
{
    int rank,index;
};
info h[100009];
char s[100009];
int p[22][100009],n,stp;
bool better(info p1, info p2)
{
    if(p1.x<p2.x) return 1;
    if(p1.x==p2.x&&p1.y<p2.y) return 1;
    return 0;
}
bool better2(data p1, data p2)
{
    if(p1.rank<p2.rank) return 1;
    if(p1.rank==p2.rank&&p1.index<p2.index) return 1;
    return 0;
}
void Parse_Table()
{
    for(int i=0; i<n; i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            p[0][i]=s[i]-'0';
        else p[0][i]=s[i]-'A'+11;
    }
    for(int i=1;; i++)
    {
        int len=(1<<i);

        for(int j=0; j<n; j++)
        {
            h[j].x=p[i-1][j];

            int k=j+len/2;

            if(k<n) h[j].y=p[i-1][k];
            else h[j].y=-1;
            h[j].indx=j;
        }
        sort(h,h+n,better);
        int co=0;
        for(int j=0; j<n; j++)
        {
            if(j>0&&h[j].x==h[j-1].x&&h[j].y==h[j-1].y)
                p[i][h[j].indx]=p[i][h[j-1].indx];
            else p[i][h[j].indx]=co++;
        }
        if(len>=n)
        {
            stp=i;
            break;
        }
    }
}

int main()
{
    int i,j,k,m,d,test,t=0;
    while(scanf("%s",s)==1)
    {
        stp=0;
        n=strlen(s);
        Parse_Table();
        data suffix_array[100009];
        for(i=0; i<n; i++)
        {
            suffix_array[i].rank=p[stp][i];
            suffix_array[i].index=i;
        }
        sort(suffix_array,suffix_array+n,better2);
        for(i=0; i<n; i++)
            printf("%d\n",suffix_array[i].index);
    }
    return 0;
}
