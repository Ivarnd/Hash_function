Hash Function Project

Functionality of the program:

Program executes in main.cpp
main.cpp:
We create a hashtable with number of slots and number of tokens as parameters.
Then we insert all of the string values from the input texts.
Then we call print_table function to print the contents of the first 5 slots, 
print_slot_lengths function to print the slot lengths, 
print_standard_deviation function to print the standard deviation.

hash.h:
We create node struct (linked list for chaining hash table) and HashTable class, where we create properties of the HashTable (attributes and methods). 

hash.cpp:
We assign functions to the HashTable methods that were created in hash.h.
We create a simple constructor and destructor. 
Then we create a hash function itself. It gets an ascii code of characters in a string, sums them together and multiplies it by itself and 17 (prime number). Then it gets reminder from division of itself and table_size. Ideally this hash function should evenly distribute the keys without collisions, and it does fairly well on input files, except one.
We create a print_table function where we just print output of first 5 slots.  
Then we have a slot_length function where we just get the number of tokens in each slot. 
We have a print_slot_lengths function where we just print the lengths of each slot in hash table.
We have a print_standard_deviation function where we just calculate the standard deviation of hash table and print it.
We also have a hash_table_insert function where we get a pointer to an array as parameter, and insert all values of an array to the hash table. We do it this way because we know that tokens from file are collected in texts array.
