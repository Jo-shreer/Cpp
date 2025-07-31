/*
LRU Cache Implementation Approach
Use an unordered_map (hash map) to map keys to nodes for O(1) lookup.

Use a doubly linked list to store the usage order:
Front = most recently used
Back = least recently used
On get(key):
If key exists, move the corresponding node to the front (marking it most recently used).
On put(key, value):
If key exists, update value and move node to front.
Else, insert new node at front.
If capacity exceeded, remove node from the back (least recently used).

*/
