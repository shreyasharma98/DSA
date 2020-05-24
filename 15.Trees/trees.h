#include<vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode*> children;    // vector<TreeNode<T>*> we can also do this but by default it will take the children's type as T...as parent k children ka type same hi hoga!

    TreeNode(T data)
    {
        this->data = data;
    }
};
