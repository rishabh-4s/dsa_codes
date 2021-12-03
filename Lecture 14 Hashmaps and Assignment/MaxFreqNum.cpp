#include <iostream>
#include <unordered_map>

using namespace std;

int maxFreqNum(int arr[], int n)
{
    unordered_map<int, int> hello;
    for (int i = 0; i < n; i++)
    {
        hello[arr[i]]++;
    }
    int max_count = 0, res = -1;
    for (auto i : hello)
    {
        if (max_count < i.second)
        {
            res = i.first;
            max_count = i.second;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 1, 3, 5};
    cout << maxFreqNum(arr, 4);
}