# audio_platform_storage_and_testing
Create a software for an audio streaming platform capable of loading countless audio tracks into a library, to search songs by the artist’s name and to remove certain songs from the library. 

Data Structure : Doubly Linked List

## Description
This project aims to create a software for an audio streaming platform capable of loading countless audio tracks into a library, to search songs by the artist’s name and to remove certain songs from the library. For the software to work fast and manage potentially billions of tracks, the data structure chosen to store the tracks must be appropriate. The algorithm that performs the search on the library needs to be rapid enough to search specific tracks in the smallest possible time. 


## Design
### Data Structures and Algorithms
Each music track contains the following attributes: title, artist, and duration. Figure1 shows the class design for this.
Since the music platform will contain an unpredictable and therefore potentially millions of music tracks, with dictionary operations: Insert, Search and Delete; it is best to choose a data structure that can perform the operations in the fastest way possible while navigating millions of data.

For this music platform, hash table was used as the data structure. This is because hash tables are implemented with simple arrays but use direct addressing to determine the index position of where the data should be stored at.   

The index is calculated using a hash function where a key is given the function outputs the index on the array to store the data. Hash tables often uses an array proportional to the number of keys available so most hash function calculation are based on the array as so not to create keys out of bounds or arrays with too many empty positions. This satisfies the condition of simple uniform hashing. (Cormen et al., 2009) 

Therefore, under these conditions, the average time to search for an element, given the key, is **O(1)**.

The idea is to have a hash table T be an array that has a size of s therefore the array can store in the slots T[0… s-1]. Each element stored in T has a key k that will be passed into a hash function h which returns h(k) as the index for the element. (Cormen et al., 2009)

However, there is still a chance that two keys will end up having the same slot and can be resolved by chaining with linked lists. This is mostly likely to happen when the key used to calculate the index is a number that can repeat multiple times throughout all elements. In our case, using the “duration” attribute of the Track class can lead to multiple collisions.

Assuming that most tracks are between 90 seconds and 300 seconds; the probability that numbers in the range **[90, 300]** will repeat increase with the amount of tracks added and the platform should deal with millions of tracks. But more importantly, even when trying to chain the tracks together in a linked list, the data storage will not make sense since the chained tracks in one index of the hash table T are not related to each other, searching and delete more difficult and take too much time since each slot in the hash table now has a list. Moreover, the user of the program should be able to delete all tracks by a certain artist and/or a specific track.
Since the hash function for this program is based on the Division Method (modulus), it remains static for all keys used. In this project, the track artist is used as the key where the hash function calculates the index based on the ASCII values of the numbers modulo the capacity of the hash table. This ensures that the keys are uniformly distributed across the range of available keys. 

This also makes deletion and searching easier as a single slot of the hash table will contain a list all tracks by the same artist. 

**Doubly Linked List** performs better than a Singly Linked List in this case as it takes less time to do these operations however a node can take up double the size used by a singly linked list which can be a downside if the number of stored tracks reach the billions and beyond (javaTpoint). However, due to its constant time lookup, it is more efficient for this project to use.


### Analysis

<img width="509" height="406" alt="image" src="https://github.com/user-attachments/assets/b777d31d-63f5-4500-b71d-9ef25a016b8f" />

<img width="388" height="221" alt="image" src="https://github.com/user-attachments/assets/55aef69c-15e6-4500-9801-f346676a9d94" />

Each Node of the Doubly Linked List has 2 pointer variables to other Nodes and each variable is 4 bytes in size (javaTpoint). 

Insertion and Deletion, the time-complexity is **O(1)**. 

Insertion is simply updating the pointers and adding the new Node at the end of the list.

Deletion is also constant as it is already known where the element is within the list. Both pointer prev and next play into determining the Node to be deleted.

Both insertion and deletion has space complexity O(1) as neither take space for the operation.

Searching a Doubly Linked List however takes **O(n)** in average case and worst-case as the entire list needs to traversed in both cases. 

INSERT NODE

<img width="522" height="688" alt="image" src="https://github.com/user-attachments/assets/2e9fc35b-28ce-4b91-9dd4-02edea33d3a3" />


DELETE NODE

<img width="488" height="489" alt="image" src="https://github.com/user-attachments/assets/4a69a4d4-4b6a-46dc-82df-de5057939f5f" />


SEARCH NODE

<img width="507" height="415" alt="image" src="https://github.com/user-attachments/assets/86235337-9206-4d7f-9e0d-5361694c3498" />


HASH MAP 

<img width="774" height="584" alt="image" src="https://github.com/user-attachments/assets/6bda93b6-19da-4801-ac95-608654d3617d" />

<img width="696" height="116" alt="image" src="https://github.com/user-attachments/assets/0640d0a2-45ff-4afa-82fd-7649c1f11ca4" />


Figures above shows the hash function used to calculate the index. 

Each For Loop takes O(n) to complete where n is the size of the string passed into the function.
The Division Method is used in the hash function to calculate the index from the keys. Each character’s ASCII value is multiplied by a prime number then modulo the capacity of the hash table. This value is added to the sum again.

REHASHING

<img width="632" height="590" alt="image" src="https://github.com/user-attachments/assets/56b55be7-8ea2-46a4-9a8e-c47ced0f7aac" />


INSERTION

<img width="600" height="400" alt="image" src="https://github.com/user-attachments/assets/8187f89b-650f-40da-a1cb-82bed051dd03" />


SEARCHING INTO A HASH TABLE

<img width="564" height="302" alt="image" src="https://github.com/user-attachments/assets/865e45b7-f603-4ae9-ae1f-8a29273d45ef" />

Figure above shows rehashing of the hash table when the load factor exceeds 0.75
When rehashing is called in insert function in Figure 9, it can take about O(n) in time and also O(n) in space to use the space to temporarily store the old hash table. 

For best case insertion in hash table without rehashing will only take O(1) time and O(1) in space. 

But overall insertion will also depend on the performance of the linked list and since that can take O(n) in average, Inserting into hash table can take **O(n<sup>2</sup>)** worst-case and **O(n)** in average.


DELETE ELEMENT FROM HASH TABLE

<img width="550" height="273" alt="image" src="https://github.com/user-attachments/assets/eebdf9de-f35b-4aeb-9341-52f4c54a41d3" />


## Testing

### Approach
Using Catch2 test to do Test-Driven Development on the different functionalities of the program.
Each test is done using TEST_CASE and SECTIONs to test the different reactions of the program using various input data.


## Conclusion

### Summary

This project is used on a music platform that deals with millions of Track objects and require the operations: INSERT, DELETE and SEARCH. In order to process these operations in a fast way, hashing table was used with collision handling by chaining doubly linked lists. The hash table can take O(1) to do the operations thanks to the usage of direct addressing by calculating the index of an element through a hash function. The artist in a track is used to calculate the key and all titles with the same artist will be chained in a doubly linked list so that all tracks can be displayed by accessing just one slot in the hash table.
The hash table in this case is resizable as to accommodate for the unpredictable number of tracks that can be added from files. The worst performing operation is the INSERT operation which can be O(n2) in worst-case since there is reordering of the hash table where it could be required.

### Limitations and Reflection

Although the artist of a track object is a string used as the key to calculate the index using the ASCII values of each individual modulo the capacity of the hash table therefore it has a much better chance to avoid worst-case behaviour rather than using a number based-key, artist keys can still collide to get the same index but will be rarer. 
This can be solved by using Universal Hashing Function to create a set of hash functions. The hash function chosen for a key will therefore be random and independent of the available set of keys. (Cormen et al., 2009)

### Future Approach on similar task

For similar task in the future, it would be better to test other types of data structures like trees and compare the time it takes for the data structures to handle the elements.
By using the hash table method as well, creating a Universal Hash Function will decrease the likelihood of collisions. 

## References

- Cormen, T.H. et al. (2009) Introduction to algorithms. 3rd edn. Cambridge, Massachusetts: Massachusetts Institute of Technology.
  
- Singly linked list vs doubly linked list: What's the difference? - javatpoint (no date) www.javatpoint.com. Available at: https://www.javatpoint.com/singly-linked-list-vs-doubly-linked-list#:~:text=In%20a%20doubly%2Dlinked%20list%2C%20the%20time%20complexity%20for%20inserting,element%20is%20O(1). (Accessed: March 13, 2023).












