// 21118 DSL Assignment: 7
// Shubham Chemate (E - 1)

// The ticket booking system of Cinemax theater has to be
// implemented using C++ program. There are 10 rows and 7
// seats in each row. Doubly circular linked list has to be
// maintained to keep track of free seats at rows. Assume
// some random booking to start with. Use array to store
// pointers (Head pointer) to each row. On demand
// a) The list of available seats is to be displayed
// b) The seats are to be booked
// c) The booking can be cancelled.

#include <bits/stdc++.h>

using namespace std;

// This represent each individual seat in a theatre.
class Seat {
private:
	int seat_no;
	bool isBooked;
	string pers_name;
	Seat *next, *prev;
public:
	Seat(int seat_no, string pers_name = "", bool isBooked = false) {
		this->seat_no = seat_no;
		this->pers_name = pers_name;
		this->isBooked = isBooked;
		this->next = this;
		this->prev = this;
	}
	friend class TheaterRow;
};

// This is Circular Doubly Linked List. It represent rows in a theatre.
class TheaterRow {
private:
	Seat* head;
	int total_seats;
public:
	TheaterRow() {
		head = NULL;
		total_seats = 0;
	}
	// add empty seat to the end of the row
	void addSeat() {
		total_seats += 1;
		Seat* newSeat = new Seat(total_seats);
		if (head == NULL) head = newSeat;
		else {
			head->prev->next = newSeat;
			newSeat->next = head;
			newSeat->prev = head->prev;
			head->prev = newSeat;
		}
	}
	// updates seat details, returns true on success else false
	bool updateSeatDet(int seat_no, string pers_name, bool isBooked) {
		if (seat_no > total_seats) return false;
		Seat* temp = head;
		while (temp->next != head && temp->seat_no != seat_no) temp = temp->next;
		if (temp->seat_no == seat_no) {
			if (temp->isBooked == isBooked) return false;
			temp->pers_name = pers_name;
			temp->isBooked = isBooked;
			return true;
		}
		else return false;
	}
	void PrintSeatDet(int seat_no) {
		Seat* temp = head;
		while (temp->next != head && temp->seat_no != seat_no) temp = temp->next;
		if (temp->seat_no == seat_no) {
			if (temp->isBooked == false)
				cout << "--The seat is not booked.--\n";
			else {
				cout << "Name: " << temp->pers_name << endl;
			}
		}
		else cout << "**Check seat details again.**\n";
	}
	void PrintBookings() {
		Seat* temp = head;
		if (!temp) {
			cout << "**Empty Row.**\n";
			return;
		}
		do {
			temp->isBooked ? cout << setw(12) << "Booked" : cout << setw(12) << "Not Booked";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}
};

// This class represents entire theatre.
class Theatre {
private:
	int rows, columns;
	TheaterRow *theatre_rows;
public:
	Theatre(int rows = 10, int columns = 7) {
		this->rows = rows;
		this->columns = columns;

		// Adding seats in each row of theatre
		theatre_rows = new TheaterRow[rows];
		for (int i = 0; i < rows; i++)
			for (int j = 1; j <= columns; j++)
				theatre_rows[i].addSeat();
	}
	void bookSeat(int r, int c, string pers_name) {
		if (r > rows || c > columns)
			cout << "**Check seat number again. It may not exist.**\n";
		else {
			theatre_rows[r - 1].updateSeatDet(c, pers_name, true) ?
			cout << "--Seat is booked sucessfully.--\n" :
			     cout << "**Seat is already occupied. Please check other available options.**\n";

		}
	}
	void cancelBooking(int r, int c) {
		if (r > rows || c > columns)
			cout << "**Check seat number again. It may not exist.**\n";
		else {
			theatre_rows[r - 1].updateSeatDet(c, "", false) ?
			cout << "--Booking is cancelled sucessfully.--\n" :
			     cout << "**Check seat status again.**\n" ;
		}
	}
	void PrintSeatData(int r, int c) {
		if (r > rows || c > columns)
			cout << "**Check again.**\n";
		else {
			cout << "The details of seat are as follows:\n";
			cout << "Row: " << r << " Col: " << c << endl;
			theatre_rows[r - 1].PrintSeatDet(c);
		}
	}
	void PrintBookingStat() {
		cout << "--The status of booking is as follows:\n";
		for (int i = 0; i < rows; i++) {
			cout << "Row: " << setw(2) << i + 1 << " =>";
			theatre_rows[i].PrintBookings();
		}
	}
};

int main() {
	Theatre th;
	while (true) {
		cout << "\nWhat do you want to do?\n";
		cout << "\t1 for showing status of theatre\n";
		cout << "\t2 for booking seat\n";
		cout <<	"\t3 for cancel booking of seat\n";
		cout <<	"\t4 for show the details of specific seat\n";
		cout << "\t0 to exit\n:";
		int choice;
		cin >> choice;
		if (choice == 0) break;
		else if (choice == 1) th.PrintBookingStat();
		else if (choice == 2) {
			int row, column;
			cout << "Enter row number: "; cin >> row;
			cout << "Enter column number: "; cin >> column;
			string name;
			cout << "Enter name of person: "; cin >> name;
			th.bookSeat(row, column, name);
		}
		else if (choice == 3) {
			int row, column;
			cout << "Enter row number: "; cin >> row;
			cout << "Enter column number: "; cin >> column;
			th.cancelBooking(row, column);
		}
		else if (choice == 4) {
			int row, column;
			cout << "Enter row number: "; cin >> row;
			cout << "Enter column number: "; cin >> column;
			th.PrintSeatData(row, column);
		}
		else cout << "**INVALID CHOICE. Enter again.**";
	}
	return 0;
}