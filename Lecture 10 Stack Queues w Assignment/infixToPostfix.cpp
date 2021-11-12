#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // empty function
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // insert function
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "stack overflow" << endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // delete function
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // returns the top element
    int top()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return INT_MIN;
        }

        return data[nextIndex - 1];
    }
};

//function for the precedence of the operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// function for infix to postfix conversion
void infixToPostfix(string s)
{

    int l;
    l = s.length();

    StackUsingArray s1(l);
    string final;

    for (int i = 0; i < l; i++)
    {

        char c = s[i];

        //for operands
        if (c >= 'A' && c <= 'Z')
            final += c;

        //if c is (
        else if (c == '(')
            s1.push('(');


        //if c is )
        else if (c == ')')
        {
            while (s1.top() != '(')
            {
                final += s1.top();
                s1.pop();
            }
            s1.pop();
        }

        //operator other than ( and )
        else
        {
            while (!s1.isEmpty() && prec(s[i]) <= prec(s1.top()))
            {
                final += s1.top();
                s1.pop();
            }
            s1.push(c);
        }
    }

    //poping rest of the elements form the stack
    while (!s1.isEmpty())
    {
        final += s1.top();
        s1.pop();
    }

    cout << final << endl;
}

int main()
{
    string s;
    cin >> s;
    infixToPostfix(s);
    return 0;
}
