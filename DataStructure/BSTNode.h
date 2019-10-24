#ifndef BSTNODE_H_INCLUDED
#define BSTNODE_H_INCLUDED

template <typename T>
class BSTNode
{
public:
    BSTNode<T>* left;
    T data;
    BSTNode<T>* right;
    BSTNode()
    {
        left = nullptr;
        data = 0;
        right = nullptr;
    }
    BSTNode(T _data)
    {
        left = nullptr;
        data = _data;
        right = nullptr;
    }
};

template <typename T>
class BinaryTree
{
public:
    BinaryTree()
    {
        root = nullptr;
    }
    ~BinaryTree()
    {
        delete root;
        root = nullptr;
    }
    void add_node(T _data);
    void search_node(T _data);
    void display_tree_preorder(BSTNode<T>*);
    void display_tree_inorder(BSTNode<T>*);
    void display_tree_postorder(BSTNode<T>*);
    void display();
    void delete_node(T _data);

private:
    BSTNode<T>* get_root();
    BSTNode<T>* new_node(T _data);
    void set_root(BSTNode<T>* _root);
    bool is_bt_empty();

private:
    BSTNode<T>* root;
};

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree()
    {
        root = nullptr;
    }
    ~BinarySearchTree()
    {
        delete root;
        root = nullptr;
    }
    void add_node(T _data);
    void search_node(T _data);
    void display();
    void display_tree(BSTNode<T>*);
    void delete_node(T _data);
    void display_tree_inorder(BSTNode<T>*);
    void display_tree_preorder(BSTNode<T>*);
    void display_tree_postorder(BSTNode<T>*);
    BSTNode<T>* find_last_node(BSTNode<T>*);

private:
    BSTNode<T>* get_root();
    BSTNode<T>* new_node(T _data);
    void set_root(BSTNode<T>* _root);
    bool is_bst_empty();

private:
    BSTNode<T>* root;
};

#include "BinaryTree.h"
#include "BinarySearchTree.h"

#endif // BSTNODE_H_INCLUDED
