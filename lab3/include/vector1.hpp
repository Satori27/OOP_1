#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Vector()
        : data(nullptr), size(0), capacity(0) {}

// template<typename T>
    Vector(const std::initializer_list<T> &initList) : Vector() {

    T *newArray = reinterpret_cast<T *>(new char[initList.size() * sizeof(T)]);

    try {
        std::uninitialized_copy(initList.begin(), initList.end(), newArray);
    } catch (...) {
        delete[] reinterpret_cast<char *>(newArray);
        throw;
    }

    delete[] reinterpret_cast<char *>(this->data);
    this->data = newArray;
    this->size = initList.size();
    this->capacity = this->size;
}

    explicit Vector(size_t initialCapacity)
        : data(new T[initialCapacity]), size(0), capacity(initialCapacity) {}

    Vector(const Vector& other)
        : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.capacity];
            size = other.size;
            capacity = other.capacity;
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& element) {
        if (size >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = element;
        size++;
    }

    size_t getSize() const {
        return size;
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& operator[](size_t index) {
        return const_cast<T&>(static_cast<const Vector&>(*this)[index]);
    }
};

#endif