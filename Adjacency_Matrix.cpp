#include<iostream>
using namespace std;
int arr[20][20];

void display(int v)
{
	for(int i = 1;i<2;i++)
	{
		cout<<"  ";
		for(int j=0;j<v;j++)
		cout<<" "<<j;
	}
cout<<endl;
cout<<endl;
	for(int i =0;i<v;i++)
	{
		cout<<i<<"  ";
		for(int j = 0;j<v;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int v,e;
	cout<<"Enter number of vertices: ";
	cin>>v;
	cout<<"Enter number of edges: ";
	cin>>e;
	for(int i=1;i<=e;i++)
	{
		int x,y;
		cout<<"Enter vertex 1: ";
		cin>>x;
		cout<<"Enter vertex 2: ";
		cin>>y;
		cout<<endl;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	display(v);
}
