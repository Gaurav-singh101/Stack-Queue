// weasted of memory 

#include<stdio.h>
#include<stdlib.h>

#define N 5
int queue[N] ;
int front = -1 ; 
int rear = -1 ; 

void enqueue(int x){
    if(rear == N-1){
        printf("Overflow");
    }else if(front == -1 && rear == -1){
        front = rear = 0 ; 
        queue[rear] = x ; 
    }else{
        rear++ ; 
        queue[rear] = x ;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("underflow");
    }else if(front == rear){
        front = rear = -1 ;     
    }else{
        printf("Dequeue element is : %d" , queue[front]);
        front++ ; 
    }
}


void display(){
    int i ;
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }else{
        for(i = front ; i < rear + 1 ; i++){
            printf("%d , " , queue[i]);
        }
    }
}

void peek(){

    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }else{
        printf(" Peek element is : %d", queue[front]);
    }
}


int main(){

    while(1){
    int choice , x ;
    printf("\n 1. Add in queue :  \n 2. Delete in queue :  \n 3. Display queue : \n 4. Peek queue : \n");
    scanf("%d" , &choice);
    switch (choice){
    case 1:
        printf("Enter value : ");
        scanf("%d" ,&x);
        enqueue(x);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        peek();
        break;
    case 5:
        exit(0);
        break;                

    default:
        printf("Invalid choice");
        break;
    }
    }
    return 0 ;
}







