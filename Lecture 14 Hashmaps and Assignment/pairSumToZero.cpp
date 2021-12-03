#include <iostream>
#include <unordered_map>

using namespace std;

int pariSum(int arr[], int n)
{
    int res = 0;
    unordered_map<int, int> hemlo;
    // pehle saare elements map mein daal lenge
    for (int i = 0; i < n; i++)
    {
        hemlo[arr[i]]++;
    }

    // then we'll again traverse the array and check ki element ka negative map mein hai ya nhi
    // agar hai toh res++ and pair ko map se erase kr denge
    for (int i = 0; i < n; i++)
    {
        if (hemlo[-arr[i]])
        {
            res++;
            hemlo[arr[i]]--;
            hemlo[-arr[i]]--;
        }
    }
    return res;
}
int main()
{
    int arr[] = {2, -2, 3, -3, 1, -1, 6, 7};
    cout << pariSum(arr, 8);
}