/*
 * Jatin Kumar Mandav
 * 
 * Stacks Using Linked List
 *
 * Website : https://jatinmandav.wordpress.com
 * YouTube : https://www.youtube.com/channel/UCdpf6Lz3V357cIZomPwjuFQ?view_as=subscriber
 * 
 * Facebook : facebook.com/jatinmandav
 * Twitter : @jatinmandav
 * Gmail : jatinmandav3@gmail.com
 *
*/
#include<stdio.h>
#include<stdlib.h>

// Struct for node of Linked List
struct node{
    int data;
    struct node* next;
}*top = NULL;

// Push a new element to the Stack
void Push(int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Element Pushed Into the Stack\n");
}

// Pop the Topmost element From Stack
void Pop(){
    if (top == NULL){
        printf("The Stack is Empty!\n");
        return;
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = top;
    top = temp->next;
    free(temp);
    printf("Element Popped From the Stack\n");
}

// Display the Stack
void Display(){
    struct node* p = top;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// The Main Function
int main(void){
    int choice;
    do{
        printf(" ------------------ Menu -------------------\n");
        printf("1. Push\t 2. Pop\t 3. Display\t 4. Exit\n\nChoice: ");
        scanf("%d", &choice);
        switch(choice){
            // Push new Element to Stack
            case 1:{
                printf("Value to add to Stack : ");
                int val;
                scanf("%d", &val);
                Push(val);
                break;
            }
            // Pop Topmost element From Stack
            case 2:{
                Pop();
                break;
            }
            // Display the Stack
            case 3:{
                printf("The Stack : ");
                Display();
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
