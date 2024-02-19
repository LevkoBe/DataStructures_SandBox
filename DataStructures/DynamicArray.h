#pragma once
#include <vector>
#include <iostream>

template <typename T>
class DynamicArray
{
	T* dynamicArray = nullptr;
	int size = 0;
	int capacity = 1;
public:
	DynamicArray(int capacity = 1): capacity(capacity), dynamicArray(new T[capacity]) {
		for (int i = 0; i < capacity; i++) {
			dynamicArray[i] = T();
		}
	}

	DynamicArray(std::vector<T> array) : size(array.size()), capacity(size) {
		dynamicArray = new T[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = array[i];
		}
	}

	DynamicArray(std::initializer_list<T> array): size(array.size()), capacity(size) {
		int i = 0;
		dynamicArray = new T[size];
		for (auto& value : array) {
			dynamicArray[i++] = value;
		}
	}

	DynamicArray(T* array, int size): size(size), dynamicArray(array), capacity(size) {}

	DynamicArray(DynamicArray&& array) noexcept: size(array.getSize()), capacity(array.getCapacity()), dynamicArray(array.dynamicArray) {
		array.size = 0;
		array.capacity = 1;
		array.dynamicArray = nullptr;
	}

	DynamicArray(const DynamicArray& array): size(array.getSize()), capacity(array.getCapacity()) {
		dynamicArray = new T[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = array.dynamicArray[i];
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
	void print() const {
		for (int i = 0; i < size; i++) {
			std::cout << dynamicArray[i] << " ";
		}
		std::cout << std::endl;
	}

	//friend std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& array) {
	//	for (int i = 0; i < array.getSize(); i++) {
	//		os << array[i] << " ";
	//	}
	//	return os;
	//}


	~DynamicArray() {
		delete[] dynamicArray;
	}
};

