/*
 * Jatin Kumar Mandav
 *
 * Basic Operations on Double-Ended Queue with Circular Buffer
 * Operations - Append (Add at Last Position), Prepend (Add at First Position),
 *              Pop (Delete First Element), Pop Right (Delete Last Element), Displaying the Queue
 *
 * Website : https://jatinmandav.wordpress.com
 * YouTube : https://www.youtube.com/channel/UCdpf6Lz3V357cIZomPwjuFQ?view_as=subscriber
 *
 * Facebook : facebook.com/jatinmandav
 * Twitter : @jatinmandav
 * Gmail : jatinmandav3@gmail.com
*/

// Include Headers
#include<stdio.h>
#include<stdbool.h>

// Maximum Size of Queue
#define MAXSIZE 5

// Queue
int queue[MAXSIZE];
int front = -1, rear = -1;

// Checks if Queue is Empty
bool isEmpty(){
    if (front == -1 && rear == -1){
        return true;
    }
    return false;
}

// Checks if Queue is Full
bool isFull(){
    if (!isEmpty() && rear == front){
        return true;
    }
    return false;
}

// Add Element at Last Position
void append(int val){
    if (isEmpty()){
        rear = 0;
        front = 0;
        queue[rear] = val;
    }
    else{
        rear = (rear + 1)%MAXSIZE;
        if (isFull()){
            printf("Queue is Full!\n");
            rear = (MAXSIZE + rear - 1)%MAXSIZE;
        }
        else{
            queue[rear] = val;
        }
    }
}

// Add Element at First Position
void prepend(int val){
    if (isEmpty()){
        rear = 0;
        front = 0;
        queue[front] = val;
    }
    else{
        front = (MAXSIZE + front - 1)%MAXSIZE;
        if (isFull()){
            printf("Queue is Full!\n");
            front = (front + 1)%MAXSIZE;
        }
        else{
            queue[front] = val;
        }
    }
}

// Remove First Element
int pop(){
    int val = -1;
    if (isEmpty()){
        printf("Queue is Empty!\n");
    }
    else if (front == rear){
        val = queue[front];
        front = -1;
        rear = -1;
    }
    else{
        val = queue[front];
        front = (front + 1)%MAXSIZE;
    }
    return val;
}

// Remove Last Element
int popRight(){
    int val = -1;
    if(isEmpty()){
        printf("Queue is Empty!\n");
    }
    else if (front == rear){
        val = queue[front];
        front = -1;
        rear = -1;
    }
    else{
        val = queue[rear];
        rear = (MAXSIZE + rear - 1)%MAXSIZE;
    }
    return val;
}

// Display Queue
int displayQueue(){
    if (isEmpty()){
        printf("Queue is Empty!\n");
    }
    else{
        int i = front, index = 0;
        printf("%d, %d\n", i, rear);
        while(index != rear){
            index = i%MAXSIZE;
            printf("%d ", queue[index]);
            i = i + 1;
        }
    }
    printf("\n");
    for (int i = 0;i < MAXSIZE;i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// The Main Function
int main(void){
    int choice, flag = -1;
    while(true){
        printf("1. Append\t 2. Pop Left\t 3. Prepend\t 4. Pop Right\t 5. Display Queue");
        printf("\nYour Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:{
                int val;
                printf("Enter the Value to Append: ");
                scanf("%d", &val);
                append(val);
                break;
            }
            case 2:{
                int val = pop();
                if (val != -1){
                    printf("%d Popped!\n", val);
                }
                break;
            }
            case 3:{
                int val;
                printf("Enter the Value to Append: ");
                scanf("%d", &val);
                prepend(val);
                break;
            }
            case 4:{
                int val = popRight();
                if (val != -1){
                    printf("%d Popped!\n", val);
                }
                break;
            }
            case 5:{
                displayQueue();
                break;
            }
            default:{
                flag = 1;
            }
        }
        printf("\n");
        if (flag == 1){
            break;
        }
    }
}

