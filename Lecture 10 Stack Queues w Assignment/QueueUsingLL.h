#include <iostream>
#include "node.cpp"
using namespace std;
class Queue
{
private:
    node *head;
    node *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void push(int data)
    {
        node *newNode = new node(data);
        if (head = NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void pop()
    {
        if (head == NULL)
            return;
        node *temp = head;
        head = head->next;
        delete temp;
        
        if (head = NULL){
            tail = NULL;
        }
        size--;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int peek()
    {
        return head->data;
    }
};
