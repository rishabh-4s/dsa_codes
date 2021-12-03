#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// que 0
// add element to map/increase the count, if count > 1 then kaam ka nhi hai element
string removeDuplicates(string s)
{
    string res = "";
    unordered_map<char, int> paaji;

    for (int i = 0; i < s.length(); i++)
    {

        paaji[s[i]]++;
        if (paaji[s[i]] == 1)
            res += s[i];
    }
    return res;
}

// que 1
// sabko map mein daal do
// fir element ko +1 krke check krte rho for sequence
void longestSeq(int arr[], int n)
{
    unordered_map<int, bool> paaji;
    for (int i = 0; i < n; i++)
    {
        paaji[arr[i]] = true;
    }
    int count = 0, first = 0, last = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 1;
        int m = arr[i];
        int tfirst = m;
        int tlast = m;
        while (true)
        {
            if (paaji[m + 1] == true)
            {
                temp++;
                m++;
                tlast = m;
            }
            else
                break;
        }
        if (temp > count)
        {
            count = temp;
            first = tfirst;
            last = tlast;
        }
    }
    cout << first << " " << last;
}

// que 2
// +k and -k krke search krlo ezpz

// que 3
// find the -ve of the element and if mil gya toh remove both from the map and count++ :)

int main()
{
    //string s = "aaabbcadc";
    //cout << removeDuplicates(s);
    int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    longestSeq(arr, 13);
}