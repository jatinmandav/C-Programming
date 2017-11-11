/*
 * Jatin Kumar Mandav
 * 
 * Josephus Problem Using Singly Liked List in C Language
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

// Structure of Node for Linked list
struct node{
    int data;
    struct node* next;
}*start = NULL;

// Initial size of Linked List
int size, prevIndex = 0;

// Creating the Linked List of size "size" and data as its position in List
void createList(){
    struct node* p = start;
    int i = size, data = 1;
    while(i--){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        data++;
        if (start == NULL){
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

// Display the Linked List
void displayList(){
    struct node* p = start;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

// Delete the Node at index "index"
void deleteNodeAt(int index){
    index++;
    if (index > size || index < 1){
        printf("Out Of Bounds Index!\n");
        return;
    }
    struct node* p = start, *q;
    // If last Nose is to be deleted
    if (index == size){
        while(p->next->next != NULL){
            p = p->next;
        }
        q = p->next->next;
        p->next = NULL;
        free(q);
    }
    // If First Node is to be deleted
    else if (index == 1){
        q = start;
        start = q->next;
        free(q);
    }
    // If a node other than above is to be deleted
    else{
        int i = index - 2;
        while(i --){
            p = p->next;
        }
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
    // Decrease the "size" of list
    size --;
}

// Josephus Problem
void JosephusProblem(){
    int noRotation, index, roundNum = 0;
    printf("Count : ");
    scanf("%d", &noRotation);
    noRotation--;
    while(size - 1){
        roundNum++;
        // normalizing the index
        if (noRotation < size){
            index = noRotation;
        }
        else if (noRotation == size){
            index = 0;
        }
        else{
            index = noRotation%size;
        }
        // Calculating the index to be executed or deleted from List
        index = (index + prevIndex)%size;
        prevIndex = index;
        deleteNodeAt(index);
        // Displaying the List after every round of execution
        printf("Round %d : ", roundNum);
        displayList();
        printf("\n");
    }
}

// The Main Function
int main(void){
    printf("Number of Prisoners : ");
    scanf("%d", &size);
    createList();
    printf("Initial Order of Prisoners : ");
    displayList();
    printf("\n");
    // Josephus Problem
    JosephusProblem();
    // The Person That Survives
    printf("\nPerson ");
    displayList();
    printf("has Survived the Josephus Game!\n");
    return 0;
};
