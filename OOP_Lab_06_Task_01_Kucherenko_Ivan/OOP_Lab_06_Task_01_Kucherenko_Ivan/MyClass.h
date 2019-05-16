
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