#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
    int roll_num;
    string name;
    Node* next;
public:
    Node(int roll_num, string name)
    {
        this->name = name;
        this->roll_num = roll_num;
        next = NULL;
    }
    friend class LinkedList;
    friend class Set;
};

class LinkedList
{
private:
    Node* head;
    Node* getNewNode(int roll_no, string name)
    {
        Node* newNode = new Node(roll_no, name);
        return newNode;
    }
public:
    LinkedList()
    {
        head = NULL;
    }
    void addNode(int roll_num, string name)
    {
        Node* newNode = getNewNode(roll_num, name);
        if (head == NULL) head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    void deleteNode(int x)
    {
        if (head->roll_num == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *curr, *prev;
        curr = head;
        prev = NULL;
        while (curr != NULL && curr->roll_num != x) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) cout << "The student is not present in the list.\n";
        else {
            prev->next = curr->next;
            delete curr;
        }

    }
    bool isPresent(int x)
    {
        Node *temp = head;
        while (temp) {
            if (temp->roll_num == x) return true;
            temp = temp->next;
        }
        return false;
    }
    void Print()
    {
        if (head == NULL) {
            cout << "Empty List.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << "Roll No.: " << temp->roll_num << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    friend class Set;
};

class Set
{
private:
    LinkedList students;
public:
    void getInput()
    {
        cout << "Number of students? ";
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter roll number: ";
            int roll_num; cin >> roll_num;
            cout << "Enter name: ";
            string name; cin >> name;
            if (!students.isPresent(roll_num)) students.addNode(roll_num, name);
            else {
                cout << "Roll number is already present in list. Enter again.\n";
                i--;
            }
        }
    }
    Set getUnion(Set B)
    {
        Set unionSet;
        Node* temp_a = students.head;
        while (temp_a) {
            unionSet.students.addNode(temp_a->roll_num, temp_a->name);
            temp_a = temp_a->next;
        }

        Node* temp_b = B.students.head;
        while (temp_b) {
            if (!students.isPresent(temp_b->roll_num)) unionSet.students.addNode(temp_b->roll_num, temp_b->name);
            temp_b = temp_b->next;
        }
        return unionSet;
    }
    Set getIntersection(Set B)
    {
        Set interSet;
        Node* temp_a = students.head;
        while (temp_a) {
            if (B.students.isPresent(temp_a->roll_num)) interSet.students.addNode(temp_a->roll_num, temp_a->name);
            temp_a = temp_a->next;
        }
        return interSet;
    }
    Set getDiff(Set B)
    {
        Set diffSet;
        Node* temp_a = students.head;
        while (temp_a) {
            if (!B.students.isPresent(temp_a->roll_num)) diffSet.students.addNode(temp_a->roll_num, temp_a->name);
            temp_a = temp_a->next;
        }
        return diffSet;
    }
    void printData()
    {
        students.Print();
    }
};

int main()
{
    Set total_students, vanilla, btrsch;
    cout << "Enter Universal Data:\n";
    total_students.getInput();
    cout << "\nFor vanilla:\n";
    vanilla.getInput();
    cout << "\nFor butterscotch: \n";
    btrsch.getInput();

    cout << "\nVanilla Lovers: \n"; vanilla.printData();
    cout << "Butterscotch Lovers: \n"; btrsch.printData();

    Set vnl_or_btrsch = vanilla.getUnion(btrsch);
    Set vnl_and_btrsch = vanilla.getIntersection(btrsch);

    while (true) {
        cout << "\nEnter\n1 for students who like both vanilla and butterscotch\n";
        cout << "2 for students who like either vanilla or butterscotch but not both\n";
        cout << "3 for students who like neither vanilla nor butterscotch\n:";
        int choice; cin >> choice;

        Set res;
        if (choice == 0) break;
        else if (choice == 1) {
            res = vnl_and_btrsch;
            cout << "Students who like both vanilla and butterscotch: \n";
        }
        else if (choice == 2) {
            res = vnl_or_btrsch.getDiff(vnl_and_btrsch);
            cout << "Students who like either vanilla or butterscotch but not both: \n";
        }
        else {
            res = total_students.getDiff(vnl_or_btrsch);
            cout << "Students who like neither vanilla nor butterscotch: \n";
        }
        res.printData();
    }
    return 0;
}
