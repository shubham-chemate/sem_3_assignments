#include<iostream>
#include<string>

using namespace std;

class Stack
{
    int top;
    char stack[20];
    int max = 20;
public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()              //checks for empty stack
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()               //checks if top is greater than maximum
    {
        if (top >= max)
        {
            return true;
        }
        return false;

    }

    void push(char e)               //pushes a character to the stack
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            stack[top] = e;
        }

    }

    char pop()                      //pops the stack
    {
        if (isEmpty())
        {
            cout << "Stack is empty, nothing to pop" << endl;
            return ' ';
        }
        else
        {
            top--;
            return stack[top];
        }

    }

};

class Expression
{
    string exp;
public:

    Expression()
    {
        exp = "";
    }
    Expression(string str)
    {
        exp = str;
    }

    int count(char x)
    {
        int count = 0;
        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] == x)
            {
                count++;
            }
        }
        return count;
    }

    bool isAMatch(char x)
    {
        if (x == '(')
        {
            if (count('(') == count(')'))
            {
                return true;
            }
            return false;
        }
        else if (x == '{')
        {
            if (count('{') == count('}'))
            {
                return true;
            }
            return false;
        }
        else
        {
            if (count('[') == count(']'))
            {
                return true;
            }
            return false;
        }



    }

    void validateExpression()
    {
        Stack S;
        int flag = 0;
        for (int i = 0; i < exp.length(); i++)
        {
            switch (exp[i])
            {
            case '(':
                S.push(exp[i]);
                break;

            case '[':
                S.push(exp[i]);
                break;

            case '{':
                S.push(exp[i]);
                break;

            case ')':

                if (!isAMatch('('))
                {
                    flag = 1;
                }
                else if (S.isEmpty())
                {
                    flag = 1;
                    break;
                }
                else
                {
                    S.pop();
                }
                break;

            case ']':
                if (!isAMatch('['))
                {
                    flag = 1;
                    //cout<<" no match!";
                }
                else if (S.isEmpty())
                {
                    flag = 1;
                    break;
                }
                else
                {
                    S.pop();
                }
                break;

            case '}':
                if (!isAMatch('{'))
                {
                    flag = 1;
                }
                else if (S.isEmpty())
                {
                    flag = 1;
                    break;
                }
                else
                {
                    S.pop();
                }
                break;

            }

        }
        if (flag == 0 && S.isEmpty())
        {
            cout << "Valid parenthesis" << endl;
        }
        else
        {
            cout << "Invalid parenthesis!" << endl;
        }
    }


};


int main()
{
    string str;
    cout << "Enter expression to be validated :";
    cin >> str;

    Expression e(str);                      //object of expression class that has function for checking for valid expressions

    e.validateExpression();

    return 0;

}
