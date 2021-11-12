#include <vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*> children; // by default it'll assume the data type of parent. so need to specify T
    //TreeNode<T> *root;

    TreeNode(int data){
        this-> data = data;
    }
};
