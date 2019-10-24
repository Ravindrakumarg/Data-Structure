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
Node<T>* BinarySearchTree<T>::NewNode(T data)
{
    return new Node<T>(data);
}

template<typename T>
void BinarySearchTree<T>::Add(Node<T>* rt, T data)
{
    if(rt == nullptr)
    {
        rt = NewNode(data);
        return;
    }


    if(rt->data < data)
        Add(rt->left, data);
    else
        Add(rt->right, data);

}

template<typename T>
void BinarySearchTree<T>::Remove(Node<T>* rt, T data)
{

}

template<typename T>
void BinarySearchTree<T>::LookUp(Node<T>* rt, T data)
{

}

template<typename T>
void BinarySearchTree<T>::ShowBST(Node<T>* rt)
{
    if(rt == nullptr)
        return;

    /*In-Order traversal data display*/
    ShowBST(rt->left);
    std::cout<<rt->data<<std::endl;
    ShowBST(rt->right);
}
