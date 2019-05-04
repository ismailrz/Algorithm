#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 500007;
int pos;
int indx[N],indx2[N];
struct SUFFIX_ARRAY
{
    int wa[N],wb[N],ws[N],wv[N],r[N];
    int len; // length of the string
 
    int rank[N]; // here rank said in which position a suffix is situated in the sorted suffix list.
    int height[N];
    //Height gives the lcp of sa[i] ans sa[i-1] So index height[1] contains the lcp of sa[1] and and sa[0]
 
    int sa[N]; //sa gives the sorted suffix indexes (staring index)//Index zero te always  strlen tomo adress thake
    // abc
    //er jonno 3 0 1 2
 
    int dp[N][21]; // for LCP
 
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
            //printf("p = %d\n", p );
        }
    }
    void calheight(int n)
    {
        memset(height,0,sizeof(height));
        memset(rank,0,sizeof(rank));
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
    // create sparse table in height array
    void sparse_table()
    {
        int n =  len+1;
 
        for(int i=0; i<n; i++) dp[i][0]=height[i];
        for (int j=1; (1 << j) <= n; j++)
            for (int i = 0; i+(1 << j)-1<n; i++)
                dp[i][j] = (dp[i][j-1]<=dp[ i+(1<<(j-1)) ][j-1] )? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }
 
    // start/end , the suffix that situated at start/end index after suffix sort
    // RMQ(find minimum value)
    int find_lcp(int start,int end)
    {
        if(start>end) swap(start,end);
        start++;
        int diff=end-start;
        diff=31 - __builtin_clz(diff+1);
        return dp[start][diff]<=dp[end-(1<<diff)+1][diff]?dp[start][diff]:dp[end-(1<<diff)+1][diff];
    }
    // find lcp of s and e th suffix of original string
    int get_lcp(int s,int e)
    {
        return find_lcp( rank[s] ,rank[e] );
    }
 
    void print()
    {
 
        // cout << "length :  " << len << endl;
        // cout << "s[n] = '$' " << endl;
        //cout << "sorted suffix index(0 based) : " << endl;
        int i;
 
        // for(i=1; i<=len; i++) cout<<sa[i]<<" ";
        // cout<<endl;
        //for(int i=1; i<=len; i++)  cout << height[i] << " ";
        // cout << endl;
        int ans=0;
        for(int i=2; i<=len; i++)
        {
            if(indx[sa[i]]!=indx[sa[i-1]])
            {
                //cout<<sa[i]<<" "<<sa[i-1]<<endl;
                // cout<<"hi="<<height[i]<<endl;
                //if(pos>sa[i]&&pos<sa[i-1]||pos<sa[i]&&pos>sa[i-1])
                //cout << "rank of suffix " << endl;
                // for(int i=0; i<=len; i++)  cout << rank[i] << " , ";
                // cout << endl;
                // cout << "LCP between i and i-1 " << endl;
                // cout<<height[i]<<endl;
                ans=max(ans,height[i]);
            }
        }
        printf("%d\n",ans);
    }
} SA;
char str[500007],str2[500007];
int main()
{
    //http://codeforces.com/contest/611/submission/15270024
    int i,j,n,t,mn;
    scanf("%s %s",str,str2);
    strcat(str,"#");
    pos=strlen(str)-1;
    for(i=0; i<pos; i++) indx[i]=1;
 
    strcat(str,str2);
    SA.generate(str);//Send  o indexed string
    mn=strlen(str);
    for(i=pos; i<mn; i++) indx[i]=2;
    SA.sparse_table();
    // int x=SA.get_lcp(0,3);//gives the lcp of position 0,and 3
    SA.print();
    //hicout<<x<<endl;
    return 0;
}
 
