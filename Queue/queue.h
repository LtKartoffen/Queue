// queue.h -- interface for queue
#ifndef QUEUE_H_
#define QUEUE_H_

// Queue is filled with Customers
class Customer
{
private:
	long arrive;				// appears of client
	int processtime;			// time to process client
public:
	Customer()
	{
		arrive = processtime = 0;
	}
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node
	{
		Item item;
		struct Node* next;
	};
	enum{Q_SIZE = 10};

	// Locked members of class
	Node* front;					// pointer to beginning of Queue
	Node* rear;						// pointer to ending of Queue
	int items;						// count of customers in Queue
	const int qsize;				// maximum customers

	// declaration for not using constructor of copy
	Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};
#endif // !QUEUE_H_
