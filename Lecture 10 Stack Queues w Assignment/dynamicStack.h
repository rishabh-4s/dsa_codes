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
    StackUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
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
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
            
            
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
