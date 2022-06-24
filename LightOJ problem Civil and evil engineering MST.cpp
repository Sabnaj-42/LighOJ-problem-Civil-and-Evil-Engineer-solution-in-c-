
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int e,f,w;
};
int parent[100005];
node ar[100005];
int findd(int a)
{
    if(parent[a]==a)return a;
    else return parent[a]=findd(parent[a]);
}
bool comp(node a,node b)
{
    if(a.w<b.w)return true;
    else return false;
}
void unonn(int a,int b)
{
    parent[a]=b;
}
int main()
{
   int t;cin>>t;
   for(int k=1;k<=t;k++)
   {
       int n;cin>>n;
       int cnt=0;
       while(1)
       {
           int a,b,c;
           cin>>a>>b>>c;
           if(a==0&&b==0&&c==0)break;
           ar[cnt].e=a;
           ar[cnt].f=b;
           ar[cnt].w=c;
           cnt++;
       }
       for(int i=0;i<=n;i++)parent[i]=i;
       sort(ar,ar+cnt,comp);
       long long sum1=0,sum2=0;
       for(int i=0;i<cnt;i++)
       {
           int u=findd(ar[i].e);
           int v=findd(ar[i].f);
           if(u!=v)
           {
               sum1+=ar[i].w;
               parent[u]=v;

           }
       }
       for(int i=0;i<=n;i++)parent[i]=i;
       for(int i=cnt-1;i>=0;i--)
       {
           int u=findd(ar[i].e);
           int v=findd(ar[i].f);
           if(u!=v)
           {
               sum2+=ar[i].w;
               parent[u]=v;

           }
       }
       long long sum=sum1+sum2;
       printf("Case %d: ",k);
       if(sum%2==0)
       {
           cout<<sum/2<<endl;
       }
       else cout<<sum<<"/"<<2<<endl;
   }

}
