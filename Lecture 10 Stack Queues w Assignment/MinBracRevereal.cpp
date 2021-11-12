#include <iostream>
#include <string>
#include <stack>
using namespace std;

int minBracRev(string s)
{
    stack<char> stack;
    int countopen = 0;
    int countclosed = 0;

    if (s.length() % 2 != 0)
        return -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            stack.push(s[i]);
            countopen++;
        }

        else if (!stack.empty())
        {
            stack.pop();
            countclosed++;
        }
    }

    return stack.size() / 2;
}
int main()
{
    string s;
    cin >> s;
    cout << minBracRev(s);
}