#include <iostream>
#include "header.h"
using namespace std;


template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(void)
{
	Clear();
}
template <typename T>
void DoublyLinkedList<T>::AddToHead(T data)
{
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->next = head;
	if (head)
		head->previous = temp;
	else
		tail = temp;
	head = temp;
	count++;
}
template <typename T>
void DoublyLinkedList<T>::AddToTail(T data)
{
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->previous = tail;
	if (tail)
		tail->next = temp;
	else
		head = temp;
	tail = temp;
	count++;
}
template <typename T>
void DoublyLinkedList<T>::DeleteFromHead()
{
	if (head)
	{
		Node<T>* temp = head->next;
		if (head == tail)
			tail = temp;
		delete head;
		head = temp;
		count--;
	}
}
template <typename T>
void DoublyLinkedList<T>::DeleteFromTail()
{
	if (tail)
	{
		Node<T>* temp = tail->previous;
		if (head == tail)
			head = temp;
		delete tail;
		tail = temp;
		count--;
	}
}
template <typename T>
T DoublyLinkedList<T>::GetDataByIndex(int index)
{

	Node<T>* temp;
	if (index <= count / 2)
	{
		temp = head;
		for (int i = 0; i != index; i++)
			temp = temp->next;
	}
	else
	{
		temp = tail;
		for (int i = count-1; i != index; i--)
			temp = temp->previous;
	}
	return temp->data;
}
template <typename T>
void DoublyLinkedList<T>::SetDataByIndex(T newData, int index)
{
	Node<T>* temp;
	if (index <= count / 2)
	{
		temp = head;
		for (int i = 0; i != index; i++)
			temp = temp->next;
	}
	else
	{
		temp = tail;
		for (int i = count - 1; i != index; i--)
			temp = temp->previous;
	}
	temp->data = newData;
}
template <typename T>
void DoublyLinkedList<T>::Print() const
{
	Node<T>* temp = head;
	for (int i = 0; i < count; i++, temp = temp->next)
		cout << temp->data << " ";
	cout << endl;
}
template <typename T>
void DoublyLinkedList<T>::Clear()
{
	Node<T>* temp = head;
	while (temp->next)
	{
		temp = temp->next;
		delete temp->previous;
	}
	delete tail;
	head = tail = nullptr;
	count = 0;
}


template <typename T>
Stack<T>::Stack(int size)
	: size{ size }
{
	T t{};
	for (int i = 0; i < size; i++)
		dll.AddToTail(t);
}
template <typename T>
Stack<T>::Stack()
	: Stack(10) {}

template <typename T>
bool Stack<T>::isEmpty()
{
	return index == 0;
}
template <typename T>
bool Stack<T>::isFull()
{
	return index == size - 1;
}

template <typename T>
void Stack<T>::Push(T data)
{
	dll.SetDataByIndex(data, index++);
}
template <typename T>
T Stack<T>::Pop()
{
	return dll.GetDataByIndex(--index);
}
template <typename T>
T Stack<T>::Peek()
{
	if (!isEmpty())
		return dll.GetDataByIndex(index - 1);
}

template <typename T>
int Stack<T>::getIndex()
{
	return index;
}


int main()
{
	Stack<int> stack(5);

	for (int i = 0; i < 5; i++)
		stack.Push(rand() % 100);

	for (int i = 0; i < 3; i++)
		cout << stack.Pop() << " ";
	cout << endl;

	cout << stack.Peek() << " == ";
	cout << stack.Pop() << endl;

	return 0;
}