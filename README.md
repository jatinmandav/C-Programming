# C-Programming

Here you can find different C programs from different topics in C Programming

- [Linked List in C](Linked_List_in_C/)
  - A linked list is a set of dynamically allocated nodes, arranged in such a way that each node contains one value and one pointer. The pointer always points to the next member of the list. If the pointer is NULL, then it is the last node in the list.
A linked list is held using a local pointer variable which points to the first item of the list. If that pointer is also NULL, then the list is considered to be empty.
  - Advantages: Dynamic of Size, Easy Insertion or delection.
  - Drawbacks: Random Access in not Allowed, Extra Memory to store Pointer is required
  - Examples and Code: 
    - [Singly Linked List - Basic Operations](Linked_List_in_C/SinglyLinkedList_BasicOperations.c/)
    - [Doubly Linked List - Basic Operations](Linked_List_in_C/DoublyLinkedList_BasicOperations.c/)
    - [Circular Linked List - Basic Operations](Linked_List_in_C/CircularLinkedList_BasicOperation.c/)
    - [Josephus Problem Using Singly Linked List](Linked_List_in_C/JosephusProblemUsingSinglyLinkedList.c/)

- [Stacks in C](Stacks_in_C/)
  - A Stack is a data structure which is used to store data in a particular order. Two operations that can be performed on a Stack are: Push operation which inserts an element into the stack. Pop operation which removes the last element that was added into the stack. It follows Last In First Out(LIFO) Order.
  - A stack overflow is an undesirable condition in which the program tries to use more memory space than the call stack has available. If a Stack is empty and yet a Pop operation is attempted, then it results in Stack Underflow condition.
  - Examples and Code:
    - [Stacks Using Arrays](Stacks_in_C/StacksUsingArrays.c/)
    - [Stacks Using Linked List](Stacks_in_C/StacksUsingLinkedList.c/)
    - [Infix To Postfix Expression Using Stacks](Stacks_in_C/InfixToPostfixUsingStacks.c/)
    - [Postfix Expression Evaluation Using Stacks](Stacks_in_C/PostfixEvaluationUsingStacks.c/)
    
 - [Queues in C](Queues_In_C/)
   - In computer science, a queue is a particular kind of abstract data type or collection in which the entities in the collection are kept in order and the principle (or only) operations on the collection are the addition of entities to the rear terminal position, known as enqueue, and removal of entities from the front terminal position, known as dequeue. This makes the queue a First-In-First-Out (FIFO) data structure. 
   - In a FIFO data structure, the first element added to the queue will be the first one to be removed. This is equivalent to the requirement that once a new element is added, all elements that were added before have to be removed before the new element can be removed.
   - Often a peek or front operation is also entered, returning the value of the front element without dequeuing it. A queue is an example of a linear data structure, or more abstractly a sequential collection.
   - Examples and Code:
     - [Direct and Circular Buffer Memory Allocation in Queues](Queues_In_C/NormalAndCircularBuffer_BasicOperations.c/)
     - [Doubly Ended Queues - Basic Operations](Queues_In_C/DoubleEndedQueue_BasicOperation.c/)
     - [Priority Queues Using Linked List - Basic Operations](Queues_In_C/PriorityQueuesUsingLinkedList_BasicOperations.c/)
