/*
 * Jatin Kumar Mandav
 * 
 * Basic Operations on Circular Linked list
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

// Including The Headers
#include<stdio.h>
#include<stdlib.h>

// Struct for node in Circular Linked List
struct node{
    int data;
    struct node* next;
}*start = NULL;

// Initial Size
int size;

// Create Cirular List
void createList(){
    struct node* p = start;
    printf("Enter Data :\n");
    int data;
    for (int i = 0;i < size;i++){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &data);
        newNode->data = data;
        if (start == NULL){
            start = newNode;
            p = start;
        }
        else{
            p->next = newNode;
            p = p->next;
        }
        newNode->next = start;
    }
}

// Display Linked List
void displayList(){
    int i = size;
    struct node* p = start;
    while(i--){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Insert Node at "index"
void insertNodeAt(int index){
    // Validating the Index
    if (index < 0 || index > size - 1){
        printf("Invalid Index!\n");
        return;
    }
    int data;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &data);
    newNode->data = data;
    struct node* p = start;
    // Insert at Beginning
    if (index == 0){
        while(p->next != start){
            p = p->next;
        }
        p->next = newNode;
        newNode->next = start;
        start = newNode;
    }
    // Insert at any index
    else{
        int i = index - 1;
        while(i--){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    size ++;
}

// Delete a node from Circular Linked List
void deleteNodeAt(int index){
    if (index < 0 || index > size - 1){
        printf("Invalid Index!\n");
        return;
    }
    struct node* toDelete = NULL, *p = start;
    int i = index - 1;
    // Delete At Beginning
    if (i == -1){
        while(p->next != start){
            p = p->next;
        }
        toDelete = start;
        p->next = p->next->next;
        start = p->next;
        free(toDelete);
    }
    // Delete at any index
    else{
        while(i--){
            p = p->next;
        }
        toDelete = p->next;
        p->next = p->next->next;
        free(toDelete);
    }
    size --;
}

// Main Function
int main(void){
    printf("Size: ");
    scanf("%d", &size);
    createList();
    displayList();
    int choice = 0, index;
    do{printf("\n\n1. Display List\t 2. Insert Node\t 3. Delete Node\t 4. Quit");
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
