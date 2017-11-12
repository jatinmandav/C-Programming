/*
 * Jatin Kumar Mandav
 *
 * Priority Queue : Basic Operations Using Linked List
 * Operations - Creating the Queue, Adding Data according to Priority,
 *              Removing Data according to Priority (Here Maximum Priority is removed), Displaying the Queue
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
#include<stdlib.h>
#include<stdbool.h>

// Length of the Queue
int len = 0;

// Structure for node/Queue Element
struct node{
    int data;
    int priority;
    struct node* next;
}* start = NULL;

// Check if Queue is Empty
bool isEmpty(){
    if (start == NULL){
        return true;
    }
    return false;
}

// Get Index of where to insert the next element in Queue
int getIndex(int key){
    int index = 0;
    struct node* p = start;
    if (isEmpty()){
        return index;
    }
    else{
        while(p->next != NULL){
            if (key >= p->priority){
                return index;
            }
            p = p->next;
            index += 1;
        }
        if (key >= p->priority){
            return index;
        }
    }
    index += 1;
    return index;
}

// Add Value at index According to its Priority
void enqueueVal(int val, int key){
    int index;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("No more Memory Available!\n");
        return;
    }
    newNode->data = val;
    newNode->priority = key;
    newNode->next = NULL;
    if (isEmpty()){
        start = newNode;
    }
    else{
        struct node* p = start;
        index = getIndex(key);
        if (index == 0){
            newNode->next = start;
            start = newNode;
        }
        else{
            for (int i = 0;i < index - 1;i++){
                p = p->next;
            }
            newNode->next = p->next;
            p->next = newNode;
        }
    }
    len += 1;
}

// Remove/Dequeue Value according to Priority,  Highest removed First
int dequeueVal(){
    len -= 1;
    int val = -1;
    struct node* toDelete = start;
    if (isEmpty()){
        printf("Queue is Empty!");
    }
    else{
        val = start->data;
        start = start->next;
        free(toDelete);
    }
    return val;
}

// Display the Queue
void displayQueue(){
    struct node* p = start;
    if (isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }
    while(p->next != NULL){
        printf("|%d, %d|->", p->data, p->priority);
        p = p->next;
    }
    printf("|%d, %d|->NULL\n", p->data, p->priority);
}

// Peek which element is at top in Queue
int peek(){
    int val;
    if (isEmpty()){
        val = -1;
    }
    else{
        val = start->data;
    }
    return val;
}

// The Main Function
int main(void){
    int val, key, flag = -1;
    int choice;
    while(true){
        printf("1. Enqueue\t 2. Dequeue\t 3. Display\t 4. Peek\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int val, key;
                printf("Value and Priority: ");
                scanf("%d %d", &val, &key);
                enqueueVal(val, key);
                break;
            }
            case 2:{
                int val = dequeueVal();
                if (val != -1){
                    printf("%d Dequeued!", val);
                }
                break;
            }
            case 3:{
                displayQueue();
                break;
            }
            case 4:{
                int val = peek();
                if (val == -1){
                    printf("Queue is Empty!");
                }
                else{
                    printf("Top on Queue: %d", val);
                }
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
    return 0;
}

