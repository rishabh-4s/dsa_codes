#include <iostream>
using namespace std;

class simpleQueue
{
private:
    int *data;
    int rear, front, capacity, size;

public:
    simpleQueue(int s)
    {
        data = new int[s];
        rear = -1;
        front = -1;
        size = 0;
        capacity = s;
    }
    
    //returns the number of elements in the queue
    int get_size()
    {
        return size;
    }

    //checks if the queue is empty or not
    bool is_empty()
    {
        return size == 0;
    }
    
    //returns the first element of the queue
    int first_element(){
        if(is_empty()){
            cout << "queue is empty" << endl;
            return 0;
        }
        return data[rear];
    }

    //inserts an element in front of the queue
    void enqueue(int element)
    {
        if (front == capacity - 1)
        {
            cout << "queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            rear = 0;
        }
        front++;
        data[front] = element;
        size++;
    }

    //deletes an element from the rear of the queue and returns it
    int dequeue()
    {
        if (is_empty())
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        int ans = data[rear];
        rear++;
        size--;
        if (size == 0)
        {
            rear = -1;
            front = -1;
        }
        return ans;
    }
};

int main(){
    simpleQueue q(5);
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.get_size() << endl;
    cout << q.first_element() << endl;
    cout << q.dequeue() << endl;
    cout << q.first_element() << endl;
    cout << q.get_size() << endl;

    return 0;
}