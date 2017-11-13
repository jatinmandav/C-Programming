/*
 * Jatin Kumar Mandav
 *
 * Searching: Binary Search
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
#include<stdbool.h>

// Check if Array is Sorted
bool isSorted(int arr[], int size){
    for (int i = 0;i < size - 1;i++){
        if (arr[0] > arr[1]){
            if (arr[i] < arr[i + 1]){
                return false;
            }
        }
        else{
            if (arr[i] > arr[i + 1]){
                return false;
            }
        }
    }
    return true;
}

// Perform Binary Search
int binarySearch(int arr[], int size, int toFind){
    bool isSort = isSorted(arr, size);
    if(!isSort){
        return -2;
    }
    else{
        int start = 0, end = size - 1, mid;
        while(start <= end){
            mid = start + (end - start)/2;
            if (arr[mid] == toFind){
                return mid;
            }
            else if(toFind > arr[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
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
    printf("Sorted Array: ");
    for (int i = 0;i < size;i++){
        scanf("%d", &arr[i]);
    }
    int toFind;
    printf("To Find: ");
    scanf("%d", &toFind);
    int index = binarySearch(arr, size, toFind);
    if (index == -2){
        printf("Array is Not Sorted.\n");
    }
    else if (index == -1){
        printf("%d is not in the List.\n", toFind);
    }
    else{
        printf("%d Found at Index %d in List.\n", toFind, index);
    }
    return 0;
}
