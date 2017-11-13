# Searching-In-C
Searching Using C Language

  - [Linear Search](Searching/LinearSearch.c/)
    - Algorithm:
      - Start from the leftmost element of arr[ ] and one by one compare x with each element of arr[ ]
      - If x matches with an element, return the index.
      - If x doesn’t match with any of elements, return -1.
    - Time Complexity: O(n) where, n = Size of given array.
  
  - [Binary Search](Searching/BinarySearch.c/)
    - Algorithm:
      - Compare x with the middle element.
      - If x matches with middle element, we return the mid index.
      - Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
      - Else (x is smaller) recur for the left half.
    - Time Complexity: O(log(n)) where, n = Size of given array
  
  - [Interpolation Search](Searching/InterpolationSearch.c/)
    - Algorithm:
      - pos = low + (toFind-arr[low])*(high-low)/(arr[high]-arr[low]) where, low = Starting Index, high = Ending Index
      - In a loop, calculate the value of “pos” using the probe position formula.
      - If it is a match, return the index of the item, and exit.
      - If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array.
      - Repeat until a match is found or the sub-array reduces to zero.
    - Time Complexity: O(log(log(n))) where, n = Size of given array
      
   - [Jump Search](Searching/JumpSearch.c/)
     - Algorithm:
       - jump = Size of Jump
       - Jump from index 0 to index jump.
       - Jump from index jump to 2*jump.
       - Jump from index 2*jump to 3*jump. And so on...
       - If arr[index1] <= toFind < arr[index1 + jump], perform a Linear Search between (index1) and (index1 + jump)
       - Most Optimal Jump = sqrt(n) where, n = Size of given Array
     - Time Complexity: O(sqrt(n)) where, n = Size of given Array
