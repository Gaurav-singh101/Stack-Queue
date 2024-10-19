#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ; 
    struct node *link ; 
};

struct node *top = 0 ;

void push(int x){
    struct node *newnode ;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = x ;
    newnode -> link = top ;
    top = newnode ;
}

void display(){

    struct node *temp; 
    temp = top ;
    if(top == 0){
        printf("List is empty !");
    }else{
        while(temp != 0){
            printf("%d ,  " , temp -> data);
            temp = temp-> link ;
        }
    }
}

void peek(){
    if(top == 0){
        printf("Stack is empty !");
    }else{
        printf("Top element : %d " , top -> data);
    }
}

void pop(){
    struct node *temp; 
    temp = top ;
    if(top == 0){
        printf("Stack is empty !");
    }else{
        printf("Poped element : %d" , top->data);
        top = top ->link ;
        free(temp);
    }
}

int main(){
    int choice ; 
    int data ;
    while(1){
    printf("\n 1. Push element \n 2. Display element \n 3. Peek \n 4. Pop \n 5. Exit \n\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1 :
            printf("Enter data : ");
            scanf("%d",&data);
            push(data);
            break;
        case 2 :
            display();
            break;
        case 3 :
            peek() ;
            break;
        case 4 :
            pop();
            break;
        case 5 :
            exit(0);
            break;    
        default : 
            printf("Invalid choice !");
            break;    
    }
    }

    return 0 ;
}