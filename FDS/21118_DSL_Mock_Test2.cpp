#include <iostream>
#include <string>

using namespace std;

const int D = 100;

template <class T>
class Stack {
private:
	T arr[D];
	int top;
public:
	Stack() {top = -1;};
	bool isEmpty() {return (top == -1);};
	bool isFull() {return (top + 1 == D); }
	T Top() { return arr[top];};
	void Push(T x) {
		if (!isFull()) arr[++top] = x;
		else cout << "Stack is Full.\n";
	}
	void Pop() {
		if (!isEmpty()) top--;
		else cout << "Stack is empty.\n";
	}
	void PrintStack() {
		if (!isEmpty()) {
			for (int i = 0; i <= top; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
		else cout << "Stack is empty!\n";
	}
};

class Expression {
private:
	string exp;
	bool isOperator(char ch) {
		return (ch == '+' ||
		        ch == '-' ||
		        ch == '*' ||
		        ch == '/');
	}
	bool isOperand(char ch) {
		return (ch <= 'z' && ch >= 'a');
	}
	int getOperatorWt(char ch) {
		if (ch == '+' || ch == '-') return 1;
		else if (ch == '*' || ch == '/') return 2;
		else return -1;
	}
	bool isHigherPrec(char ch1, char ch2) {
		int wt1 = getOperatorWt(ch1);
		int wt2 = getOperatorWt(ch2);
		return (wt1 >= wt2);
	}
	float evaluate(float op1, float op2, char oprt) {
		switch (oprt) {
		case '+':
			return (op1 + op2);
		case '-':
			return (op1 - op2);
		case '*':
			return (op1 * op2);
		case '/':
			return (op1 / op2);
		default:
			return -1;
		}
	}
public:
	Expression(string str = "") {
		exp = str;
	}
	void setExp() {
		cout << "Enter Expression: ";
		while (exp.length() == 0)
			getline (cin, exp);
	}
	string getExp() {return exp;}
	string infixToPostfix() {
		string postfix = "";
		int n = exp.length();
		Stack<char> stk;

		for (int i = 0; i < n; i++) {
			if (isOperand(exp[i])) {
				postfix += exp[i];
				postfix += " ";
			}
			else if (isOperator(exp[i])) {
				while (!stk.isEmpty() && stk.Top() != '(' && isHigherPrec(stk.Top(), exp[i])) {
					postfix += stk.Top();
					postfix += " ";
					stk.Pop();
				}
				stk.Push(exp[i]);
			}
			else if (exp[i] == '(')
				stk.Push('(');
			else if (exp[i] == ')') {
				while (stk.Top() != '(') {
					postfix += stk.Top();
					postfix += " ";
					stk.Pop();
				}
				stk.Pop();
			}
		}

		while (!stk.isEmpty()) {
			postfix += stk.Top();
			postfix += " ";
			stk.Pop();
		}

		return postfix;
	}
	float postfixEvaluation() {
		int n = exp.length();
		if (n == 0) {
			cout << "Enter the expression first.\n";
			return -1.0;
		}

		float operand_val[26] = {0};
		for (int i = 0; i < exp.size(); i++)
			if (isOperand(exp[i]))
				operand_val[exp[i] - 'a'] = -1;

		for (int i = 0; i < 26; i++) {
			if (operand_val[i] == -1) {
				cout << "Enter the value of varible - " << char('a' + i) << ": ";
				cin >> operand_val[i];
			}
		}

		Stack<float> stk;
		for (int i = 0; i < n; i++) {
			if (isOperand(exp[i]))
				stk.Push(operand_val[exp[i] - 'a']);
			else if (isOperator(exp[i])) {
				float op2 = stk.Top(); stk.Pop();
				float op1 = stk.Top(); stk.Pop();
				float res = evaluate(op1, op2, exp[i]);
				stk.Push(res);
			}
		}

		return stk.Top();
	}
};

int main() {
	cout << "Lowercase characters from a to z are expected as operands.\n";
	cout << "+, -, *, / are expected as operators.\n\n";

	while (true) {
		Expression exp;
		exp.setExp();
		cout << "What do you want to do??\n";
		cout << "\tEnter 1 for conversion\n\t2 for postfix evaluation\n:";
		int choice; cin >> choice;
		if (choice == 1) {
			cout << "Postfix form: ";
			cout << exp.infixToPostfix() << endl;
		}
		else if (choice == 2) {
			float val = exp.postfixEvaluation();
			cout << "Value of expression is: " << val << endl;
		}
		else if (choice == 0) break;
		else cout << "INVALID CHOICE. Try Again.\n";
	}
	return 0;
}