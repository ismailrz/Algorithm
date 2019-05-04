#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N =15004;
int indx[N];
char str[N],str2[N],str3[N];
struct SUFFIX_ARRAY
{
    int wa[N],wb[N],ws[N],wv[N],r[N];
    long long len;
    int rank[N],height[N],sa[N];
    int cmp(int *ar,int a,int b,int l)
    {
        return (ar[a]==ar[b]) && (ar[a+l]==ar[b+l]);
    }
    void DA(int n,int m)
    {
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[x[i]=r[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
        for(j=1,p=1; p<n; j*=2,m=p)
        {
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) ws[i]=0;
            for(i=0; i<n; i++) ws[wv[i]]++;
            for(i=1; i<m; i++) ws[i]+=ws[i-1];
            for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
    }
    void calheight(int n)
    {
        int i,j,k=0;
        for(i=1; i<=n; i++) rank[sa[i]]=i;
        for(i=0; i<n; height[rank[i++]] = k )
            for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    }
    void generate(char *s)
    {
        int n;
        for (n=0; s[n] ; n++) r[n]=(int)s[n];
        r[n]=0;
        this->len  = n;
        DA(n+1,128);
        calheight(n);
    }
    void print()
    {
        int tt,x,y,z,ans=0;
        for(int i=3; i<=len; i++)
        {
            x=indx[sa[i]];
            y=indx[sa[i-1]];
            z=indx[sa[i-2]];
            if(x!=y and y!=z and z!=x)
            {
                tt=min(height[i],height[i-1]);
                ans=max(ans,tt);
            }
        }
        printf(" %d\n",ans);
    }
} SA;
int main()
{
    int i,j,n,t,mn,tn,pos,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s %s",str,str2,str3);
        pos=strlen(str);
        printf("Case %d:",cs++);
        for(i=0; i<pos; i++) indx[i]=1;
        strcat(str,"#");
        strcat(str,str2);
        mn=strlen(str);
        for(i=pos; i<mn; i++) indx[i]=2;
        strcat(str,"$");
        strcat(str,str3);
        tn=strlen(str);
        for(i=mn; i<tn; i++) indx[i]=3;
        SA.generate(str);
        SA.print();
    }
    return 0;
}

