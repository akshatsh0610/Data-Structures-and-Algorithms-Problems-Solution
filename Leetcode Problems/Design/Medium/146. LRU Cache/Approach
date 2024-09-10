Problem Statement-:

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the 
capacity from this operation, evict the least recently used key.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Problem Constraints -:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

Topic Tags -: Hash Table, Linked List, Design, Doubly-Linked List

Approach -:

So according to the problem we need to build a data structure that works on the principle of LRU Cache.
An LRU cache is a data structure used to store a limited number of items, typically with the goal of providing fast access to frequently accessed data.
The key to understanding how an LRU cache operates lies in its underlying data structure. While various implementations are possible, one common approach is to 
combine a doubly linked list with a hashmap. Here’s a high-level overview of how it works:
Doubly Linked List: This structure keeps track of the items in the cache in the order they were accessed, with the most recently used item at the front and the 
least recently used item at the back.
Hashmap: Each item in the cache is associated with a key-value pair. The hashmap provides fast access to items based on their keys, allowing constant-time 
retrieval and update operations.
When an item is accessed in the cache, it’s moved to the front of the linked list to signify that it’s the most recently used. If the cache is full and a new 
item needs to be added, the item at the end of the list (i.e., the least recently used item) is removed to accommodate the new entry.

The approach to implement LRU is very simple we are going to use a Doubly Linked List and a Hash table. The linked list is used here so that we can easily remove 
the least recently used data and easily add the new data to the memory and most frequent data to the front of linked list. And hash table is used here to store 
the key value pair and with the help of this we can easily access the data.

The Node represents the single node of a doubly linked list. You will know later why we have taken key in our node.
We have created a hash table that contains key -> {data,Node} . We have also created a head pointer pointing to the front and the tail pointer points to the end. 
We have created these pointers so that we don’t have to traverse the complete linked list.
In the constructor function we have pointed head and tail to dummy nodes for easy manipulation of list.
The insert() function will insert the new data entry at the front of the list besides front dummy node.
The remove() function is going to the remove the least frequently used data.
The get() method will take the key of data and returns the data corresponding to that key. Here if the key is present then we will remove it from that place and insert
it at the front of the list this is how it will become most frequently used data.
The put() method is used to insert the data into the list. If the cache is not filled completely then we can simply insert the data, otherwise we need to remove the 
lru and then insert the data. Also if the key is already present in hashtable then we will simply update the key and re-insert it in list.
So this was the implementation of LRU Cache. We can also implement it using deque.
