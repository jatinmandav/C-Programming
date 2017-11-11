/*
 * Jatin Kumar Mandav
 *
 * Basic Operations on Queues with Direct Memory Allocation and Circular Buffer
 * Operations - Enqueue, Dequeue, Displaying the Queue
 *              Linear Searching the Queue
 *
 * Website : https://jatinmandav.wordpress.com
 * YouTube : https://www.youtube.com/channel/UCdpf6Lz3V357cIZomPwjuFQ?view_as=subscriber
 *
 * Facebook : facebook.com/jatinmandav
 * Twitter : @jatinmandav
 * Gmail : jatinmandav3@gmail.com
*/

// Including the Headers
#include<stdio.h>
#include<stdbool.h>

// Maximum Size of Queue
#define MAXSIZE 5

// Queue and the Front and Rear Indices
int queue[MAXSIZE];
int front = -1, rear = -1;
bool circular = false;

// Check if Queue is Empty
bool isEmpty(){
    if (front == -1 && rear == -1){
        return true;
    }
    return false;
}

// Check if Queue is Full
bool isFull(){
    if (!isEmpty()){
        if (circular){
            if (rear == front){
                return true;
            }
        }
        else{
            if (rear >= MAXSIZE){
                return true;
            }
        }
    }
    return false;
}

// Peek the Topmost Element in Queue
int Peek(){
    if (!isEmpty()){
        return queue[front];
    }
    return -1;
}

// Display the Queue
void displayQueue(){
    if (!isEmpty()){
        int i = front%MAXSIZE, index;
        index = i%MAXSIZE;
        if (circular){
            while(index != rear){
                index = i%MAXSIZE;
                printf("%d ", queue[index]);
                i = i + 1;
            }
        }
        else{
            for(int i = front;i < rear + 1;i++){
                printf("%d ", queue[i]);
            }
        }
    }
    else{
        printf("Queue is Empty!");
    }
    printf("\n");
}

// Enqueuing "val" to the Queue
void enqueueVal(int val){
    if (isEmpty()){
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else{
        if (circular){
            rear = (rear + 1)%MAXSIZE;
        }
        else{
            rear += 1;
        }
        if (isFull()){
            printf("Queue OverFlow!\nNo More Space Available!\n");
            rear = (MAXSIZE + rear - 1)%MAXSIZE;
        }
        else
            queue[rear] = val;
    }
}

// Dequeuing the Topmost Element in Queue
int dequeueVal(){
    if (isEmpty()){
            printf("Cannot Dequeue Element from Empty Queue!\n");
        return -1;
    }
    else if(front == rear){
        int val = Peek();
        front = -1;
        rear = -1;
        return val;
    }
    else{
        int val = Peek();
        if  (circular){
            front = (front + 1)%MAXSIZE;
        }
        else{
            front += 1;
        }
        return val;
    }
    return -1;
}

// Linear Search the Queue
void linearSearchQueue(int key){
    int pos = -1;
    if (isEmpty()){
        printf("No element in Queue to Search For!\n");
    }
    else{
        if (circular){
            int index = front, i = 0;
            while(index != rear){
                if (queue[index] == key){
                    pos = i;
                    break;
                }
                index = (index + 1)%MAXSIZE;
                i += 1;
            }
            if (queue[index] == key){
                pos = i;
            }
        }
        for (int i = front;i < rear + 1;i++){
            if (queue[i] == key){
                pos = i - front;
                break;
            }
        }
        if (pos == -1){
            printf("%d is not in the Queue!\n", key);
        }
        else{
            printf("%d Found at %d Index in Queue!\n", key, pos);
        }
    }
}

// The Main Function
int main(void){
    int choice, flag = 0;

    printf("1. Circular Buffer\t\t2. Direct Memory Allocation in Array\n");
    printf("Memory Allocation Choice: ");
    scanf("%d", &choice);
    if (choice == 1){
        circular = true;
    }
    while(1){
        printf("\n1. Display\t 2. Enqueue\n3. Dequeue\t 4. Linear Search\n5. Peek   \t 6. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:{
                displayQueue();
                break;
            }
            case 2:{
                int val;
                printf("Value: ");
                scanf("%d", &val);
                enqueueVal(val);
                break;
            }
            case 3:{
                int val;
                val = dequeueVal();
                if (val != -1){
                    printf("%d Dequeued from Queue!\n", val);
                }
                break;
            }
            case 4:{
                int key;
                printf("Element to search in Queue: ");
                scanf("%d", &key);
                linearSearchQueue(key);
                break;
            }
            case 5:{
                int val;
                val = Peek();
                if (val != -1){
                    printf("First Value in Queue: %d\n", val);
                }
                else{
                    printf("Queue is Empty!\n");
                }
                break;
            }
            case 6:{
                flag = 1;
            }
        }
        if (flag == 1){
            break;
        }
    }
    return 0;
}
