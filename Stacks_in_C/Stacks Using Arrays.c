/*
 * Jatin Kumar Mandav
 *
 * Stacks Using Arrays
 *
 * Website : https://jatinmandav.wordpress.com
 * YouTube : https://www.youtube.com/channel/UCdpf6Lz3V357cIZomPwjuFQ?view_as=subscriber
 *
 * Facebook : facebook.com/jatinmandav
 * Twitter : @jatinmandav
 * Gmail : jatinmandav3@gmail.com
 *
*/

// Maximum Capacity
#define CAPACITY 100
#include<stdio.h>

// Stack Structure
struct stack{
    int top;
    int numbers[CAPACITY];
}s;

// Push a new Element to the Stack
void Push(int num){
    if (s.top == CAPACITY){
        printf("Stack is FULL!\n");
        return;
    }
    s.top++;
    s.numbers[s.top] = num;
}

// Check if Stack is Empty
int isEmpty(){
    if (s.top == -1){
        return 1;
    }
    return 0;
}

// Pop the Topmost element from the Stack
int Pop(){
    if (isEmpty()){
        printf("Stack is EMPTY!\n");
        return 0;
    }
    int num = s.numbers[s.top];
    s.top--;
    return num;
}

// Display the Stack
void Display(){
    if (isEmpty()){
        printf("Stack is EMPTY!\n");
        return;
    }
    for (int i = s.top; i >= 0;i--){
        printf("%d ", s.numbers[i]);
    }
}

// The Main Function
int main(void){
    s.top = -1;
    int choice;
    do{
        printf("1. Push a Number\t 2. Pop a Number\t 3. Display Stack\t 4. QUIT\n");
        printf("Your Choice : ");
        scanf("%d", &choice);
        switch(choice){
            // Push new element in Stack
            case 1:{
                printf("Number to Puch in Stack : ");
                int n;
                scanf("%d", &n);
                Push(n);
                break;
            }
            // Pop Topmost element from Stack
            case 2:{
                int num = Pop();
                printf("Number Popped : %d\n", num);
                break;
            }
            // Display the Stack
            case 3:{
                printf("Stack : ");
                Display();
                printf("\n");
                break;
            }
            // Exit the Loop
            case 4:{
                break;
            }
            default:{
                printf("Invalid Choice!\n");
                break;
            }
        }
    }while(choice != 4);
    return 0;
}
