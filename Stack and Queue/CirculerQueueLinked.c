 #include<stdio.h>
 #include<stdlib.h>

struct node{
    int data ; 
    struct node *next;
};

struct node *front = 0 ;
struct node *rear = 0 ;


void enqueue(int x){
    struct node *newnode ; 
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = x ; 
    newnode -> next = rear ;

    if(rear == 0){
        front = rear = newnode ;
        rear -> next = front ;
    }else{
        rear -> next = newnode;
        rear = newnode ;
        rear ->next = front ;
    }
}

void dequeue(){
    struct node *temp ;
    temp = front ;
    if(front == 0 && rear ==0){
        printf("Underflow");
    }else if(front == rear){
        printf("Deleted element : %d" , temp->data);
        front = rear = 0 ; 
        free(temp);
    }else{
        printf("Deleted element : %d" , temp->data);
        front = front ->next;
        rear ->next = front ; 
        free(temp);
    }

}

void display(){
    struct node *temp ; 
    temp = front ; 
    if(front == 0 && rear == 0){
        printf("Queue is empty");
    }else{
        while(temp -> next != front){
            printf("%d , " , temp -> data);
            temp = temp->next ;
        }
    printf("%d" , temp -> data);
    }

}



void peek(){
    if(front == 0 && rear == 0){
        printf("Queue is empty");
    }else{
        printf("%d" , front ->data);
    }
}


int main(){

while(1){
    int choice , x ;
    printf("\n 1. Enqueue : \n 2. Dequeue : \n 3. Display : \n 4. Peek : \n 5. Exit : \n");
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
                peek();
                break;
        case 5:
                exit(0);
        default:
                printf("Invalid choice !");
                break;
    }

}

    return 0 ;
}

























