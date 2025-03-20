#ifndef hash_h
#define hash_h


#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

struct node{
            string text; 
            node* next;

            node(string new_text){
                text = new_text;
                next = nullptr;
            }
};

class HashTable {
    public:
        int table_size;
        int words_number;
        node** hash_table;

        HashTable(int slot, int num);
        ~HashTable();
        int hash_function(string text);
        void print_table();
        void print_slot_lengths();
        void hash_table_insert(string* str);
        void print_standard_deviation();
        int slot_length(int index);
        node* hash_table_lookup (string text);
        node* hash_table_delete (string str);

    private:
};

#endif