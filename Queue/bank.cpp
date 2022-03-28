// bank.cpp -- using Queue's interface
#include <iostream>
#include "queue.h"
#include <cstdlib>			// rand() & srand()
#include <ctime>			// time()
const int MIN_PER_HR = 60;

bool newcustomer(double x);	// new client?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	// Prepare
	std::srand(time(0));
	cout << "Case study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);
	cout << "Enter number of simulation hours: ";
	int hours;
	cin >> hours;

	// Emulation start a 1 cycle in minute
	long cyclelimit = hours * MIN_PER_HR;
	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;
	Item temp;							// data of new client
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	// Start simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 and !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}
	// Out of results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "customers served: " << served << endl;
		cout << "turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "average wait time: "
			<< (double)line_wait / served << "minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}