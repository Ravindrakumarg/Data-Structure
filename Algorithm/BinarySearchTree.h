#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(){}
    Node(T d)
    {
       data  = d;
       left  = nullptr;
       right = nullptr;
    }
};

template<typename T>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        virtual ~BinarySearchTree();

        //Helper Operations
        bool IsEmpty();
        int Size(Node<T>* rt);
        Node<T>* GetRef(T element);
        Node<T>* GetParent(Node<T>* node);
        int GetLevel(Node<T>* node);
        void Show(Node<T>* rt);

        //Basic Operations
        void Add(T data);
        void Remove(T data);
        Node<T>* Find(T data);
        Node<T>* MinTree(Node<T>* rt);
        Node<T>* MaxTree(Node<T>* rt);
        int MinDepth(Node<T>* rt);
        int MaxDepth(Node<T>* rt);
        void CleanUp(Node<T>* rt);

        //Interview Specific
        bool IsBST(Node<T>* rt);
        std::string IsBalanced(Node<T>* rt);
        Node<T>* FindCommonAncestor(Node<T>* rt, Node<T>* first, Node<T>* second);
        bool FindCousin(Node<T>* first, Node<T>* second);
        void PathFinder(T data);
        T FindSuccessor(T data);
        T FindPredecessor(T data);
        T FindNthMaximum(Node<T>* rt, int n);
        T FindNthMinimum(Node<T>* rt, int n);
        void BFS();
        void DFS();


    Node<T>* GetRoot() { return root; }

    protected:
        void SetRoot(Node<T>* root) { this->root = root; }

    private:
        Node<T>* root;

};

#include "BinarySearchTree_Impl.h"

#endif // BINARYSEARCHTREE_H
