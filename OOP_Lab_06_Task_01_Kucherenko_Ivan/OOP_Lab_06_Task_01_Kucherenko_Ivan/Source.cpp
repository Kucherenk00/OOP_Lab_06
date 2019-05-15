#include <iostream>
#pragma once
//27
using namespace std;


int main()
{
	MyClass<int>* queue = new MyClass<int>();

	int item;
	int size;

	Quee<int> quee;
	quee.Add(1);
	quee.DeleteNode();
	quee.PrintQuee();

	size = queue->Size();
	cout << "After creating: size = " << size << endl;
	system("pause");
	return 0;
}


template<typename T>

class MyClass
{
private:
		T value;
		 char ms[100];
		 MyClass<T>* next;

public:

	MyClass(T item, MyClass<T>* next);
	int Size() const;

	void Print()
	{
		cout << "print   " << value << endl;
	}

	const T GetItem() const;
	MyClass<T>* GetNext() const;
	void SetItem(const T item);
	void SetNext(MyClass<T>* next);

	~MyClass();
};

template<typename T> MyClass<T>::MyClass(T item, MyClass<T>* next)
{
	cout << " this->item,this->next " << endl;
	this->item = item;
	this->next = next;
}

template<typename T> MyClass<T>::~MyClass()
{
	cout << "~MyClass()" << endl;
}

template<typename T> void MyClass<T>::SetItem(const T item)
{
	this->item = item;
}

template<typename T> void MyClass<T>::SetNext(MyClass<T>* next)
{
	this->next = next;
}

template<typename T> const T MyClass<T>::GetItem() const
{
	return this->item;
}

template<typename T> MyClass<T>* MyClass<T>::GetNext() const
{
	return this->next;
}

template<typename T>
class Quee
{
public:
	Quee();
	~Quee();

	void Add(T data);
	void DeleteNode();
	void PrintQuee();
	int FindSize();

private:
	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(T data) {
			this->data = data;
			pNext = nullptr;
		}
	};
	Node<T> *head;
	int size;
};

template<typename T>
Quee<T>::Quee()
{
	head = nullptr;
	this->size = 0;

}

template<typename T>
void Quee<T>::Add(T data) {
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = head;
		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		this->size -= 1;
		current->pNext = new Node<T>(data);

	}
	size++;
}
template<typename T>
void Quee<T>::DeleteNode() {
	Node<T> *newFirst = head->pNext;
	delete head;
	head = newFirst;
	size--;
}

template<typename T>
void Quee<T>::PrintQuee() {
	Node<T> *current = head;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->pNext;
	}
}

