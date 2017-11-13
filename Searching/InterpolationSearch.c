/*
 * Jatin Kumar Mandav
 *
 * Searching: Interpolation Search
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

// Checking if array is Sorted
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

// Performing the Interpolation Search
int interpolationSearch(int arr[], int size, int toFind){
    bool isSort = isSorted(arr, size);
    if (!isSort){
        return -2;
    }
    else{
        int low = 0, high = size - 1, pos;
        while(low <= high && arr[low] <= toFind && arr[high] >= toFind){
            pos = low + ((high - low)*(toFind - arr[low]))/(arr[high] - arr[low]);
            if (toFind == arr[pos]){
                return pos;
            }
            else if(toFind > arr[pos]){
                low = pos + 1;
            }
            else{
                high = pos - 1;
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
    int index = interpolationSearch(arr, size, toFind);
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
