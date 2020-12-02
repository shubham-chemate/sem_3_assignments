// In any language program mostly syntax error occurs due to
// unbalancing delimiter such as (),{},[]. Write C++ program
// using stack to check whether given expression is well parenthesized
// or not.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int D = 100;

//============= character stack ===================
class Stack {
private:
	char arr[D];
	int top;
public:
	Stack() {
		top = -1;
	}
	void Push(char ch) {
		top++;
		if (top < D)
			arr[top] = ch;
		else
			top--;
	}
	void Pop() {
		if (top >= 0)
			top--;
	}
	bool isEmpty() {
		return top == -1;
	}
	char Top() {
		if (top >= 0)
			return arr[top];
		else
			return ' ';
	}
};

//==============================================


//========== Valid Parentheses Code ============

bool isOpening(char ch) {
	return (ch == '(' ||
	        ch == '[' ||
	        ch == '{');
}

bool isClosing(char ch) {
	return (ch == ')' ||
	        ch == ']' ||
	        ch == '}');
}

bool areMatching(char open, char close) {
	return ((open == '(' && close == ')') ||
	        (open == '[' && close == ']') ||
	        (open == '{' && close == '}'));
}

bool checkParen(string exp) {
	Stack stk;

	int n = exp.length();
	for (int i = 0; i < n; i++) {
		if (isOpening(exp[i])) {
			stk.Push(exp[i]);
		}
		else if (isClosing(exp[i])) {
			if (stk.isEmpty())
				return false;
			char open = stk.Top();
			stk.Pop();
			if (!areMatching(open, exp[i]))
				return false;
		}
	}

	if (!stk.isEmpty())
		return false;
	else
		return true;
}

// ================================================

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	string exp; cin >> exp;

	checkParen(exp) ?
	cout << "Balanced\n" :
	     cout << "Not Balanced\n";

	return 0;
}