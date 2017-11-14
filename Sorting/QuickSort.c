/*
 * Jatin Kumar Mandav
 *
 * Sorting: Quick Sort
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

// Swaping two values
int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Takes last element as Pivot and moves all smaller elements to its left and all higher elements to its right.
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low;j < high;j++){
        if (arr[j] <= pivot){
            i += 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Performing Quick Sort Recursively
void quickSort(int arr[], int size, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, size, low, pi - 1);
        quickSort(arr, size, pi + 1, high);
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

    quickSort(arr, size, 0, size - 1);

    for (int i = 0;i < size;i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
