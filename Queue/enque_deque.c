#include <stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};
// empty condition
int isempty(struct queue*q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
// is full codition
int isFull(struct queue*q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
//enque
void enqueue(struct queue*q,int val){
    if(isFull(q)){
        printf("this queue is full");
    }
    else{
        q->r++;
    q->arr[q->r]=val;
    }

};
// DEQUE    
int dequeue(struct queue*q){
    int a=-1;
    if(isempty(q)){
        printf("this queue is full");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
};
int main(){
    struct queue q;
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,11);
    enqueue(&q,14);
    // only prints jitna hamne elements queue me feed kiya hai
    for(int i=0;i<=q.r;i++){
        printf(" %d ",q.arr[i]);
    }
    // ye wala poora print karega jonse index tk hamne value dali hai wo print hoga and uske aage ke 0 print honege
    for(int i=0;i<q.size-1;i++){
        printf(" %d ",q.arr[i]);
    }
    // deque portion
    printf("\n Dequeuing element : %d ",dequeue(&q));
    printf("\n Dequeuing element : %d ",dequeue(&q));
    printf("\n Dequeuing element : %d ",dequeue(&q));
}   
