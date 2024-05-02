#include "HashTable.h"
#include "WordEntry.h"

// for zybooks submission
// int main() { return 0; }

// constructor
HashTable::HashTable (int newsize) {
  size = newsize;
  hashTable = new list<WordEntry>[size];
}

// destructor because uses heap
HashTable::~HashTable() {
  // clear each list
  for (unsigned i = 0; i < size; ++i) {
    hashTable[i].clear();
  }
  delete[] hashTable; // deallocate array pointer
}

// returns an int based on input -> used for index into array in hash table
int HashTable::computeHash(const string& key) const {
  int value = 0;
  // combines ascii values of characters
  for (char ch : key) { value += static_cast<int>(ch); }
  return value % size;
}

// adds a new appearance to WordEntry if it already exists in hash table
// if it doesn't exist, makes a new entry and push it onto list
void HashTable::put(const string &input, int score) {
  // iterate through hashTable
  for (WordEntry& entry : hashTable[computeHash(input)]) {
    // if exists
    if (entry.getWord() == input) {
      entry.addNewAppearance(score);
      return;
    }
  }
  // doesn't exist
  hashTable[computeHash(input)].push_back(WordEntry(input, score));
}

// return average score of word, or 2.0 (neutral) if not found
double HashTable::getAverage(const string& key) const {
  // iterate through hash table
  for (WordEntry& entry : hashTable[computeHash(key)]) {
    if (entry.getWord() == key) { return entry.getAverage(); }
  }
  return 2.0; // if not found, return neutral result
}

// returns true if it exists in the hash table, else false
bool HashTable::contains(const string& key) const {
  if (size > 0) { // if hash table has elements
    // iterate through hash table
    for (const WordEntry& entry : hashTable[computeHash(key)]) {
      if (entry.getWord() == key) return true;
    }
  }
  return false;
}

