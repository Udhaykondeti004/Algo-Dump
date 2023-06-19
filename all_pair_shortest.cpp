#include<iostream>
using namespace std;
#define MAX 999
int V;
int graph[100][100];
 void display(int graph[100][100])
 {
    cout<<"All pairs shortest path is"<<endl;
    for(int i =0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
 }
 
 void allpair(int graph[100][100])
 {
     int i,j,k;
     for(k=0;k<V;k++)
     {
         for(i=0;i<V;i++)
         {
             for(j=0;j<V;j++)
             {
                 if(graph[i][k] + graph[k][j] <= graph[i][j])
                 graph[i][j] = graph[i][k] + graph[k][j];
             }
         }
     }
     display(graph);
 }
 
 int main()
 {
     cout<<"Enter number of vertices : ";
     cin>>V;
     for(int i = 0;i<V;i++)
     {
         for(int j = 0;j<V;j++)
         {
             cin>>graph[i][j];
         }
     }
     allpair(graph);
 }
