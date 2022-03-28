// queue.cpp -- Customer's and Queue's methods
#include "queue.h"
#include <cstdlib>	
// Queue's methods
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

// Add Customer in queue
bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node;		// creating node
	add->item = item;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

// Setting front's element in variable item and then deleting from queue
bool Queue::dequeue(Item& item)
{
	if (front == nullptr)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}

// Customer's method
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}