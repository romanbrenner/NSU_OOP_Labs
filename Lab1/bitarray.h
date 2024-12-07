#pragma once

#include <iostream>
#include <vector>
#include <string>

// BitArray class represents a dynamic array of bits and provides various bitwise operations and utilities
class BitArray {
private:
  std::vector<bool> bits; // Internal storage for bits using vector

public:
  // Constructors and Destructor
  // Default constructor: Initializes an empty bit array
  BitArray() = default;

  // Destructor: Automatically frees memory allocated for the bits vector
  ~BitArray() = default;

  // Parameterized constructor: Initializes a bit array with a given number of bits and an optional initial value
  // If no value is provided, all bits are initialized to 0.
  explicit BitArray(int num_bits, unsigned long value = 0);

  // Copy constructor: Creates a new BitArray as a copy of an existing one
  BitArray(const BitArray& b);

  // Swap method: Exchanges the contents of this BitArray with another
  void swap(BitArray& b);

  // Assignment operator: Copies the contents of one BitArray to another
  BitArray& operator=(const BitArray& b);

  // Resizing methods:
  // Resizes the array to the given number of bits and sets all bits to a specified value (default: false)
  void resize(int num_bits, bool value = false);

  // Clears the bit array, removing all bits
  void clear();

  // Adds a new bit to the end of the bit array
  void push_back(bool bit);

  // Bitwise operators:
  // Performs a bitwise AND with another BitArray and assigns the result to this object
  BitArray& operator&=(const BitArray& b);

  // Performs a bitwise OR with another BitArray and assigns the result to this object
  BitArray& operator|=(const BitArray& b);

  // Performs a bitwise XOR with another BitArray and assigns the result to this object
  BitArray& operator^=(const BitArray& b);

  // Bit shifting operations:
  // Shifts the bits to the left by n positions and assigns the result to this object
  BitArray& operator<<=(int n);

  // Shifts the bits to the right by n positions and assigns the result to this object
  BitArray& operator>>=(int n);

  // Left shift operator: Returns a new BitArray where the bits are shifted left by n positions
  BitArray operator<<(int n) const;

  // Right shift operator: Returns a new BitArray where the bits are shifted right by n positions
  BitArray operator>>(int n) const;

  // Set and reset methods:
  // Sets the bit at the nth position to a specified value (default: true)
  BitArray& set(int n, bool val = true);

  // Sets all bits to true
  BitArray& set();

  // Resets (sets to false) the bit at the nth position
  BitArray& reset(int n);

  // Resets all bits to false
  BitArray& reset();

  // Checks whether any bit is set to true
  bool any() const;

  // Checks whether none of the bits are set to true
  bool none() const;

  // Bitwise NOT operator: Returns a new BitArray where all bits are inverted
  BitArray operator~() const;

  // Counts the number of set bits (bits that are true)
  int count() const;

  // Access operator: Allows reading a bit at index i (returns false if out of bounds)
  bool operator[](int i) const;

  // Methods for size and empty check:
  // Returns the number of bits in the array
  int size() const;

  // Returns true if the array is empty (contains no bits)
  bool empty() const;

  // Returns a string representation of the bit array
  std::string to_string() const;
};

// Non-member operators for bitwise operations:

// Equality operator: Returns true if two BitArray objects are equal
bool operator==(const BitArray & a, const BitArray & b);

// Inequality operator: Returns true if two BitArray objects are not equal
bool operator!=(const BitArray & a, const BitArray & b);

// Bitwise AND operator: Returns a new BitArray where the bits are ANDed between two arrays
BitArray operator&(const BitArray& b1, const BitArray& b2);

// Bitwise OR operator: Returns a new BitArray where the bits are ORed between two arrays
BitArray operator|(const BitArray& b1, const BitArray& b2);

// Bitwise XOR operator: Returns a new BitArray where the bits are XORed between two arrays
BitArray operator^(const BitArray& b1, const BitArray& b2);
