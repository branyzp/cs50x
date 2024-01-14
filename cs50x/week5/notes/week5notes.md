# Data Structures

## Node
`typedef struct node{
    string phrase;
    struct node *next;
}`

- we can store phrases such as 'Hi' or 'Bye' as string phrase inside the node
- the node *next is what links the current node to the next node, using a pointer address expressed in hexadecimal that will lead this node to the next node

building a linked list
1. define list as pointer to a node, the starting node, as NULL (as we don't have a linked list yet) so it'll look like this: list->
2. allocate memory for the starting node `node *n = malloc(sizeof(node));` so that n will exist
3. call the phrase attribute of n to set it to 'Hi' `n->phrase = "Hi";` so that the phrase inside our start node n is now "Hi"
4. set the chain by setting next to null `n->next = NULL;` so that the next node from our start node is null
5. set list to equal n `list = n;`w to have list point to the start node
6. set a new node and allocate memory for it `n = malloc(sizeof(node));` so we have a new node
7. set the phrase attribute of the node n to "Hey" `n->phrase = "Hey!"`
8. set the next node of n to list `n->next = list;` so that the start node now becomes n, and the previous start node becomes the second linked node
9. free memory using temporary pointer `node *ptr = list->next;` so that when we free list using `free(list)`, we will have *ptr to reference the other node
10. now, set `list = ptr;` to reference the other node then set `ptr = list->next;` to ensure that there is always a pointer reference for the next node
11. `free(list);` then `list = ptr` when finally list = NULL then you are done

### we can use valgrind to check for memory leaks in the program, always remember to free malloc'd memory entirely to prevent memory leaks.

## Hash Table

- a hash table is basically an array of linked lists
- for example, an array of alphabets that, for each alphabet it is a linked list of names

hash function will process the phrase and output an index of the bucket that the value should be stored under

- a good hash function always gives you the same value for the same input
- produces an even distribution across buckets
- uses all buckets


