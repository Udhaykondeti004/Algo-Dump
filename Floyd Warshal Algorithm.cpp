#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define inf 9999
int V;
int graph[100][100];
int m[100][100];

void display(int graph[100][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<endl;
		for(j=0;j<n;j++)
		{
		
		cout<<graph[i][j]<<"\t";
	}
	}
}

void allpairshort(int graph[100][100],int n){
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if (graph[i][j]==0)
			{
			
			     m[i][j]=inf;
			 }
			else
			    m[i][j]=graph[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if (i==j)
				{
					m[i][j]=0;
				}
				else if (m[i][j]<=m[i][k]+m[k][j])
				    m[i][j]=m[i][j];
				else
				    m[i][j]=m[i][k]+m[k][j];
				
			}
		}
		printf("\n\n");
		display(m,V);

}

}


int main()
{

	int e;
	cout<<"enter no of vertices: ";
	cin>>V;
	cout<<"enter no of edges: ";
	cin>>e;
   for(int i=0;i<e;i++)
    {
        int x,y,weight;
        cout<<"enter vertex 1 : ";
        cin>
        cout<<"enetr vertex 2 : ";
        cin>>y;
        cout<<"enter weight:";
        cin>>weight;
        graph[x][y]=weight;
    }
	allpairshort(graph,V);

	return 0;
}
