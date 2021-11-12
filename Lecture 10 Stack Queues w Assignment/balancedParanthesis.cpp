#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool ballancedParanthesis(string s)
{
    stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack.push(s[i]);
            //cout << s[i];
        }
        else if (s[i] == ')')
        {
            if (stack.top() == '(')
                stack.pop();
            else
                return 0;
        }
        else if (s[i] == '}')
        {
            if (stack.top() == '{')
                stack.pop();
            else
                return 0;
        }
        else if (s[i] == ']')
        {
            if (stack.top() == '[')
                stack.pop();
            else
                return 0;
        }
    }
    return 1;
}
int main()
{
    string s;
    cin >> s;
    cout << ballancedParanthesis(s);
}