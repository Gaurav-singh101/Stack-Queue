#include<stdio.h>

#define N 5
int stack[N]; 
int top = -1;

void Push() {
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if (top == N - 1) {
        printf("Overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void Pop() {
    int item; 
    if (top == -1) {
        printf("Underflow\n");
    } else {
        item = stack[top];
        top--;
        printf("Popped item is: %d\n", item);
    }  
}

void Peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top most element is: %d\n", stack[top]);
    }
}

void Display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        int i;
        for (i = top; i >= 0; i--) {
            printf("%d,  ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("Enter 1 for Push: \nEnter 2 for Pop: \nEnter 3 for Peek: \nEnter 4 for Display: \n");
        int choice;
        scanf("%d", &choice);  

        switch (choice) {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break; 
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
