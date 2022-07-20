//BFS

#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(sizeof(int)*q.size);

    int node; //used to traverse the graph
    int i = 0; //node we are currently at...initialize it with any node of choice
    int visited[8] = {0, 0, 0, 0, 0, 0, 0,0}; //unvisited is 0 and visited is 1
    int a[8][8]={
        {0,1,1,1,0,0,0,0},
        {1,0,0,0,1,0,0,0},
        {1,0,0,0,0,1,0,0},
        {1,0,0,0,0,0,1,0},
        {0,1,0,0,0,0,0,1},
        {0,0,1,0,0,0,1,0},
        {0,0,0,1,0,0,0,1},
        {0,0,0,0,1,1,1,0},
    };
    /*
        0 
      / | \
     1  2  3 
     |  |  |
     4  5  6
      \ | /
        7
    */
    printf("%d ", i); //printing source node
    visited[i] = 1; //marking this node visited
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q); //plucking the top element in queue
        for (int j = 0; j < 8; j++) //since size of graph is 7
        {
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}