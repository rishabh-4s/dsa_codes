#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkRedundantBrac(string s)
{
    stack<char> stack;
    
    for (int i = 0; i < s.length(); i++)
    {
        int count = 0;
        //pushing elements to the stack until we find a closing bracket
        if (s[i] != ')')
        {
            stack.push(s[i]);
        }
        //when we encounter a closing bracket, pop all the elements till we find an opening bracket and count the elements between them
        else
        {
            while (stack.top() != '(')
            {
                stack.pop();
                count++;
            }
            stack.pop();
            if (count <= 1)
                return 1;
        }
    }
    return 0;
}

int main(){
    string s;
    cin >> s;
    cout << checkRedundantBrac(s);
}