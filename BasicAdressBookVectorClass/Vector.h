#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept> // For exception handling

template <typename T>
class Vector {
private:
    T* data;          // Pointer to the dynamically allocated array
    size_t capacity;  // Maximum number of elements the vector can hold
    size_t size;      // Current number of elements in the vector

    // Resize the vector when needed
    void resize(size_t newCapacity);

public:
    // Constructor and Destructor
    Vector();
    ~Vector();

    // Add a new element to the end
    void push_back(const T& value);

    // Access an element by index
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Get the current size of the vector
    size_t getSize() const;
};

// Constructor
template <typename T>
Vector<T>::Vector() : data(nullptr), capacity(0), size(0) {}

// Destructor
template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

// Resize the vector
template <typename T>
void Vector<T>::resize(size_t newCapacity) {
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Add a new element
template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

// Access element by index
template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Const version of access by index
template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Get the current size
template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

#endif
