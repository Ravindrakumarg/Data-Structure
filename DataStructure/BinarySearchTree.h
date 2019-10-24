#include "BSTNode.h"
#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#define INORDER 1
#define PREORDER 0
#define POSTORDER 0


template <typename T>
BSTNode<T>* BinarySearchTree<T>::get_root()
{
    return root;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::new_node(T _data)
{
    return new BSTNode<T>(_data);
}

template <typename T>
void BinarySearchTree<T>::set_root(BSTNode<T>* _root)
{
    root = _root;
}

template <typename T>
bool BinarySearchTree<T>::is_bst_empty()
{
    if(get_root() == nullptr)
        return true;
    else
        return false;
}

template <typename T>
void BinarySearchTree<T>::display()
{
    if(is_bst_empty())
        cout << "BST is empty"<<endl;
    else
    {
        if(INORDER)
        {
            cout << "BST In-Order List:";
            display_tree_inorder(get_root());
            cout <<endl;
        }
        if(PREORDER)
        {
            cout << "BST Pre-Order List:";
            display_tree_preorder(get_root());
            cout <<endl;
        }
        if(POSTORDER)
        {
            cout << "BST Post-Order List:";
            display_tree_postorder(get_root());
            cout <<endl;
        }
    }
}

template<typename T>
inline void BinarySearchTree<T>::display_tree(BSTNode<T>*)
{
}

template <typename T>
void BinarySearchTree<T>::display_tree_inorder(BSTNode<T>* node)
{
    if(!node)
        return;
    display_tree_inorder(node->left);
    cout << node->data << " ";
    display_tree_inorder(node->right);
}

template <typename T>
void BinarySearchTree<T>::display_tree_preorder(BSTNode<T>* node)
{
    if(!node)
        return;
    cout << node->data << " ";
    display_tree_inorder(node->left);
    display_tree_inorder(node->right);
}

template <typename T>
void BinarySearchTree<T>::display_tree_postorder(BSTNode<T>* node)
{
    if(!node)
        return;
    display_tree_inorder(node->left);
    display_tree_inorder(node->right);
    cout << node->data << " ";
}

template <typename T>
void BinarySearchTree<T>::add_node(T _data)
{
    if(is_bst_empty())
    {
        set_root(new_node(_data));
    }
    else
    {
        BSTNode<T>* temp = get_root();
        BSTNode<T>* ptemp = nullptr;

        while(temp)
        {
            ptemp = temp;
            if(_data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if(ptemp->data > _data)
            ptemp->left = new_node(_data);
        else
            ptemp->right = new_node(_data);
    }
}

template <typename T>
void BinarySearchTree<T>::search_node(T _data)
{
    if(is_bst_empty())
        cout << "BST is empty"<<endl;
    else
    {
        BSTNode<T>* temp = get_root();
        bool flag =  false;
        while(temp)
        {
            if(temp->data == _data)
            {
                flag =true;
                break;
            }
            if(temp->data > _data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if(flag)
            cout << "Search "<<_data<<" : Data found"<<endl;
        else
            cout << "Search "<<_data<<" : Data not found"<<endl;
    }
}

template <typename T>
void BinarySearchTree<T>::delete_node(T _data)
{
    if(is_bst_empty())
        cout << "BST is empty"<<endl;
    else
    {
        BSTNode<T>* temp = get_root();
        BSTNode<T>* ptemp = nullptr;
        while(temp)
        {
            if(temp->data == _data)
                break;
            else if(temp->data > _data)
            {
                ptemp = temp;
                temp = temp->left;
            }
            else
            {
                ptemp = temp;
                temp = temp->right;
            }
        }
        if(!temp)
            cout << "Delete "<<_data<<": Data not found in BST"<<endl;
        else
        {
            if(temp->left == nullptr && temp->right == nullptr)
            {
                if(ptemp->data > temp->data)
                    ptemp->left = nullptr;
                else
                    ptemp->right = nullptr;

                delete temp;
                temp = nullptr;
            }
            else if(temp->left == nullptr)
            {
                if(ptemp->data > temp->data)
                    ptemp->left = temp->right;
                else
                    ptemp->right = temp->right;

                delete temp;
                temp = nullptr;
            }
            else if(temp->right == nullptr)
            {
                if(ptemp->data > temp->data)
                    ptemp->left = temp->left;
                else
                    ptemp->right = temp->left;

                delete temp;
                temp = nullptr;
            }
            else
            {
                BSTNode<T>* smallest_head = find_last_node(temp);

                if(smallest_head->right)
                {
                    temp->data = smallest_head->right->data;
                    delete(smallest_head->right);
                    smallest_head->right = nullptr;
                }
                else
                {
                    temp->data = smallest_head->left->data;
                    delete(smallest_head->left);
                    smallest_head->left = nullptr;
                }
            }
            cout <<"Delete "<<_data<<" : Successfully deleted"<<endl;
        }
    }
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::find_last_node(BSTNode<T>* head)
{
    BSTNode<T>* ptemp, pptemp;
    ptemp = head;
    while(head)
    {
        if(head->right)
        {
            ptemp = head;
            head=head->right;
        }
        else if(head->left)
        {
            ptemp = head;
            head=head->left;
        }
        else
            break;
    }

    return ptemp;
}
#endif // BINARYSEARCHTREE_H_INCLUDED
