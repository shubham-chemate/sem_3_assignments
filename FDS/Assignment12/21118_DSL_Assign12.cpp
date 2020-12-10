// DSL Assignment - 12 by Shubham (Roll No. 21118)

#include <iostream>

using namespace std;

const int D = 100;

class Info {
private:
	string data;
	int priority;
public:
	Info(string data = "", int priority = 0) {
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
	friend bool operator <= (Info , Info );
	friend ostream& operator << (ostream& dout, Info i);
};

bool operator <= (Info i1, Info i2) {
	return (i1.priority <= i2.priority);
}

ostream& operator << (ostream& dout, Info i) {
	dout << "Data: " << i.data << endl;
	dout << "Priority: " << i.priority << endl;
	return dout;
}

// max - heap implementation
template <class T>
class PriorityQueue {
private:
	T arr[D];
	int n;
public:
	PriorityQueue() { n = 0; }
	int getSize() { return n; }
	bool isEmpty() { return (n < 1); }
	bool isFull() { return (n == D); }
	T Top() { return arr[0]; }
	void Push(T x) {
		if (!isFull()) {
			n++;
			arr[n - 1] = x;
			BubbleUp(n - 1);
		}
	}
	void Pop() {
		if (isEmpty()) return;
		swap(arr[0], arr[n - 1]);
		n--;
		Bubbledown(0);
	}
	void BubbleUp(int i) {
		int parent = (i - 1) / 2;
		while (parent != -1 && i > 0 && arr[parent] <= arr[i]) {
			swap(arr[i], arr[parent]);
			i = parent;
			parent = (i - 1) / 2;
		}
	}
	void Bubbledown(int i) {
		if (i >= n) return;

		int left_child = 2 * i + 1;
		int right_child = 2 * i + 2;
		int largest = i;
		if (left_child < n && arr[i] <= arr[left_child])
			largest = left_child;
		if (right_child < n && arr[largest] <= arr[right_child])
			largest = right_child;
		if (largest != i) {
			swap (arr[i], arr[largest]);
			Bubbledown(largest);
		}
	}
	void Print() {
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
	}
};

int main() {
	PriorityQueue<Info> pq;
	// srand(time(0));

	// cout << "Pushing..\n";
	// for (int i = 0; i < 10; i++) {
	// 	Info temp_info("ABC", rand() % 10);
	// 	pq.Push(temp_info);
	// }

	// pq.Print();

	// cout << "\n\nPopping..\n";
	// while (!pq.isEmpty()) {
	// 	cout << pq.Top();
	// 	pq.Pop();
	// }
	// cout << endl;

	while (true) {
		cout << "What do you want to do??\n";
		cout << "Enter\n\t1 to add in the list.\n\t2 to get from the list.\n\t3 to remove from the list.\n\t0 to exit.\n:";
		int choice = 0; cin >> choice;
		if (choice == 1) {
			Info temp_info;
			temp_info.setData();
			pq.Push(temp_info);
		}
		else if (choice == 2) {
			if (pq.isEmpty())
				cout << "List is empty.\n";
			else
				cout << pq.Top();
		}
		else if (choice == 3) {
			pq.Pop();
			cout << "Removed Successfully.\n";
		}
		else if (choice == 0)
			break;
		else
			cout << "INVALID INPUT. Try Again.\n";
	}

	return 0;
}