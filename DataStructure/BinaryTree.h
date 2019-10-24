#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <queue>

#define INORDER 1
#define PREORDER 0
#define POSTORDER 0

template <typename T>
BSTNode<T>* BinaryTree<T>::get_root()
{
    return root;
}

template <typename T>
BSTNode<T>* BinaryTree<T>::new_node(T _data)
{
    BSTNode<T>* new_node = new BSTNode<T>(_data);
    return new_node;
}

template <typename T>
void BinaryTree<T>::set_root(BSTNode<T>* _root)
{
    root = _root;
}

template <typename T>
bool BinaryTree<T>::is_bt_empty()
{
    if(get_root() == nullptr)
        return true;
    else
        return false;
}

template <typename T>
void BinaryTree<T>::display()
{
    if(is_bt_empty())
        cout << "Binary tree is empty."<<endl;
    else
    {
        if(INORDER)
        {
            cout << "BT In-Order List:";
            display_tree_inorder(get_root());
            cout <<endl;
        }
        if(PREORDER)
        {
            cout << "BT Pre-Order List:";
            display_tree_preorder(get_root());
            cout <<endl;
        }
        if(POSTORDER)
        {
            cout << "BT Post-Order List:";
            display_tree_postorder(get_root());
            cout <<endl;
        }
    }
}

template <typename T>
void BinaryTree<T>::display_tree_preorder(BSTNode<T>* temp)
{
    if(!temp)
        return;
    cout << temp->data << " ";
    display_tree_preorder(temp->left);
    display_tree_preorder(temp->right);
}

template <typename T>
void BinaryTree<T>::display_tree_inorder(BSTNode<T>* temp)
{
    if(!temp)
        return;
    display_tree_inorder(temp->left);
    cout << temp->data << " ";
    display_tree_inorder(temp->right);
}

template <typename T>
void BinaryTree<T>::display_tree_postorder(BSTNode<T>* temp)
{
    if(!temp)
        return;
    display_tree_postorder(temp->left);
    display_tree_postorder(temp->right);
    cout << temp->data << " ";
}

template <typename T>
void BinaryTree<T>::add_node(T _data)
{
    BSTNode<T>* node = new_node(_data);
    if(is_bt_empty())
    {
        set_root(node);
    }
    else
    {
        queue<BSTNode<T>*> que;
        que.push(get_root());

        while(!que.empty())
        {
            BSTNode<T>* temp = que.front();
            que.pop();
            if(temp->left == nullptr)
            {
                temp->left = node;
                break;
            }
            else
                que.push(temp->left);

            if(temp->right == nullptr)
            {
               temp->right = node;
               break;
            }
            else
                que.push(temp->right);
        }
    }
}

template <typename T>
void BinaryTree<T>::search_node(T _data)
{
    if(is_bt_empty())
    {
        cout << "Search "<<_data<<": Tree is empty"<<endl;
    }
    else
    {
        bool flag = false;
        queue<BSTNode<T>*> bt_queue;
        bt_queue.push(get_root());

        while(!bt_queue.empty())
        {
            BSTNode<T>* temp = bt_queue.front();
            bt_queue.pop();

            if(temp->data == _data)
            {
                flag = true;
                break;
            }
            else
            {
                if(temp->left != nullptr)
                    bt_queue.push(temp->left);
                if(temp->right != nullptr)
                    bt_queue.push(temp->right);
            }
        }
        if(flag)
            cout << "Search "<<_data<<": Data found"<<endl;
        else
            cout << "Search "<<_data<<": Data not found"<<endl;
    }
}

template <typename T>
void BinaryTree<T>::delete_node(T _data)
{
    if(is_bt_empty())
    {
        cout << "Delete "<<_data<<": Tree is empty"<<endl;
    }
    else
    {
        bool flag = false;
        queue<BSTNode<T>*> bt_queue;
        bt_queue.push(get_root());

        BSTNode<T>* key_temp = nullptr;
        while(!bt_queue.empty())
        {
            key_temp = bt_queue.front();
            bt_queue.pop();

            if(key_temp->data == _data)
            {
                flag = true;
                break;
            }
            else
            {
                if(key_temp->left != nullptr)
                    bt_queue.push(key_temp->left);
                if(key_temp->right != nullptr)
                    bt_queue.push(key_temp->right);
            }
        }

        if(!flag)
            cout << "Delete "<<_data<<" : Data not found"<<endl;
        else
        {
            //find rightmost node
            queue<BSTNode<T>*> bt_que;
            bt_que.push(get_root());
            BSTNode<T>* temp = nullptr, *ptemp=nullptr;
            while(!bt_que.empty())
            {
                 ptemp = temp;
                 temp = bt_que.front();
                 bt_que.pop();

                 if(temp->right)
                    bt_que.push(temp->right);
                 else if(temp->left)
                    bt_que.push(temp->left);
            }
            key_temp->data = temp->data;
            if(ptemp->left == temp)
                ptemp->left = nullptr;
            else
                ptemp->right = nullptr;

            delete temp;
            temp = nullptr;
            cout << "Delete "<<_data<<" :data found and successfully deleted"<<endl;
        }
    }
}

#endif // BINARYTREE_H_INCLUDED
