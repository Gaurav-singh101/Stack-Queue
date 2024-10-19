#include<stdio.h>
#include<stdlib.h>

#define N 5 
int queue[N] ;
int front = -1 ; 
int rear = -1 ;

void Enqueue(int x){
    if(front == -1 && rear == -1){
        front = rear = 0 ;
        queue[rear] = x ; 
    }else if((rear + 1) % N == front){
        printf("Overflow condition");
    }else{
        rear = (rear + 1)% N ; 
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow condition");
    }else if(front == rear){
        printf("Dequeue element is : %d " , queue[front]);
        front = rear = -1 ;
    }else{
        printf("Dequeue element is : %d " , queue[front]);  
        front = (front + 1) % N ;
    }
}

void display(){
    int i = front ;
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }else{
        printf("Queue is : ");
        while(i != rear){
            printf("%d , " , queue[i]);
            i = (i + 1) % N ;
        }
        printf("%d" , queue[rear]);
    }
}

void peek(){

    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }else{
        printf("First element : %d",queue[front]);
    }
}


int main(){

while(1){
    int choice ;
    int x ;
    printf("\n 1. Enqueue element : \n 2. Dequeue element : \n 3. Display element : \n 4. peek element : \n");
    scanf("%d" , &choice);
    switch(choice){
        case 1:
            printf("Enter data : ");
            scanf("%d", &x);
            Enqueue(x);
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
            printf("Invalid choice !");
            break;       
    }

}
    return 0 ;
}












