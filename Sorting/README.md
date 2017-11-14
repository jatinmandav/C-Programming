# Sorting-In-C

Sorting Using C Programming Language.

  - Bubble Sort
    - Bubble Sort is the Simplest sorting algorithm that works by repeated swapping the adjacent elements if they are in wrong order.
    - Time Complexity: O(n*n)
    - Best Case (Array is Sorted): O(n)
    - Worst Case (Array is reverse Sorted): O(n*n)
    - Auxiliary Space: O(1)
    - Code: [Bubble Sort](BubbleSort.c/)
    
  - Selection Sort
    - The Selection Sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning.
    - The algorithm divides the array into two parts:
      1. Subarray which is sorted
      2. Remaining subarray is unsorted
    - In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
    - Time Complexity: O(n*n)
    - Auxiliary Space: O(1)
    - Code: [Selection Sort](SelectionSort.c/)
  
  - Insertion Sort
    - The array is searched sequentially and unsorted items are moved and inserted into the sorted sub-list(in the same array).
    - Algorithm:
      - If it is the first element, it is already sorted.
      - Pick next element.
      - Compare with all elements in sorted sub-list.
      - Shift all the elements in the sorted sub-list that is greater than the value to be sorted.
      - Insert the value
      - Repeat until list is sorted.
    - Time Complexity: O(n*n)
    - Auxiliary Space: O(1)
    - Code: [Insertion Sort](InsertionSort.c/)
    
  - Quick Sort
    - Quick Sort is a Divide and Conquer algorithm. It picks a pivot point and partitions the array around that pivot.
    - Pivot is picked in following ways:
      - First Element as Pivot.
      - Last Element as Pivot.
      - Median is Pivot.
      - Random Element as Pivot.
    - Partition: Target of Partition is given an array and a pivot, put pivot at its correct position in sorted array and put all smaller elements before pivot and put all the greater elements after pivot/
    - Time Complexity: O(n*log(n))
    - Best: O(n*log(n))
    - Worst: O(n*n)
    - Code: [Quick Sort](QuickSort.c/)
  
  - Merge Sort
    - Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
    - Algorithm for mergeSort Function:
      - if right > left
        - Find the middle to divide the array into two halves.
        - Call mergeSort for first half.
        - Call mergeSort for second half.
        - Merge the two halves sorted.
    - Time Complexity: O(n*log(n))
    - Best: O(n*log(n))
    - Worst: O(n*log(n))
    - Auxiliary Space: O(n)
    - Code: [Merge Sort](MergeSort.c/)
