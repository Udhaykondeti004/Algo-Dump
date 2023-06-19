//#include <stdio.h>
//#include <stdlib.h>
#include<iostream>
using namespace std;
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->r == q->size - 1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("The Queue is Full.");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));

    int node;
    int i;
    int n;
    cin>>n;
    int a[n][n];
    int visited[n];
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    int k1=0,k2=0;
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    while(k1!=-1 && k2!=-1)
    {
        cin>>k1>>k2;
        if(k1!=-1 && k2!=-1)
        {
            a[k1][k2]=1;
        }
    }
    int key1;
    cin>>key1;
    visited[key1] = 1;
    enqueue(&q, key1);
    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for(int j = 0; j<n; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
        cout<<node<<" ";
    }
     return 0;
}
