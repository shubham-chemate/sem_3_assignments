// FDS assignment - 13 by Shubham (Roll No: 21118)

//        1 2 3 4 5 6 7 8 9
//   front^			   	  ^rear

#include <iostream>

using namespace std;

const int D = 3;

class Dequeue {
private:
	int arr[D];
	int front, rear;
public:
	Dequeue() {
		front = 0, rear = 0;
	}
	bool isEmpty() { return (front == rear);}
	bool isFull() {
		return ((front + D - 1) % D == rear || (rear + 1 ) % D == front);
	}
	void insertFront(int x) {
		if (!isFull()) {
			arr[front] = x;
			front = (front + D - 1) % D;
		}
	}
	void insertRear(int x) {
		if (!isFull()) {
			rear = (rear + 1) % D;
			arr[rear] = x;
		}
	}
	int getFront() {
		if (!isEmpty()) return arr[(front + 1) % D];
		else return -1;
	}
	int getRear() {
		if (!isEmpty()) return arr[rear];
		else return -1;
	}
	void removeFront() {
		if (!isEmpty())
			front = (front + 1) % D;
	}
	void removeRear() {
		if (!isEmpty())
			rear = (rear + D - 1) % D;
	}
	void PrintQu() {
		if (isEmpty()) {
			cout << "Empty List\n";
			return;
		}

		for (int i = (front + 1) % D; ; i = (i + 1) % D) {
			cout << arr[i] << " ";
			if (i == rear) break;
		}
		cout << endl;
	}
};

int main() {

	Dequeue dq;

	while (true) {
		cout << "\nWhat do you want to do??\n";
		cout << "Enter\n\t1 to add to front.\n\t2 to add to rear.\n";
		cout << "\t3 to get front\n\t4 to to get rear.\n";
		cout << "\t5 to remove from front.\n\t6 to remove from rear.\n\t0 to exit.\n:";
		int choice; cin >> choice;

		if (choice == 0) break;
		else if (choice == 1) {
			if (dq.isFull())
				cout << "List is full.\n";
			else {
				cout << "Enter element to add to front: ";
				int x; cin >> x;
				dq.insertFront(x);
			}
		}
		else if (choice == 2) {
			if (dq.isFull())
				cout << "List is full.\n";
			else {
				cout << "Enter element to add to rear: ";
				int x; cin >> x;
				dq.insertRear(x);
			}

		}
		else if (choice == 3) {
			if (dq.isEmpty())
				cout << "Queue is empty.\n";
			else
				cout << dq.getFront() << endl;
		}
		else if (choice == 4) {
			if (dq.isEmpty())
				cout << "Queue is empty.\n";
			else
				cout << dq.getRear() << endl;
		}
		else if (choice == 5) {
			if (dq.isEmpty())
				cout << "Queue is empty.\n";
			else
				dq.removeFront();
		}
		else if (choice == 6) {
			if (dq.isEmpty())
				cout << "Queue is empty.\n";
			else
				dq.removeRear();
		}
		else cout << "INVALID CHOICE. Try Again.\n";

		cout << "Current list is: ";
		dq.PrintQu();
	}

	return 0;
}
