#include<iostream>
using namespace std;
int Arr[20][20];
int arr[20]; 
int count=0;
int maximum=0;
void displayMatrix(int v) {
   int i, j;
   for(i=1;i<2;i++){
   	cout<<"   ";
   	for(j=0;j<v;j++)
   	cout<<" "<<j;
   }
   cout<<endl;
   cout<<endl;
   for(i = 0; i < v; i++) {
   		cout<<i<<"   ";
      for(j = 0; j < v; j++) {
         cout << Arr[i][j] << " ";
      }
      cout << endl;
   }
}
void degree(int v){
	int i, j;
	
   for(i = 0; i < v; i++) {
   	count=0;
      for(j = 0; j < v; j++) {
      	
         if(Arr[i][j]==1){
         	
			 count=count+1; 
		 }
		  
     }
    cout<<"for "<<i<<"="<<count<< endl;
	}  
    if(count>=maximum){
    	maximum=count;
	}
	
	cout<<"maximum degree is "<<maximum;
	
   }

   


void max(int v)
{
for(int i = 0; i < v; i++) {
   	count=0;
      for(int j = 0; j < v; j++) {
      	
         if(Arr[i][j]==1){
         	
			 count=count+1; 
		 }
		  
     }
    
    if(count>=maximum){
    	maximum=count;
	}
	}
	cout<<"maximum degree is "<<maximum;
   }

int main(){
	int v ,e;
	cout<<"enter no of vertices: ";
	cin>>v;
	cout<<"enter no of edges: ";
	cin>>e;
   for(int i=1;i<=e;i++)
    {
        int x,y;
        cout<<"enter vertex 1 : ";
        cin>>x;
        cout<<"enetr vertex 2 : ";
        cin>>y;
        Arr[x][y]=1;
        Arr[y][x]=1;
    }
   displayMatrix(v);
   degree(v);
   max(v);
}
