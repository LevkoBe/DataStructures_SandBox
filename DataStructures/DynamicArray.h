#pragma once
#include <vector>
#include <iostream>

template <typename T>
class DynamicArray
{
	T* dynamicArray = nullptr;
	size_t size = 0;
	size_t capacity = 1;
public:
	DynamicArray(int capacity = 1): capacity(capacity), dynamicArray(new T[capacity]) {
		for (int i = 0; i < capacity; i++) {
			dynamicArray[i] = T();
		}
	}

	DynamicArray(std::vector<T> arr) : size(arr.size()), capacity(size) {
		dynamicArray = new T[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = arr[i];
		}
	}

	DynamicArray(std::initializer_list<T> arr): size(arr.size()), capacity(size) {
		int i = 0;
		dynamicArray = new T[size];
		for (auto& value : arr) {
			dynamicArray[i++] = value;
		}
	}

	DynamicArray(T* arr, int size): size(size), dynamicArray(arr), capacity(size) {}

	DynamicArray(DynamicArray&& arr) noexcept: size(arr.size), capacity(arr.capacity), dynamicArray(arr.dynamicArray) {
		arr.size = 0;
		arr.capacity = 1;
		arr.dynamicArray = nullptr;
	}

	DynamicArray(const DynamicArray& arr): size(arr.size), capacity(arr.capacity) {
		dynamicArray = new T[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = arr.dynamicArray[i];
		}
	}


	// parameters
	const int getSize() const {
		return size;
	}

	const int getCapacity() const {
		return capacity;
	}


	// output
	friend std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
		for (int i = 0; i < arr.size; i++) {
			os << arr.dynamicArray[i] << " ";
		}
		os << std::endl;
		return os;
	}

	DynamicArray& operator=(const DynamicArray& arr) {
		if (this != &arr) {
			if (dynamicArray != nullptr)
				delete[] this->dynamicArray;
			this->size = arr.size;
			this->capacity = arr.capacity;
			this->dynamicArray = new T[capacity];
			for (int i = 0; i < size; i++) {
				this->dynamicArray[i] = arr.dynamicArray[i];
			}
		}
		return *this;
	}

	~DynamicArray() {
		delete[] dynamicArray;
	}
};

