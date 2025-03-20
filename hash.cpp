#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"

using namespace std;

HashTable::HashTable(int slot, int num){
    table_size = slot;
    words_number = num;
    hash_table = new node*[table_size];
    for (int i = 0; i < table_size; i++){
        hash_table[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for (int i = 0; i < table_size; i++){
        node* tmp = hash_table[i];
        while (tmp != NULL){
            node* next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }
    delete[] hash_table;
}

int HashTable::hash_function(string text) {
    // Implement your own hash function here
    if (table_size == 0) return 0;
    int hash_value = 0;
    for (char c : text) {
        hash_value += static_cast<int>(c);
        hash_value = (hash_value * 17 * static_cast<int>(c)) % table_size;
    }
    return hash_value;
}

void HashTable::print_table(){
    int i = 0;
    while (i < 5){
        if (hash_table[i] == NULL) {
            cout << "Slot " << i << ": " << endl;
        } else
        {
            cout << "Slot " << i << ": ";
            node* tmp = hash_table[i];
            while (tmp != NULL) {
                cout << tmp->text << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
        i++;
    }
}

void HashTable::print_slot_lengths(){
    int i = 0;
    while (i < table_size){
        int n = slot_length(i);
        cout << "Slot " << i << ": " << n << endl;
        i++;
    }
}

void HashTable::hash_table_insert(string* str){
    for (int index = 0; index < words_number; index++){
        node* word = new node(str[index]);
        if (word != NULL){
            int i = hash_function(word->text);
            word->next = hash_table[i];
            hash_table[i] = word;
        }
    }

}

void HashTable::print_standard_deviation(){
    // get mean

    if (table_size == 0) {
        return;
    }
    
    double mean = (double)words_number / (double)table_size;

    double deviation = 0;
    double n = 0.0;
    for (int i = 0; i < table_size; i++){
        n = (double)slot_length(i);
        deviation += pow(n - mean, 2);
    }
    deviation = sqrt(deviation / (double)table_size);
    cout << deviation << endl;
}

// get lengths of each slot for printing and standard deviation
int HashTable::slot_length(int index){
    int n = 0;
    if (hash_table[index] == NULL) {
        return 0;
    } else
    {
        node* tmp = hash_table[index];
        while (tmp != NULL) {
            n++;
            tmp = tmp->next;
        }
        return n;
    }
}
