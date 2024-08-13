#define MAX_SIZE 100000  // Assuming the maximum size of the array

typedef struct {
    int key;
    int value;
} HashItem;

// A simple hash function
int hash(int key) {
    return (key + MAX_SIZE) % MAX_SIZE;
}

// Insert a key-value pair into the hash table
void insert(HashItem* hashTable, int key, int value) {
    int index = hash(key);
    while (hashTable[index].key != 0 || hashTable[index].value != 0) {
        index = hash(index + 1);
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
}

// Find a value by key in the hash table
int find(HashItem* hashTable, int key) {
    int index = hash(key);
    while (hashTable[index].key != 0 || hashTable[index].value != 0) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = hash(index + 1);
    }
    return -1;  // Return -1 if not found
}

int findMaxLength(int* nums, int numsSize) {
    HashItem hashTable[MAX_SIZE] = {0};  // Initialize hash table
    int maxLen = 0, sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += (nums[i] == 0) ? -1 : 1;

        if (sum == 0) {
            maxLen = i + 1;
        } else {
            int prevIndex = find(hashTable, sum);
            if (prevIndex != -1) {
                maxLen = (i - prevIndex > maxLen) ? i - prevIndex : maxLen;
            } else {
                insert(hashTable, sum, i);
            }
        }
    }

    return maxLen;
    
}