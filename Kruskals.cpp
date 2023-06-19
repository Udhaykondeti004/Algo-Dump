// You are using GCC
#include <bits/stdc++.h>
using namespace std;
#define inf 99999
int i,j,k,a,b,u,v,n,newedge=1;
int m;
int mincost=0;
int cost[100][100];
int parent[100];
int findintersection(int);
int merge(int,int);
int main()
{
cin>>n;
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        cin>>cost[i][j];
        if(cost[i][j]==0)
        cost[i][j]=inf;
    }
}
while(newedge<n)
{
    for(i=1,m=inf;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]<m)
            {
                m=cost[i][j];
                a=u=i;
                b=v=j;
            }
        }
    }

u=findintersection(u);
v=findintersection(v);
int ans=merge(u,v);
if(ans==1){
    
    cout<<newedge++<<" edge"<<"("<<a<<","<<b<<")"<<" ="<<m<<endl;
    mincost+=m;
}
cost[a][b]=cost[b][a]=inf;
}
cout<<mincost<<endl;
    
}
int findintersection(int u){
    while(parent[u]){
     u=parent[u];
    }
     return u;
}
int merge(int u,int v){
    if(u!=v){
        parent[v]=u;
        return 1;
    }
    return 0;
}
