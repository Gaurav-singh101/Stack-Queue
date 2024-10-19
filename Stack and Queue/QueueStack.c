#include<stdio.h>
#include<stdlib.h>

#define N 5 
int S1[N] , S2[N] ; 
int top1 = -1 , top2 = -1;
int count = 0 ;

void Push1(int data){
    if(top1 == N-1){
        printf("Stack is full");
    }else{
        top1++;
        S1[top1] = data;
    }
}

void Push2(int data){
    if(top2 == N-1){
        printf("Stack is full");
    }else{
        top2++;
        S2[top2] = data;
    }
}

int  Pop1(){
    return S1[top1--];
}

int Pop2(){
    return S2[top2--];
}


void enqueue(int x){
    Push1(x);
    count++ ;
}

void dequeue(){
    int i , a , b;
    if(top1 == -1 && top2 == -1){
        printf("Queue is empty");
    }else{
        for(i = 0 ; i < count ; i++){
            a = Pop1();
            Push2(a);
        }
        b = Pop2();
        printf("Deleted element : %d" , b);

        // Push back in stack 1 //

        count-- ; 
        for(i = 0 ; i < count ; i++){
            a = Pop2();
            Push1(a) ;
        }
    }
}


void display(){
    int i ;
    printf("Queue is : \n ");
    for(i = 0 ; i < top1 ; i++){
        printf("%d , " , S1[i]);
    }
      printf("%d" , S1[i]);

}

int main(){

int choice , x ;

while (1){
    printf("\n 1. Enqueue : \n 2. Dequeue : \n 3. Display : \n 4 . Exit : \n");
    scanf("%d" ,&choice);
    switch(choice){
        case 1:
                printf("Enter Data : ");
                scanf("%d" , &x);
                enqueue(x);
                break;
        case 2:
                dequeue();
                break;
        case 3:
                display();
                break;
        case 4:
                exit(0);
        default:
                printf("Invalid choice !");
                break;
    }

}
}












