/*
 * Jatin Kumar Mandav
 *
 * Hashing: Double Hashing
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
 * Formula: h(k, i) = [h1(k) i*h2(k)] mod m
 * where, m = Size of Hash Table
 *        h1(k) = key mod m
 *        h2(k) = key mod m - 2
 *        mod = % Operator
*/
void insertDouble(int key){
    int index = 0, m = SIZE;
    int hKey1 = key%m, hKey2 = key%(m - 2);
    for(int i = 0;i < SIZE;i++){
        index = (hKey1 + i*hKey2)%m;
        if (hashTable[index] == -1){
            hashTable[index] = key;
            return;
        }
    }
}

// Search for Key
int searchDouble(int toFind){
    int index = 0, m = SIZE;
    int hKey1 = toFind%m, hKey2 = toFind%(m - 2);
    for (int i = 0;i < SIZE;i++){
        index = (hKey1 + i*hKey2)%m;
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
void deleteDouble(int toDelete){
    int index = searchDouble(toDelete);
    if (index == -1){
        printf("%d is not Present in the Hash Table, Cannot be Deleted!\n", toDelete);
    }
    else{
        hashTable[index] = -1;
    }
}

// Quadratic Hashing
void doubleHashing(){
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
                insertDouble(key);
                break;
            }
            case 2:{
                int toDelete;
                printf("Which Value to Delete: ");
                scanf("%d", &toDelete);
                deleteDouble(toDelete);
                break;
            }
            case 3:{
                int toFind;
                printf("Which Value to Find: ");
                scanf("%d", &toFind);
                int index = searchDouble(toFind);
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
    doubleHashing();
    return 0;
}
