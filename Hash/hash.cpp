#include <iostream>
#include <vector>
using namespace std;

class DoubleHashingHashTable {
private:
    vector<int> table;
    int size;
    int prime;

    int hash_function_1(int key) const {
        return key % size;
    }

    int hash_function_2(int key) const {
        return prime - (key % prime);
    }

public:
    DoubleHashingHashTable(int table_size, int prime_number) : size(table_size), prime(prime_number) {
        table.resize(size, -1); // Initialize table with -1 (indicating empty)
    }

    void insert(int key) {
        int index = hash_function_1(key);

        if (table[index] == -1) {
            table[index] = key;
        } else {
            int step = hash_function_2(key);
            int original_index = index;

            // Probe until an empty slot (-1) or the same key is found
            while (table[index] != -1 && table[index] != key) {
                index = (index + step) % size;

                // Stop if we have looped back to the original index
                if (index == original_index) {
                    return; // Table is full, cannot insert
                }
            }

            // If we found an empty slot, insert the key
            if (table[index] == -1) {
                table[index] = key;
            }
        }
    }

    void print_table() const {
        cout << "Hash Index\tKey" << endl;
        for (int i = 0; i < size; ++i) {
            cout << i << "\t\t";
            if (table[i] == -1) {
                cout << "-" << endl;
            } else {
                cout << table[i] << endl;
            }
        }
    }
};

int main() {
    // Example usage:
    int table_size = 11;
    int prime_number = 7;

    DoubleHashingHashTable hash_table(table_size, prime_number);

    // Keys to insert
    vector<int> keys = {112, 125, 15, 82, 124, 145, 188, 178, 125, 58, 57};

    // Insert keys into the hash table
    for (int key : keys) {
        hash_table.insert(key);
    }

    // Print the hash table
    hash_table.print_table();

    return 0;
}
