/*
 * Jatin Kumar Mandav
 *
 * Sorting: Bubble Sort
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

// Performing Bubble Sort
void bubbleSort(int arr[], int size){
    for (int i = 0;i < size;i++){
        for (int j = i;j < size;j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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

    bubbleSort(arr, size);

    printf("\n");
    return 0;
}
