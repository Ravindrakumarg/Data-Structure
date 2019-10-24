#ifndef LINKEDLISTTEST_H
#define LINKEDLISTTEST_H

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "BSTNode.h"

using namespace std;

class DataStructureTest
{
public:
	DataStructureTest() {};
	~DataStructureTest() {};
    void testLinkedList();
    void testStack();
    void testBT();
    void testBST();
};

void DataStructureTest::testLinkedList()
{
    cout << "================================="<<endl;
    cout << "Linked List Functionality"<<endl;
    cout << "================================="<<endl;
    LinkedList<int> linked_list;

    linked_list.add_node(10);
    linked_list.add_node(20);
    linked_list.add_node(30);

    linked_list.display_list();

    linked_list.search_node(20);
    linked_list.search_node(50);

    linked_list.delete_node(60);

    linked_list.reverse_list();
    linked_list.NthNode(3);
    linked_list.NthNodeFromEnd(4);

    linked_list.detect_loop();
    linked_list.remove_loop();

    linked_list.add_node(48);
    linked_list.display_list();
    linked_list.find_middle_node();

    linked_list.remove_middle_node();
    linked_list.display_list();

    linked_list.add_node(40);

    linked_list.display_list();
    linked_list.delete_node_address();
    linked_list.display_list();

    linked_list.add_node(88);
    linked_list.add_node(39);
    //linked_list.check_palindrom();

    linked_list.add_node(77);
    linked_list.display_list("swap");
    linked_list.swap_pair_node();
    linked_list.display_list("swap1");
}

void DataStructureTest::testStack()
{
    cout << endl <<"================================="<<endl;
    cout << "Stack Functionality"<<endl;
    cout << "================================="<<endl;

    Stack<int> stack_obj;
    stack_obj.push(10);
    stack_obj.push(30);
    cout <<"PoPed data:" << stack_obj.pop() <<endl;
    stack_obj.push(40);
    stack_obj.push(12);
    stack_obj.push(23);
    stack_obj.push(89);
    stack_obj.display_stack();
    stack_obj.reverse_stack();
    stack_obj.display_stack();
}

void DataStructureTest::testBT()
{
    cout << endl <<"================================="<<endl;
    cout << "Binary Tree Functionality"<<endl;
    cout << "================================="<<endl;
    BinaryTree<int> BT;
    BT.add_node(10);
    BT.add_node(20);
    BT.add_node(30);
    BT.add_node(34);
    BT.add_node(678);
    BT.display();
    BT.search_node(31);
    BT.search_node(34);
    BT.delete_node(37);
    BT.display();
}

void DataStructureTest::testBST()
{
    cout << endl <<"================================="<<endl;
    cout << "Binary Search Tree Functionality"<<endl;
    cout << "================================="<<endl;
    BinarySearchTree<int> bst;
    bst.add_node(10);
    bst.add_node(20);
    bst.add_node(30);
    bst.add_node(8);
    bst.add_node(5);
    bst.add_node(9);
    bst.display();
    bst.search_node(30);
    bst.search_node(11);
    bst.delete_node(20);
    bst.delete_node(5);
    bst.display();
}

#endif
