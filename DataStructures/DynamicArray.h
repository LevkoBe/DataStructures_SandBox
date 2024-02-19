#pragma once
#include <vector>
#include <iostream>

class DynamicArray
{
	int* dynamicArray = nullptr;
	int size = 0;
	int capacity = 1;
public:
	DynamicArray(int capacity = 1): capacity(capacity), dynamicArray(new int[capacity]) {};
	// todo: use template
	// todo: check if capacity is being initialized properly
	DynamicArray(std::vector<int> array) : size(array.size()), capacity(size) {
		dynamicArray = new int[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = array[i];
		}
	}

	DynamicArray(std::initializer_list<int> array): size(sizeof(array) / sizeof(int)), capacity(array.size()) {
		int i = 0;
		dynamicArray = new int[size];
		for (auto& value : array) {
			dynamicArray[i++] = value;
		}
	}

	DynamicArray(int* array, int size): size(size), dynamicArray(array), capacity(size) {};

	DynamicArray(DynamicArray&& array) noexcept: size(array.getSize()), capacity(array.getCapacity()), dynamicArray(array.dynamicArray) {
		array.size = 0;
		array.capacity = 1;
		array.dynamicArray = nullptr;
	}

	DynamicArray(const DynamicArray& array): size(array.getSize()), capacity(array.getCapacity()) {
		dynamicArray = new int[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = array.dynamicArray[i];
		}
	}

	const int getSize() const {
		return size;
	}

	const int getCapacity() const {
		return capacity;
	}

	void print() const {
		for (int i = 0; i < size; i++) {
			//std::cout << dynamicArray + i << " ";
			std::cout << dynamicArray[i] << " ";
		}
		std::cout << std::endl;
	}
};

