/*
 * Jatin Kumar Mandav
 *
 * Sorting: Merge Sort
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

// Merge Two Sub-Arrays
void merge(int arr[], int low, int mid, int high){
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int left[size1], right[size2];

    for (int i = 0;i < size1;i++){
        left[i] = arr[low + i];
    }

    for(int i = 0;i < size2;i++){
        right[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = low;
    while(i < size1 && j < size2){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i += 1;
        }
        else{
            arr[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    while (i < size1){
        arr[k] = left[i];
        k += 1;
        i += 1;
    }

    while (j < size2){
        arr[k] = right[j];
        k += 1;
        j += 1;
    }
}

// Perform Merge Sort Recursively
void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, size - 1);

    for (int i = 0;i < size;i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
