/*
 * Jatin Kumar Mandav
 *
 * Sorting: Insertion Sort
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

// Performing Insertion Sort
void insertionSort(int arr[], int size){
    for (int i = 1;i < size;i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j]){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }

    for (int i = 0;i < size;i++){
        printf("%d ", arr[i]);
    }
}

// The Main Function
int main(void){
    int size;
    printf("Size: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0;i < size;i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, size);

    printf("\n");
    return 0;
}
