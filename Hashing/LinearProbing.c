/*
 * Jatin Kumar Mandav
 *
 * Hashing: Linear Probing
 * Operations - Insert a Key, Delete a Key, Search for a Key, Display the Hash Table
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
#include<stdbool.h>

// Size of Hash Table
#define SIZE 10

int hashTable[SIZE];

// Initialize the Hash Table with Invalid Value : -1
void init(){
    for (int i = 0;i < SIZE;i++){
        hashTable[i] = -1;
    }
}

// Display the Hash Table
void displayHashTable(){
    for (int i = 0;i < SIZE;i++){
        printf("| %d ", hashTable[i]);
    }
    printf("|\n");
}

// Insert Key in Table
/*
 * Formula: h(k, i) = [h'(k) + i] mod m
 * where, m = Size of Hash Table
 *        h'(k) = key mod m
 *        mod = % Operator
*/
void insertLinear(int key){
    int index = 0, m = SIZE;
    int hKey = key%m;
    for(int i = 0;i < SIZE;i++){
        index = (hKey + i)%m;
        if (hashTable[index] == -1){
            hashTable[index] = key;
            return;
        }
    }
    printf("Key Cannot be Placed in Hash Table!\n");
}

// Search for Key
int searchLinear(int toFind){
    int index = 0, m = SIZE;
    int hKey = toFind%m;
    for (int i = 0;i < SIZE;i++){
        index = (hKey + i)%m;
        if (hashTable[index] == toFind){
            return index;
        }
        else if (hashTable[index] == -1){
            return -1;
        }
    }
    return -1;
}

// Delete a Key
void deleteLinear(int toDelete){
    int index = searchLinear(toDelete);
    if (index == -1){
        printf("%d is not Present in the Hash Table, Cannot be Deleted!\n", toDelete);
    }
    else{
        hashTable[index] = -1;
    }
}

// Linear Probing
void linearProbing(){
    int choice, flag = -1;
    while(true){
        printf("1. Insert\t 2. Delete\t 3. Search\t 4. Display\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int key;
                printf("Insert Key to Insert: ");
                scanf("%d", &key);
                insertLinear(key);
                break;
            }
            case 2:{
                int toDelete;
                printf("Which Value to Delete: ");
                scanf("%d", &toDelete);
                deleteLinear(toDelete);
                break;
            }
            case 3:{
                int toFind;
                printf("Which Value to Find: ");
                scanf("%d", &toFind);
                int index = searchLinear(toFind);
                if(index == -1){
                    printf("Element Does not Exist in the Hash Table.\n");
                }
                else{
                    printf("%d is Present at %d Index in Hash Table.\n", toFind, index);
                }
                break;
            }
            case 4:{
                displayHashTable();
                break;
            }
            default:{
                flag = 1;
            }
        }
        if (flag == 1){
            break;
        }
        printf("\n");
    }
}

// The Main Function
int main(void){
    init();
    linearProbing();
    return 0;
}
