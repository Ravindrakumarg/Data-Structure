#include "BinarySearchTree.h"

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    this->root = nullptr;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
}

template<typename T>
bool BinarySearchTree<T>::IsEmpty()
{
    if(this->root == nullptr)
        return true;
    else
        return false;
}

template<typename T>
int BinarySearchTree<T>::Size(Node<T>* rt)
{
    if(rt == nullptr)
        return 0;
    if(rt->left == nullptr && rt->right == nullptr)
        return 1;

    int leftSize  = Size(rt->left);
    int rightSize = Size(rt->right);

    return leftSize + 1 + rightSize;
}

template<typename T>
Node<T>* BinarySearchTree<T>::GetRef(T element)
{
    return Find(element);
}

template<typename T>
Node<T>* BinarySearchTree<T>::GetParent(Node<T>* node)
{
    Node<T>* rt = this->GetRoot();
    Node<T>* parent = nullptr;

    if(node == nullptr)
        return nullptr;

    while(rt != node)
    {
        parent = rt;
        if(node->data < rt->data)
            rt = rt->left;
        else
            rt = rt->right;
    }

    return parent;
}

template<typename T>
int BinarySearchTree<T>::GetLevel(Node<T>* node)
{
    Node<T>* rt = this->GetRoot();
    int level = 0;

    if(node == nullptr)
        std::cout<<"Node doesn't exist in BST::";
    else
    {
        while(rt != nullptr)
        {
            if(rt->data == node->data)
                break;

            if(node->data < rt->data)
                rt = rt->left;
            else
                rt = rt->right;

            level++;
        }
    }

    return level;
}

template<typename T>
void BinarySearchTree<T>::CleanUp(Node<T>* rt)
{
    if(rt != nullptr)
    {
        CleanUp(rt->left);
        CleanUp(rt->right);
        delete rt;
    }
}

template<typename T>
void BinarySearchTree<T>::Show(Node<T>* rt)
{
    if(rt == nullptr)
        return;

    /*Recursive In-Order traversal data display*/
    Show(rt->left);
    std::cout<<rt->data<<" ";
    Show(rt->right);

}

template<typename T>
void BinarySearchTree<T>::Add(T data)
{
    if(IsEmpty())
    {
        this->root = new Node<T>(data);
        return;
    }

    Node<T>* rt = this->root;
    while(true)
    {
        if(data <= rt->data)
        {
           if(rt->left != nullptr)
                rt = rt->left;
           else
           {
               rt->left = new Node<T>(data);
               break;
           }
        }
        else
        {
           if(rt->right != nullptr)
                rt = rt->right;
           else
           {
               rt->right = new Node<T>(data);
               break;
           }
        }
    }
}

template<typename T>
void BinarySearchTree<T>::Remove(T data) //This Remove function works with links manipulation
{                                        //with attaching, detaching links instead of replacing element.
    Node<T>* rt = this->GetRoot();
    Node<T>* parent = nullptr;

    try
    {
        if(IsEmpty())
        {
          const std::string exc = "BST is empty";
          throw exc;
        }

        /*Finds the deleted node*/
        while(true)
        {
            if(rt == nullptr)
            {
                const std::string exc = "Data not found";
                throw exc;
            }

            if(rt->data == data)
                break;

            if(data <= rt->data)
            {
                parent = rt;
                rt = rt->left;
            }
            else
            {
                parent = rt;
                rt = rt->right;
            }

        }

        /*Case 1 : Deleted node don't have child or is a leaf node*/
        if(rt->left == nullptr && rt->right == nullptr)
        {
            if(parent->data >= rt->data)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            delete rt;
        }

        /*Case 2 : Deleted node have both child.*/
        else if(rt->left != nullptr && rt->right != nullptr)
        {
            Node<T>* subtree = rt->left;

            if(subtree->right == nullptr)
            {
                if(rt->data <= parent->data)
                    parent->left = subtree;
                else
                    parent->right= subtree;

                if(rt->right != nullptr)
                {
                    subtree->right = rt->right;
                    rt->right = nullptr;
                }
            }
            else
            {
                Node<T>* subtreeParent = nullptr;
                while(subtree->right != nullptr)
                {
                    subtreeParent = subtree;
                    subtree = subtree->right;
                }


                Node<T>* temp = subtree;
                subtreeParent->right = nullptr;

                temp->left = rt->left;
                rt->left = nullptr;

                temp->right = rt->right;
                rt->right = nullptr;

                if(rt->data <= parent->data)
                    parent->left = temp;
                else
                    parent->right = temp;
                }

                delete rt;
        }

        /*Case 3 : Deleted node have one child.*/
        else
        {
            if(rt->left != nullptr)               //if "the one child" is a left child of deleted node.
            {
                if(parent->data >= rt->data)      //if "rt" node is a left child of parent node.
                    parent->left = rt->left;      //then set parent left child to left child of "rt" node.
                else
                    parent->right = rt->left;     //other set parent right child to left child of "rt" node.
            }
            else                                  //if "the one child" is a right child of deleted node.
            {
                if(parent->data >= rt->data)      //if "rt" node is a left child of parent node.
                    parent->left = rt->right;     //then set parent left child to right child of "rt" node.
                else
                    parent->right = rt->right;    //other set parent right child to right child of "rt" node.
            }

            delete rt; //Dispose the "rt" node memory;
        }
    }
    catch(const std::string& str)
    {
        std::cout<<str<<std::endl;
    }
}

template<typename T>
Node<T>* BinarySearchTree<T>::Find(T data)
{
    Node<T>* rt = this->GetRoot();

    while(rt != nullptr)
    {
        if(rt->data == data)
            break;

        if(data <= rt->data)
            rt = rt->left;
        else
            rt = rt->right;
    }

    return rt;
}

template<typename T>
Node<T>* BinarySearchTree<T>::MinTree(Node<T>* rt)
{
    if(IsEmpty())
        return nullptr;

    while(rt->left != nullptr)
        rt = rt->left;

    return rt;
}

template<typename T>
Node<T>* BinarySearchTree<T>::MaxTree(Node<T>* rt)
{
    if(IsEmpty())
        return nullptr;

    while(rt->right != nullptr)
        rt = rt->right;

    return rt;
}

template<typename T>
int BinarySearchTree<T>::MinDepth(Node<T>* rt)
{
    if(rt == nullptr || (rt->left == nullptr && rt->right == nullptr))
        return 0;

    int leftDepth  = MinDepth(rt->left);
    int rightDepth = MinDepth(rt->right);

    return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
}

template<typename T>
int BinarySearchTree<T>::MaxDepth(Node<T>* rt)
{
    if(rt == nullptr || (rt->left == nullptr && rt->right == nullptr))
        return 0;

    int leftDepth  = MaxDepth(rt->left);
    int rightDepth = MaxDepth(rt->right);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

template<typename T>
bool BinarySearchTree<T>::IsBST(Node<T>* rt)
{
    static int minData = MinTree(rt)->data; //Initialize with minimum element.

    if(rt == nullptr)
        return true;

    IsBST(rt->left);

    if(minData <= rt->data) //As it's a In-Order traversal which traverse BST in Ascending order of elements.
        minData = rt->data;  //So just verify if the last element is less than or equal to the current element.
    else
        return false;

    IsBST(rt->right);

    return true;
}

template<typename T>
std::string BinarySearchTree<T>::IsBalanced(Node<T>* rt)
{
    try
    {
        if(IsEmpty())
            throw  "BST is Empty";

        if(MaxDepth(rt) - MinDepth(rt) <= 1)
            return "BST is balanced";
        else
            return "BST is NOT balanced";
    }
    catch(const char* ex)
    {
       std::cout<<"Exception : "<<ex<<std::endl;
    }
}

template<typename T>
Node<T>* BinarySearchTree<T>::FindCommonAncestor(Node<T>* rt, Node<T>* first, Node<T>* second)
{
    if(rt == nullptr)
        return nullptr;

    if(rt->left  == first || rt->left  == second ||
       rt->right == first || rt->right == second ) return rt;

    Node<T>* left  = FindCommonAncestor(rt->left,  first, second);
    Node<T>* right = FindCommonAncestor(rt->right, first, second);

    if(left && right)
        return rt;

    return (left != nullptr) ? left : right;
}

template<typename T>
bool BinarySearchTree<T>::FindCousin(Node<T>* first, Node<T>* second)
{
    //1. Both node should not be same.
    //2. Both node should belong to same level.
    //3. Both node should not have common parent.
    //4. Both node's parent's parent are same.

    if(first == second)
        return false;

    if(GetLevel(first) != GetLevel(second))
        return false;

    if(GetParent(first) == GetParent(second))
        return false;

    if(GetParent(GetParent(first)) != GetParent(GetParent(second)))
        return false;

    return true;
}

template<typename T>
void BinarySearchTree<T>::PathFinder(T data)
{
    Node<T>* rt = this->GetRoot();
    if(rt == nullptr)
        return;

    std::vector<T> path;
    bool isPathExist = false;

    while(rt != nullptr)
    {
        path.push_back(rt->data);
        if(rt->data == data)
        {
           isPathExist = true;
           break;
        }

        if(data < rt->data)
            rt = rt->left;
        else
            rt = rt->right;
    }

    if(isPathExist)
    {
        std::cout<<"Path : ";
        for(T v : path)
            std::cout<<v<<" ";
        std::cout<<std::endl;
    }
    else
        std::cout<<"Path doesn't exist to "<<data<<std::endl;

    path.clear();
}

template<typename T>
T BinarySearchTree<T>::FindSuccessor(T data)
{
    Node<T>* rt = GetRoot();
    if(rt == nullptr)
        std::cout<<"BST is Empty"<<std::endl;

    while(rt != nullptr)
    {
        if(rt->data == data)
            break;

        if(data < rt->data)
            rt = rt->left;
        else
            rt = rt->right;
    }

    if(rt->right != nullptr)
        return MinTree(rt->right)->data;

    Node<T>* parent = GetParent(GetRef(data));
    while(parent->data < data)
        parent = GetParent(parent);

    return parent->data;
}

template<typename T>
T BinarySearchTree<T>::FindPredecessor(T data)
{
    Node<T>* rt = GetRoot();
    if(rt == nullptr)
        std::cout<<"BST is Empty"<<std::endl;

    while(rt != nullptr)
    {
        if(rt->data == data)
            break;

        if(data < rt->data)
            rt = rt->left;
        else
            rt = rt->right;
    }

    if(rt->left != nullptr)
        return MaxTree(rt->left)->data;

    Node<T>* parent = GetParent(GetRef(data));
    while(parent->data > data)
        parent = GetParent(parent);

    return parent->data;
}

template<typename T>
T BinarySearchTree<T>::FindNthMaximum(Node<T>* rt, int n)
{
    static std::vector<T> temp;
    if(rt == nullptr)
        return 0;

    FindNthMaximum(rt->right, n);
    temp.push_back(rt->data);
    FindNthMaximum(rt->left, n);

    return temp[n-1];
}

template<typename T>
T BinarySearchTree<T>::FindNthMinimum(Node<T>* rt, int n)
{
    static std::vector<T> temp;
    if(rt == nullptr)
        return 0;

    FindNthMinimum(rt->left, n);
    temp.push_back(rt->data);
    FindNthMinimum(rt->right, n);

    return temp[n-1];
}

template<typename T>
void BinarySearchTree<T>::BFS()
{
}

template<typename T>
void BinarySearchTree<T>::DFS()
{
}