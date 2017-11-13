/*
 * Jatin Kumar Mandav
 *
 * Searching: Linear Search
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

// Linear Search: Returns the Index or -1 if not Found
int linearSearch(int arr[], int size, int toFind){
    for (int i = 0;i < size;i++){
        if (arr[i] == toFind){
            return i;
        }
    }
    return -1;
}

// The Main Function
int main(void){
    int size;
    printf("Size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Array: ");
    for (int i = 0;i < size;i++){
        scanf("%d", &arr[i]);
    }
    int toFind;
    printf("To Find: ");
    scanf("%d", &toFind);
    int index;
    index = linearSearch(arr, size, toFind);
    if (index == -1){
        printf("%d is not in the List.\n", toFind);
    }
    else{
        printf("%d Found at Index %d in the List.\n", toFind, index);
    }
    return 0;
}
