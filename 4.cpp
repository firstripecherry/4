#include <iostream>
using namespace std;
template<typename T> 
classQueue
{
public:
	 Queue();
	~Queue();
	void delete_unit();
	void push(T data);
	void clear();
	int GetSize() { return Size; } 


 T& operator[](const int index);

private:
	template<typename T> 
	class Node {
	public:
		Node* pNext; 
		T data;
		Node(T data = T(), Node* pNext = nullptr) { 
			this->data = data;
			this->pNext = pNext;


		}
	};
	int Size;
	Node<T>* head;

};
template<typename T> 
Queue<T>::Queue() { 
	Size = 0;
	head = nullptr;
}
template<typename T> 
Queue<T>::~Queue() {
	clear();
}

template<typename T>
void Queue<T>::delete_unit() 
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;

}

template<typename T>
void Queue<T>::push(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) { 
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}
	Size++;
}

template<typename T>
void Queue<T>::clear()
{
	while (Size > 0) {
		pop_front();
	}
}



template<typename T>
T& Queue<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}











int main()
{
	Queue<int> q;
	q.push(5);
	q.push(10);
	q.push(22);
	q.delete_unit();
	cout << q.operator[](0);
	q.clear;
}
