#include<stdio.h>
#include<stdlib.h>


struct node{
    int data ;
    struct  node *next ;
};

struct node *front = 0 ;
struct node *rear = 0 ;

void enqueue(int x){
    struct node* newnode ;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = x ;
    newnode ->next = 0;
    if(front == 0 && rear == 0){
        front = rear = newnode ; 
    }else{
        rear->next = newnode ;
        rear = newnode ;
    }
}

void display(){
    struct node *temp;
    if(front == 0 && rear == 0){
        printf("list is empty");
    }else{
        temp = front ; 
        while(temp != 0){
            printf("%d , " , temp->data);
            temp = temp->next ;
        }
    }
}

void dequeue(){
    struct node *temp ;
    temp = front ; 
    if(front == 0 && rear == 0){
        printf("list is empty");
    }else{
        printf("Dequeue Data  : %d", front -> data);
        front = front ->next ;
        free(temp);
    }
}

void peek(){
    if(front == 0 && rear == 0){
        printf("List is empty");
    }else{
        printf("First element : %d", front->data);
    }
}

int main(){
    while (1){
    int choice ;
    printf("\n 1. Enqueue data : \n 2. Dequeue data : \n 3. Display data : \n 4. Peek data : \n 5. Exit : \n");
    scanf("%d" , &choice);

        switch(choice){
        case 1:
            printf("Enter data : ");
            int x ; 
            scanf("%d", &x);
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

        default : 
            printf("Invalid case !");
            break;             

    }

    }

    return 0 ;
}
