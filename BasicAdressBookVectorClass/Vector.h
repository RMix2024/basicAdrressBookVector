#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept> // For exception handling
#include <cstdlib>   // For size_t

// Template class for a dynamic array


template <typename T>
class Vector {
private:
    T* data;          // Pointer to the dynamically allocated array
    size_t capacity;  // Maximum number of elements the vector can hold
    size_t size;      // Current number of elements in the vector

    // Private method to resize the vector
    void resize(size_t newCapacity);

public:
    // Constructor
    Vector();

    // Destructor
    ~Vector();

    // Add an element to the end of the vector
    void push_back(const T& value);

    // Remove the last element from the vector
    void pop_back();

    // Access an element by index
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Get the current size of the vector
    size_t getSize() const;

    // Get the current capacity of the vector
    size_t getCapacity() const;

    // Check if the vector is empty
    bool isEmpty() const;
};

// Implementation of the template functions
template <typename T>
Vector<T>::Vector() : data(nullptr), capacity(0), size(0) {}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

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

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size == 0) {
        throw std::out_of_range("Cannot pop_back from an empty vector");
    }
    --size;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

template <typename T>
size_t Vector<T>::getCapacity() const {
    return capacity;
}

template <typename T>
bool Vector<T>::isEmpty() const {
    return size == 0;
}

#endif
