#include <iostream>
#include <stack>
using namespace std;

void toBottom(stack<int> &s, int x)
{
    if (s.empty())
        s.push(x);

    else
    {
        int a = s.top();
        s.pop();
        toBottom(s, x);
        s.push(a);
    }
}
void reverseStack(stack<int> &s)
{
    if (!s.empty())
    {
        int topp = s.top();
        s.pop();
        reverseStack(s);
        toBottom(s, topp);
    }
}
void print_stack(stack<int> s)
{
    stack<int> printer = s;
    while (!printer.empty())
    {
        cout << printer.top() << " ";

        printer.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    print_stack(s);
    reverseStack(s);
    print_stack(s);
}
