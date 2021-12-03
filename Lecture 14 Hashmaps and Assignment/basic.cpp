#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
functions to be implemented
1 insert
2 get value
3 delete

->can be implemented using linked list 
complexity O(n)
bas node different bna denge jisme key and value store hogi
->can also be implemented using array but traversal would still be O(n)
->bst se implement kr sakte hai, complexity would be O(logn)
// but still its not good enough, we want O(1)
*/

/*
-> inbuilt maps
2 types 
1) maps
iske almost saare functions log(n) ke honge
2) unoredered maps
implemented using hashtables 
functions -> O(1)
*/

vector<int> removeDuplicates(vector<int> arr)
{
    vector<int> res;
    unordered_map<int, bool> dekhaHua;
    // agar count 0 se zyada hua toh aage badh jayenge vrna push kr denge res mein
    for (int i = 0; i < arr.size(); i++)
    {
        if (dekhaHua.count(arr[i]) > 0)
            continue;
    
    dekhaHua[arr[i]] =  true;
    res.push_back(arr[i]);
    }
    return res;
}

int main()
{
    unordered_map<string, int> ourmap;
    
    // insert (key, value)
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2; // (key, value) = ("def, 2")
    
    // find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    // check if key present or not (best way to check, yahi use krna)
    if (ourmap.count("ghi") > 0)
        cout << "ghi is present" << endl;

    //delete
    ourmap.erase("ghi");    
    return 0;
}
