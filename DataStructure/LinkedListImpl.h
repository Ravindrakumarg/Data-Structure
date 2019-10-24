#include "LinkedList.h"
#include "unordered_set"
#include <string>

template <typename T>
void LinkedList<T>::add_node(T _data)
{
    Node<T>* node = new Node<T>(_data);

    Node<T>* head = get_head();
    if(head == nullptr)
    {
        set_head(node);
    }
    else
    {
        Node<T>* temp = head;
        while(temp->next!=nullptr)
            temp=temp->next;

        temp->next = node;
    }
}

template<typename T>
void LinkedList<T>::display_list(string msg)
{
    Node<T>* temp = get_head();
    if(temp == nullptr)
    {
        cout<< "List is empty"<<endl;
    }
    else
    {
        if(msg == "")
            cout << "List: ";
        else
            std::cout << msg <<": ";

        while(temp)
        {
            cout << temp->data<<" ";
            temp = temp->next;
        }
    }
    cout << endl;
}

template <typename T>
Node<T>* LinkedList<T>::get_head()
{
    return head;
}

template <typename T>
void LinkedList<T>::set_head(Node<T>* node)
{
    head = node;
}

template <typename T>
void LinkedList<T>::search_node(T _data)
{
    cout <<"Searching "<<_data<<": ";

    Node<T>* temp = get_head();
    if(temp==nullptr)
        cout << "List is empty"<<endl;
    else
    {
        while(temp)
        {
            if(temp->data == _data)
            {
                cout << "Data found"<<endl;
                break;
            }
            temp = temp->next;
        }
        if(temp == nullptr)
            cout << "Data not found"<<endl;
    }
}

template <typename T>
void LinkedList<T>::delete_node(T _data)
{
    Node<T>* temp = get_head();
    if(temp == nullptr)
        cout << "List is empty"<<endl;
    else
    {
        Node<T>* ptemp = temp;
        while(temp != nullptr && temp->data != _data)
        {
            ptemp = temp;
            temp = temp->next;
        }
        if(temp == nullptr)
            cout << "Deleting "<<_data<<": Data not found"<<endl;
        else if(temp == get_head())
        {
            set_head(temp->next);
            delete temp;
            temp = nullptr;
            cout << "Deleting "<<_data<<": Deleted Successfully"<<endl;
        }
        else
        {
            ptemp->next = temp->next;
            delete temp;
            temp = nullptr;
            cout << "Deleting "<<_data<<": Deleted Successfully"<<endl;
        }
    }
}

template <typename T>
void LinkedList<T>::reverse_list()
{
    Node<T>* head = get_head();
    if(head == nullptr)
        cout << "Revering List: "<<"List is empty"<<endl;
    else
    {
        Node<T>* current = head;
        Node<T>* next_node = nullptr;
        Node<T>* prev_node = nullptr;
        while(current)
        {
            next_node = current->next;
            current->next = prev_node;
            prev_node = current;
            current = next_node;
        }
        set_head(prev_node);
        cout <<"Reverse List:";
        display_list();
    }
}

template <typename T>
inline bool LinkedList<T>::is_list_empty()
{
    if(get_head()==nullptr)
        return true;
    else
        return false;
}

template <typename T>
void LinkedList<T>::NthNode(int index)
{
    if(is_list_empty() || (index <= 0))
        cout << "List is empty"<<endl;
    else
    {
        Node<T>* temp = get_head();
        int counter = 1;
        while(temp != nullptr)
        {
            if(counter == index)
            {
                cout << "Data at index "<<index<<": "<<temp->data<<endl;
                break;
            }
            counter++;
            temp=temp->next;
        }
        if(counter < index)
            cout << index<<"th Node is not present in list"<<endl;
    }
}

template <typename T>
void LinkedList<T>::NthNodeFromEnd(int index)
{
    if(is_list_empty())
        cout <<"List is empty"<<endl;
    else
    {
        int list_size = find_size();
        int num_node = (list_size+1) - index;
        if(num_node<=0)
            cout << index<<" node from end does not exist, invalid input"<<endl;
        else
        {
            NthNode(num_node);
        }
    }
}

template <typename T>
int LinkedList<T>::find_size()
{
    if(is_list_empty())
        return 0;

    int size =0;
    Node<T>* temp = get_head();
    while(temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

template <typename T>
void LinkedList<T>::detect_loop()
{
    if(is_list_empty())
        cout <<"List is empty"<<endl;

    unordered_set<Node<T>*> node_set;
    Node<T>* temp = get_head();
    bool flag = false;

    temp->next->next->next = temp;

    while(temp)
    {
        if(node_set.find(temp) != node_set.end())
        {
            flag = true;
            break;
        }
        node_set.insert(temp);
        temp = temp->next;
    }
    if(flag)
        cout << "There is loop detected in list"<<endl;
    else
        cout << "There is no loop in list"<<endl;
}

template <typename T>
void LinkedList<T>::remove_loop ()
{
    if(is_list_empty())
        cout <<"List is empty"<<endl;

    unordered_set<Node<T>*> node_set;
    Node<T>* temp = get_head();
    Node<T>* ptemp = nullptr;
    bool flag = false;
    temp->next->next->next = temp;  //adding loop in link list

    while(temp)
    {
        if(node_set.find(temp) != node_set.end())
        {
            ptemp->next = nullptr;
            flag = true;
            break;
        }
        node_set.insert(temp);
        ptemp = temp;
        temp = temp->next;
    }
    if(flag)
        cout << "There is loop detected in list and removed"<<endl;
    else
        cout << "There is no loop in list"<<endl;
}

template <typename T>
Node<T>* LinkedList<T>::find_middle_node()
{
    if(is_list_empty())
    {
        cout <<"List is empty"<<endl;
        return nullptr;
    }

    Node<T>* temp = get_head();
    Node<T>* doubtemp = get_head();

    while(doubtemp)
    {
        if(doubtemp->next != nullptr)
        {
            doubtemp = doubtemp->next->next;
            temp = temp->next;
        }
        else
            break;
    }
    cout << "Middle node: "<<temp->data<< endl;
    return temp;
}

template <typename T>
void LinkedList<T>::remove_middle_node()
{
    if(is_list_empty())
    {
        cout <<"List is empty"<<endl;
        return;
    }

    Node<T>* temp = get_head();
    Node<T>* ptemp = nullptr;
    Node<T>* doubtemp = get_head();
    while(doubtemp)
    {
        if(doubtemp->next != nullptr)
        {
            doubtemp = doubtemp->next->next;
            ptemp = temp;
            temp = temp->next;
        }
        else
            break;
    }

    if(temp == get_head())
    {
        set_head(temp->next);
        delete temp;
        temp = nullptr;
    }
    else
    {
        ptemp->next = temp->next;
        delete temp;
        temp=nullptr;
    }
}

template <typename T>
void LinkedList<T>::check_palindrom()
{
    Node<T>* middle_node = find_middle_node();
    if(middle_node == nullptr)
        cout << "List is empty"<<endl;
    else
    {
        int list_size = find_size();
        display_list("palindrom1");
        if(list_size%2 == 0)
        {
            cout <<"even";
            reverse_partial_list(middle_node);
        }
        else
        {   cout <<"odd";
            reverse_partial_list(middle_node->next);
        }
        display_list("palindrom2");
    }
}

template <typename T>
void LinkedList<T>::reverse_partial_list(Node<T>* temp)
{
    Node<T>* current = temp;
    Node<T>* next_node = nullptr;
    Node<T>* prev_node = nullptr;
    while(current)
    {
        next_node = current->next;
        current->next = prev_node;
        prev_node = current;
        current = next_node;
    }
    temp = prev_node;
}

template <typename T>
void LinkedList<T>::delete_node_address()
{
    Node<T>* node = get_head()->next;
    if(node->next != nullptr)
    {
        Node<T>* next_node = node->next;
        node->next = next_node->next;
        node->data = next_node->data;
        delete next_node;
        next_node = nullptr;
    }
}

template <typename T>
void LinkedList<T>::swap_pair_node()
{
    if(is_list_empty())
        cout <<"List is empty"<<endl;
    else
    {
        Node<T>* temp = get_head();
        Node<T>* ptemp = nullptr;
        Node<T>* nntemp = nullptr;
        while(1)
        {
            if(temp == nullptr || temp->next == nullptr)
                break;
            else if(temp == get_head())
            {
                nntemp = temp->next->next;
                Node<T>* ntemp = temp->next;
                set_head(ntemp);
                ntemp->next = temp;
                temp->next = nntemp;
            }
            else
            {
                nntemp = temp->next->next;
                Node<T>* ntemp = temp->next;
                ptemp->next = ntemp;
                ntemp->next = temp;
                temp->next = nntemp;
            }
            ptemp = temp;
            temp = nntemp;
        }
    }
}

template <typename T>
void LinkedList<T>::find_intersection()
{
}