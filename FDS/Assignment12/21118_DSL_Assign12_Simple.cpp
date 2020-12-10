// DSL Assignment - 12 by Shubham (Roll No. 21118)

#include <iostream>

using namespace std;

const int D = 3;

class Job {
private:
	string data;
	int priority;
public:
	Job(string data="", int priority=0) {
		this->data = data;
		this->priority = priority;
	}
	void setData() {
		cout << "Enter data: "; cin >> data;
		cout << "Enter Priority: "; cin >> priority;
	}
	string getData() {
		return data;
	}
	int getPriority() {
		return priority;
	}
	friend bool operator <= (Job , Job );
	friend ostream& operator << (ostream& dout, Job i);
};

bool operator <= (Job i1, Job i2) {
	return (i1.priority <= i2.priority);
}

ostream& operator << (ostream& dout, Job i) {
	dout << "Data: " << i.data << endl;
	dout << "Priority: " << i.priority << endl;
	return dout;
}

// priority queue implementation
template <class T>
class PriorityQueue {
private:
	T arr[D];
	int front, rear;
public:
	PriorityQueue() {
		front = 0;
		rear = 0;
	}
	bool isEmpty() { return (front == rear); }
	bool isFull() { return ((rear + 1) % D == front); }
	T getFront() {
		return arr[(front+1) % D]; 
	}
	void insert(T x) {
		if (isFull()) return;
		rear = (rear + 1) % D;
		arr[rear] = x;
		//shift the current element to appropriate position
		for (int i = rear; i != front+1; i = (D + i - 1) % D)
			if (arr[(D + i - 1) % D] <= arr[i])
				swap (arr[i], arr[(D + i - 1) % D]);
	}
	void remove() {
		if (isEmpty()) return;
		front = (front + 1) % D;
	}
	void Print() {
		if (isEmpty()) {
			cout << "Empty List.\n";
			return;
		}

		for (int i = front + 1; ; i = (i + 1) % D) {
			cout << arr[i];
			if (i == rear) break;
		}
	}
};

int main() {
	PriorityQueue<Job> pq;

	while (true) {
		cout << "\nWhat do you want to do??\n";
		cout << "Enter\n\t1 to add in the list.\n\t2 to get from the list.\n\t3 to remove from the list.\n";
		cout << "\t4 to print list\n\t0 to exit.\n:";
		int choice = 0; cin >> choice;
		if (choice == 1) {
			if (pq.isFull())
				cout << "Queue is full.\n";
			else {
				Job temp_Job;
				temp_Job.setData();
				pq.insert(temp_Job);
				cout << "Job added Successfully\n";
			}
		}
		else if (choice == 2) {
			if (pq.isEmpty())
				cout << "List is empty.\n";
			else 
				cout << pq.getFront();
		}
		else if (choice == 3) {
			if (pq.isEmpty()) cout << "List is empty.\n";
			else {
				pq.remove();
				cout << "Removed Successfully.\n";
			}
		}
		else if (choice == 4) {
			cout << "The List is:\n";
			pq.Print();
		}
		else if (choice == 0)
			break;
		else 
			cout << "INVALID INPUT. Try Again.\n";
	}

	return 0;
}