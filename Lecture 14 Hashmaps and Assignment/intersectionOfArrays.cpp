#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void intersection(int arr[], int brr[], int n, int m)
{

    unordered_map<int, int> paaji;

    // first arrya ko map mein daal denge with key being the element and the value being the count of the element
    for (int i = 0; i < n; i++)
        paaji[arr[i]]++;
    // then second array traverse karenge, agar map mein element hoga toh count-- kar denge aur print it
    // if count 0 ho gya toh map mein se element erase kr denge
    for (int i = 0; i < m; i++)
    {
        if (paaji.count(brr[i]))
        {
            cout << brr[i] << " ";
            paaji[brr[i]]--;
        }
        if (paaji[brr[i]] == 0)
            paaji.erase(brr[i]);
    }
    cout << endl;
}
int main()
{
    int arr[] = {1, 2, 2, 3, 4, 5};
    int brr[] = {2, 2, 4, 5, 6, 7};
    intersection(arr, brr, 6, 6);
}