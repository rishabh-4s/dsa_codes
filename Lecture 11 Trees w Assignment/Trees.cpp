#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "enter num of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

TreeNode<int> *levelWiseInpute()
{
    int rootData;
    cout << "enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter the num of children " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *preOrderInput()
{

    // same as level wise input bas w/o faaltu cout statements

    int rootData;
    //cout << "enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        //cout << "enter the num of children " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            //cout << "enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    cout << root->data << ":";
    // yeh edge case hai, not base case
    if (root == NULL)
        return;

    // loop for printing
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;

    // loop for recursion
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void levelWisePrint(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    cout << root->data << endl;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

int countNodes(TreeNode<int> *root)
{
    int count = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }
    return count;
}

int sumNodes(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumNodes(root->children[i]);
    }
    return sum;
}

int maxNode(TreeNode<int> *root)
{
    int max = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = maxNode(root->children[i]);
        if (max < temp)
            ;
        max = temp;
    }
    return max;
}

int heightOfTree(TreeNode<int> *root)
{

    int max = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int height = heightOfTree(root->children[i]);
        if (height > max)
            max = height;
    }
    return max + 1;
}

void printAtDepth(TreeNode<int> *root, int d)
{

    if (d == 0)
        cout << root->data << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtDepth(root->children[i], d - 1);
    }
}

int numLeaf(TreeNode<int> *root)
{
    int count = 0;
    if (root->children.size() == 0)
        return 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        count += numLeaf(root->children[i]);
    }
    return count;
}

// que 0
bool elementInTree(TreeNode<int> *root, int x)
{

    //check for root
    if (root->data == x)
        return 1;

    // treat chilren of root as trees and use recursion
    for (int i = 0; i < root->children.size(); i++)
    {
        if (elementInTree(root->children[i], x) == 1)
            return 1;
    }
    return 0;
}

// que 1
int nodesGreaterThanX(TreeNode<int> *root, int x)
{

    int count = 0;
    if (root->data > x)
        count++;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += nodesGreaterThanX(root->children[i], x);
    }

    return count;
}

// que 2
int childSum(TreeNode<int> *root)
{
    // return the sum of immediate children and root data
    int childSum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        childSum += root->children[i]->data;
    }
    return childSum + root->data;
}

TreeNode<int> *maXChildSum(TreeNode<int> *root)
{
    TreeNode<int> *max = root;
    int currMax = childSum(root);
    //cout << max->data << " " << currMax << endl;

    // agar current se bda mile then we'll update the maxNode and its sum
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = maXChildSum(root->children[i]);
        if (currMax < childSum(temp))
        {
            max = temp;
            currMax = childSum(temp);
        }
    }
    return max;
}

// que 3
bool checkIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // base case
    if (root1->data != root2->data || root1->children.size() != root2->children.size())
        return 0;

    // agar child tree identical nhi hoga toh we'll return 0
    for (int i = 0; i < root1->children.size(); i++)
    {
        if (!checkIdentical(root1->children[i], root2->children[i]))
            return 0;
    }
    return 1;
}

//que 4
int nextLarger(TreeNode<int> *root, int n)
{
    int next = -1;

    // base case
    if (root->data > n)

        next = root->data;

    // agar n se bda hua and next se chhota only then we'll update
    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = nextLarger(root->children[i], n);
        if (temp > n && next == -1)
            next = temp;
        else if (temp > n && temp <= next && next != -1)
            next = temp;
    }
    return next;
}

// que 5
// gfg code bcoz im fucking lazy and stupid
void secondLargestUtil(TreeNode<int> *root, TreeNode<int> **first, TreeNode<int> **second)
{
    if (root == NULL)
        return;

    // If first is NULL, make root equal to first
    if (!(*first))
        *first = root;

    // if root is greater than first then second
    // will become first and update first equal
    // to root
    else if (root->data > (*first)->data)
    {
        *second = *first;
        *first = root;
    }
    // if second is null, then
    // update first only if root is less than first
    else if (!(*second))
    {
        if (root->data < (*first)->data)
        {
            *second = root;
        }
    }
    // If root is less than first but greater than second
    else if (root->data < (*first)->data && root->data > (*second)->data)
        *second = root;

    // number of children of root
    int numChildren = root->children.size();

    // recursively calling for every child
    for (int i = 0; i < numChildren; i++)
        secondLargestUtil(root->children[i], first, second);
}

TreeNode<int> *secondLargest(TreeNode<int> *root)
{
    // second will store the second highest value
    TreeNode<int> *second = NULL;

    // first will store the largest value in the tree
    TreeNode<int> *first = NULL;

    // calling the helper function
    secondLargestUtil(root, &first, &second);

    if (second == NULL)
        return NULL;

    // return the second largest element
    return second;
}

// que 6
void replaceWithDepthHelper(TreeNode<int> *root, int depth)
{

    root->data = depth;

    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepthHelper(root->children[i], depth + 1);
    }
}
void replaceWithDepth(TreeNode<int> *root)
{
    replaceWithDepthHelper(root, 0);
}

int main()
{
    //TreeNode<int> *root = new TreeNode<int>(1);
    //TreeNode<int> *node1 = new TreeNode<int>(2);
    //TreeNode<int> *node2 = new TreeNode<int>(3);
    //root->children.push_back(node1);
    //root->children.push_back(node2);
    TreeNode<int> *root = preOrderInput();
    //TreeNode<int> *hoot = preOrderInput();
    //levelWisePrint(root);
    cout << nextLarger(root, 3);
    //cout << childSum(root);
    // 1 2 2 3 2 4 5 2 6 7 0 2 8 9 0 0 0 0
    // 1 2 2 3 1 4 1 5 0 0
}
