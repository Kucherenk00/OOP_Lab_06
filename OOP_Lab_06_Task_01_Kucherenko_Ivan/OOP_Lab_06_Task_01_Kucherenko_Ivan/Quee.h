
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
