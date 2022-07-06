#pragma once
// Node
template <typename T>
struct Node
{
	T data;
	Node<T>* next = nullptr;
	Node<T>* previous = nullptr;
};

// My Doubly Linked List for Stack
template <typename T>
class DoublyLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	~DoublyLinkedList(void);

	void AddToHead(T data);
	void AddToTail(T data);
	void DeleteFromHead();
	void DeleteFromTail();
	T GetDataByIndex(int index);
	void SetDataByIndex(T newData, int index);

	void Print() const;
	void Clear();
};

template<typename T>
class Stack
{
private:
	DoublyLinkedList<T> dll;
	int index = 0;
	int size;

public:
	Stack(int size);
	Stack();

	bool isEmpty();
	bool isFull();

	void Push(T data);
	T Pop();
	T Peek();

	int getIndex();
};
