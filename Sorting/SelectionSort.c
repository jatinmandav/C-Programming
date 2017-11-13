/*
 * Jatin Kumar Mandav
 *
 * Sorting: Selection Sort
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

// Performing Selection Sort
void selectionSort(int arr[], int size){
    for (int i = 0;i < size - 1;i++){
        int index = i;
        for (int j = i + 1;j < size;j++){
            if (arr[j] < arr[index]){
                index = j;
            }
        }
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
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

    selectionSort(arr, size);

    printf("\n");
    return 0;
}
