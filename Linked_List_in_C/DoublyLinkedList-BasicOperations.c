/*
 * Jatin Kumar Mandav
 * 
 * Basic Operations on Doubly Linked list
 * Operations - Creating the linked list, Displaying the Linked List, 
 *              Inserting New Node, Deleting a Node
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

// Struct for node of Doubly Linked List
struct node{
    int data;
    struct node* next;
    struct node* prev;
}*start = NULL;

// Initial Size of Linked List
int size;

// Create Doubly Linked List
void createList(){
    printf("Enter Data : \n");
    struct node* p = start;
    int data;
    for(int i=0;i<size;i++){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &data);
        newNode->data = data;
        
        if (start == NULL){
            start = newNode;
            start->prev = NULL;
            p = start;
        }
        else{
            newNode->prev = p;
            p->next = newNode;
            p = p->next;
        }
        p->next = NULL;
    }
}

// Display Doubly Linked List
void displayList(){
    struct node* p = start;
    while(p->next != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
    while(p->prev != NULL){
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("%d\n", p->data);
}

// Insert Node in Doubly Linked List at "index"
void insertNodeAt(int index){
    // Validating the Index
    if (index < 0 || index>= size){
        printf("Invalid Index!\n");
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    int data;
    struct node* p = start;
    printf("Data : ");
    scanf("%d", &data);
    newNode->data = data;
    // Insert at Beginning of Doubly Linked List
    if (index == 0){
        newNode->prev = NULL;
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
    // Insert at End of Doubly Linked List
    else if (index == size - 1){
        while(p->next != NULL){
            p = p->next;
        }
        newNode->prev = p;
        p->next = newNode;
        newNode->next = NULL;
    }
    // Insert at any index of Doubly Linked List
    else{
        int i = index - 2;
        while(i--){
            p = p->next;
        }
        newNode->prev = p;
        newNode->next = p->next;
        p->next->prev = newNode;
        p->next = newNode;
    }
    size ++;
}

// Delete Node in Doubly Linked List at "index"
void deleteNodeAt(int index){
    // Validating the Index
    if (index < 0 || index > size - 1){
        printf("Invalid Index!\n");
        return;
    }
    struct node* toDelete = NULL, *p = start;
    // Delete at Beginning of Doubly Linked List
    if (index == 0){
        toDelete = start;
        start = start->next;
        start->prev = NULL;
        free(toDelete);
    }
    // Delete at End of Doubly Linked List
    else if (index == size - 1){
        while(p->next != NULL){
            p = p->next;
        }
        p = p->prev;
        toDelete = p->next;
        p->next = NULL;
        free(toDelete);
    }
    // Delete at any index of Doubly Linked List
    else{
        int i = index - 2;
        while(i--){
            p = p->next;
        }
        toDelete = p->next;
        p->next = p->next->next;
        p->next->prev = p;
        free(toDelete);
    }
    size --;
}

// Main Function
int main(void){
    printf("Size : ");
    scanf("%d", &size);
    createList();
    displayList();
    int choice = 0, index;
    do{
        printf("\n\n1. Display List\t 2. Insert Node\t 3. Delete Node\t 4. Quit");
        printf("\nChoice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                displayList();
                break;
            }
            case 2:{
                printf("Insert Node At (INDEX): ");
                scanf("%d", &index);
                insertNodeAt(index);
                break;
            }
            case 3:{
                printf("Delete Node At (INDEX): ");
                scanf("%d", &index);
                deleteNodeAt(index);
                break;
            }
            case 4:{
                break;
            }
            default:{
                printf("Invalid Choice!\n");
            }
        }
        
    }while(choice != 4);
    return 0;
}


