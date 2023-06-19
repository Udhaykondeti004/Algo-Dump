#include<iostream>
using namespace std;
void dfs(int);
int g[10][10],reach[10],n;
void dfs(int v)
{
	cout<<v<<" ";
	reach[v] = 1;
	for(int i=0;i<n;i++)
	{
		if(!reach[i] && g[v][i]==1)
		{
			dfs(i);
		}
	}
}
int main()
{
	int k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		reach[i] = 0;
	}
	cin>>k;
	dfs(k);
}
