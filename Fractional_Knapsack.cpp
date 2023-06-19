#include<iostream>
using namespace std;
int main()
{
    int n,i,j,cap,u,temp;
    float tp=0.0;
    cout<<"Enter the capacity of knapsack:"<<"\n";
    cin>>cap;
    u=cap;
    cout<<"Enter the number of items:\n";
    cin>>n;
    float w[n],p[n],r[n],x[n]={0};
    cout<<"Enter the weight and value of " <<n<<" item:\n";
    for(i=0;i<n;i++)
    {
      cin>>w[i];
      cin>>p[i];
      r[i]=p[i]/w[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(r[j]<r[j+1])
            {
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
               
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
               
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(w[i]>cap)
        {
            break;
        }
        else
        {
            cap=cap-w[i];
            x[i]=1;
            tp=tp+p[i];
        }
    }
    if(i<n)
    {
        x[i]=cap;
        tp=tp+cap*r[i];
    }
    for(i=0;i<n;i++)
    {
     
        if(x[i]==1)
        {
          u=u-w[i];  
          cout<<i+1<<" "<<p[i]<<" "<<w[i]<<" "<<u<<".";  
        }
        else
        {
            u=u-cap;
            cout<<i+1<<" "<<int((cap/w[i])*100)<<"% "<<p[i]<<" "<<w[i]<<" "<<u<<" ";
        }
        cout<<"\n";
    }
    cout<<"Filled the bag with objects worth "<<tp<<".00 Rs.";
    return 0;
}
