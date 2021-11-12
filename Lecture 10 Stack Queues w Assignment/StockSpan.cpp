#include <iostream>
#include <stack>
//#define n 1000
using namespace std;

void stockSpan(int arr[], int n, int res[])
{
    stack<int> s;
    s.push(0);
    res[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            s.pop();
        }
        // agar stack empty ho gya toh iska matlab voh element ab tak sabse bda hai
        if (s.empty())
        {
            res[i] = i + 1;
        }
        // else voh top ke baad waale saare elements se bda hai
        else
        {
            res[i] = i - s.top();
        }
    }
}
int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};

    int res[7];
    stockSpan(arr, 7, res);
    for (int i = 0; i < 7; i++)
    {
        cout << res[i] << " ";
    }
}