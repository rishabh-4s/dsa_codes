#include <iostream>
#include "node.cpp"
using namespace std;

class stackUsingLL
{
    node *head;
    //node *tail;
    int size;

public:
    stackUsingLL()
    {
        head = NULL;
        //tail = NULL;
        size = 0;
    }
    void push(int data)
    {
        node *newNode = new node(data);
        /*
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        */

        newNode->next = head;
        head = newNode; 
        size++;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    int top()
    {
        if (isEmpty())
            return -1;
        return head->data;
    }
    int pop()
    {

        node *temp = head->next;
        /*
        while(temp->next != tail){
            temp = temp->next
        }
        int popp = tail->data;
        delete tail;
        tail = temp;
        return popp;
        */
        int popp = head->data;
        delete head;
        head = temp;
        size--;
        return popp;
    }
    int getsize()
    {
        return size;
    }
};
