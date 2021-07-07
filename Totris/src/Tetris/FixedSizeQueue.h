#pragma once
#include <stdexcept>

template<typename T>
class FixedSizeQueue {
	unsigned int capacity;
	unsigned int size;
	T* data;
	void copyVars(const FixedSizeQueue& other);
	void resize(unsigned int newCapacity);
public:
	FixedSizeQueue();
	FixedSizeQueue(unsigned int capacity_);
	FixedSizeQueue(const FixedSizeQueue& other);
	FixedSizeQueue& operator=(const FixedSizeQueue& rhs);
	~FixedSizeQueue();
	void enqueue(T inputData);
	T dequeue();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
	bool isFull();
	bool isEmpty();
	T operator[](unsigned int index);
};

template<typename T>
FixedSizeQueue<T>::FixedSizeQueue() {
	capacity = 1;
	size = 0;
	data = new T[capacity];
}

template<typename T>
FixedSizeQueue<T>::FixedSizeQueue(unsigned int capacity_) {
	capacity = capacity_;
	size = 0;
	data = new T[capacity];
}

template<typename T>
void FixedSizeQueue<T>::copyVars(const FixedSizeQueue& other) {
	capacity = other.capacity;
	size = other.size;
	delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}

template<typename T>
FixedSizeQueue<T>::FixedSizeQueue(const FixedSizeQueue& other) {
	copyVars(other);
}

template<typename T>
FixedSizeQueue<T>& FixedSizeQueue<T>::operator=(const FixedSizeQueue& rhs) {
	copyVars(rhs);
	return *this;
}

template<typename T>
FixedSizeQueue<T>::~FixedSizeQueue() {
	delete[] data;
}

template<typename T>
void FixedSizeQueue<T>::enqueue(T inputData) {
	if (size == capacity) {
		throw std::runtime_error("Error: Cannot enqueue. Queue is full");
	}
	data[size] = inputData;
	size++;
}

template<typename T>
void FixedSizeQueue<T>::resize(unsigned int newCapacity) {
	T* tempArray = new T[newCapacity];
	unsigned int minSize = newCapacity;
	if (size < minSize)
		minSize = size;
	for (unsigned int i = 0; i < minSize; i++)
		tempArray[i] = data[i];
	delete[] data;
	data = tempArray;
	capacity = newCapacity;
}

template<typename T>
T FixedSizeQueue<T>::dequeue() {
	T toReturn;
	if (size == 0) {
		throw std::runtime_error("Error: Cannot pop of queue. Queue is empty.");
	}
	else {
		toReturn = data[0];
		size--;
		for (unsigned int i = 0; i < size; i++)
			data[i] = data[i + 1];
	}
	return toReturn;
}

template<typename T>
T FixedSizeQueue<T>::peek() {
	if (size == 0)
		throw std::runtime_error("Error: Cannot peek of queue. Queue is empty.");
	return data[0];
}

template<typename T>
unsigned int FixedSizeQueue<T>::getSize() {
	return size;
}

template<typename T>
unsigned int FixedSizeQueue<T>::getMaxCapacity() {
	return capacity;
}

template<typename T>
T* FixedSizeQueue<T>::getData() {
	return data;
}

template<typename T>
bool FixedSizeQueue<T>::isFull() {
	return size == capacity;
}

template<typename T>
bool FixedSizeQueue<T>::isEmpty() {
	return size == 0;
}

template<typename T>
T FixedSizeQueue<T>::operator[](unsigned int index) {
	if (index >= size)
		throw std::runtime_error("Error: Index out of bounds");
	return data[index];
}