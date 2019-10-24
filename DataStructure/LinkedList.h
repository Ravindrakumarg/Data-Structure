#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(T _data)
    {
        data = _data;
        next = nullptr;
    }
};

template <typename T>
class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
    }
    void add_node(T _data);
    void display_list(string msg="");
    void search_node(T _data);
    void delete_node(T _data);
    void reverse_list();
    void NthNode(int index);
    void NthNodeFromEnd(int index);
    void detect_loop();
    void remove_loop();
    Node<T>* find_middle_node();
    void remove_middle_node();
    void check_palindrom();
    void delete_node_address();
    void reverse_partial_list(Node<T>*);
    void swap_pair_node();
    void find_intersection();

private:
    //helper methods
    inline Node<T>* get_head();
    inline void set_head(Node<T>* node);
    inline bool is_list_empty();
    inline int find_size();

private:
    Node<T> *head;
};

#include "LinkedListImpl.h"

#endif