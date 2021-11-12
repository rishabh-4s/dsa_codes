#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
private:
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

    // size function
    int size()
    {
        return nextIndex;
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
            cout << "stack full" << endl;
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
            cout << "stack is epmty" << endl;
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
            cout << "stack is epmty" << endl;
            return INT_MIN;
        }
        
        return data[nextIndex - 1];
        
    }

};
