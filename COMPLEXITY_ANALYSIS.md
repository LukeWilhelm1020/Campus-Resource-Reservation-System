---Complexity Analysis---
Reservation Insertion: stored in a link list; a new reservation 
is inserted at the front so no traversal is required. O(1)

Reservation Removal: linked list needs to be traversed to find a 
reservation with a requested identity. O(n)

Reservation Search: requires traversing the linked list until the matching ID is found 
of the list limit is reached. O(n)

---Waiting List---
Enqueue: reassigning pointers in a queue. O(1)

Dequeue: reassigning pointers. O(1)

Waiting List Processing: When theres availability, the next student in line is assigned. O(1)

---Cancellation History---
Cancellation History: cancelled reserve is placed on top of the stack. O(1)

Undo Cancellation: Most recent reservation cancelled is moved from the top of the stack 
and put back in the reservation list. O(1)

---Resource Management---
Resource Search: stored in a vector, searching requires checking all sources. O(n)

Resource Sorting: Uses a bubble-sort approach, meaning the worst case scenario, every resource
may be compared. O(n^2)

Resource Loading: Every resource in the input file is read and added to the vector. O(n)

---Summary---
Linked List: Reservation insertion O(1) Reservation removal O(n) Reservation search O(n)
Queue: Waiting-list enqueue O(1) Waiting-list dequeue O(1) Waiting-list processing O(1)
Stack: Cancellation push O(1) Undo Cancellation O(1) 
Vector: Resource search O(n) Resource sorting O(n^2) Resource loading O(n)
