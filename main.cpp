/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Aivar Zhubandykov
Your team alias: Yerdaulet Dauletkali
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    HashTable hashtable(k, n);
    hashtable.hash_table_insert(texts);

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    hashtable.print_table();

    cout << "==== Printing the slot lengths ====" << endl;
    hashtable.print_slot_lengths();

    cout << "==== Printing the standard deviation =====" << endl;
    hashtable.print_standard_deviation();

    return 0;
}