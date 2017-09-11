/*
 * Jatin Kumar Mandav
 * 
 * Basic Operations on Linked list
 * Operations - Creating the linked list, Displaying the Linked List, 
 *              Inserting New Node, Deleting a Node, Linear Search
 *
 * Website : https://jatinmandav.wordpress.com
 * YouTube : https://www.youtube.com/channel/UCdpf6Lz3V357cIZomPwjuFQ?view_as=subscriber
 * 
 * Facebook : facebook.com/jatinmandav
 * Twitter : @jatinmandav
 * Gmail : jatinmandav3@gmail.com
*/

// Including the headers
#include<stdio.h>
#include<stdlib.h>

// Structure for node of Linked List
struct node{
    int data;
    struct node* next;
}*start = NULL;

// Initial Size of Linked List
int size;

// Creating a new Linked List of length "size"
void createList(){
    int data, i = size;
    struct node* p = start;
    while (i--){
        printf("Data : ");
        scanf("%d", &data);
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        if (!start){
            start = newNode;
            p = start;
        }
        else{
            p->next = newNode;
            p = p->next;
        }
        newNode->next = NULL;
    }
}

// Displaying the Complete Linked List
void displayList(){
    printf("\nList : ");
    struct node* p = start;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Insert a new Node at index "index"
void insertNodeAt(int index){
    // Validating the index
    if (index > size + 1 || index < 1){
        printf("Index Out Of Bounds!\n");
        return;
    }
    struct node* p = start;
    int data, i;
    printf("Data : ");
    scanf("%d", &data);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    // If Node is to be added at the end of list
    if (index == size){
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
        newNode->next = NULL;
    }
    // If Node is to be added at the beginning
    else if(index == 1){
        newNode->next = start;
        start = newNode;
    }
    // If Node is to be added at any point other than ends
    else{
        i = index - 2;
        while(i--){
            p = p->next;
        }
        printf("%d\n",p->data);
    
        newNode->next = p->next;
        p->next = newNode;
    }
    // Increase the "size" of linked list
    size++;
}

// Deleting the Node at index "index"
void deleteNodeAt(int index){
    // Validating the index
    if (index > size || index < 1){
        printf("Index Out Of Bounds!\n");
        return;
    }
    struct node* p = start, *q;
    // If last Node is to be deleted
    if (index == size){
        while(p->next->next != NULL){
            p = p->next;
        }
        q = p->next->next;
        p->next = NULL;
        free(q);
    }
    // If first Node is to be deleted
    else if(index == 1){
        q = start;
        start = start->next;
        free(q);
    }
    // If any node is to be deleted other than ends
    else{
        int i = index - 2;
        while(i--){
            p = p->next;
        }
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
    // Decrease the "size"
    size--;
}

// Perform Linear Search for "toFind"
int linearSearch(int toFind){
    struct node* p = start;
    int index = 0;
    while(p != NULL){
        if (p->data == toFind){
            // Element Found!
            return 1 + index;
        }
        else{
            index++;
            p = p->next;
        }
    }
    // Element not Found!
    return 0;
}

// The Main Function
int main(void){
    //Create a linked list of size "size" to start with
    printf("Size of Linked list : ");
    scanf("%d", &size);
    createList();
    displayList();
    
    int choice = 0;
    // Menu driven execution operations
    do{
        printf("\n1. Insert New Node\t 2. Delete a Node\t 3. Linear Search\t 4. Display List\t 5.QUIT\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            // Insert a New Node at "index"
            case 1:{
                int index;
                printf("Insert Node at : ");
                scanf("%d", &index);
                insertNodeAt(index);
                break;
            }
            // Delete Node at "index"
            case 2:{
                int index;
                printf("Position to Delete the Node : ");
                scanf("%d", &index);
                deleteNodeAt(index);
                break;
            }
            // Perform Linear Search for toFind
            case 3:{
                int toFind, index;
                printf("Number to Find : ");
                scanf("%d", &toFind);
                index = linearSearch(toFind);
                if (index){
                    printf("\'%d\' Found at %d!\n", toFind, index);
                }
                else{
                    printf("\'%d\' Not Found!\n", toFind);
                }
                break;
            }
            // Display the complete list
            case 4:{
                displayList();
                break;
            }
            // Exit the Loop
            case 5:{
                break;
            }
            default:{
                printf("Invalid Choice!\n");
            }
        }
    }while(choice != 5);
    
    return 0;
}
