#include "BSTTest.h"

BSTTest::BSTTest()
{

}

BSTTest::~BSTTest()
{

}

void BSTTest::Test()
{
    BinarySearchTree<int> bst;
    bst.Add(50);
    bst.Add(30);
    bst.Add(70);
    bst.Add(20);
    bst.Add(40);
    bst.Add(60);
    bst.Add(80);
    bst.Add(90);
    bst.Add(10);
    bst.Add(100);
    bst.Add(65);
    bst.Add(68);
    bst.Add(63);
    bst.Add(62);
    bst.Show(bst.GetRoot());
    std::cout<<std::endl;
    if(bst.Find(50) )
        std::cout<<"Element Exist!"<<std::endl;
    else
        std::cout<<"Element Doesn't Exist!"<<std::endl;
    bst.Show(bst.GetRoot());
    std::cout<<std::endl;
    std::cout<<"MIN  : "<<bst.MinTree(bst.GetRoot())->data<<std::endl;
    std::cout<<"MAX : "<<bst.MaxTree(bst.GetRoot())->data<<std::endl;
    std::cout<<"MIN DEPTH : "<<bst.MinDepth(bst.GetRoot())<<std::endl;
    std::cout<<"MAX DEPTH : "<<bst.MaxDepth(bst.GetRoot())<<std::endl;
    std::cout<<bst.IsBalanced(bst.GetRoot())<<std::endl;
    if(bst.IsBST(bst.GetRoot()))
        std::cout<<"Tree is a BST Tree"<<std::endl;
    else
        std::cout<<"Tree is NOT a BST Tree"<<std::endl;
    std::cout<<"LCA : "<<bst.FindCommonAncestor(bst.GetRoot(), bst.GetRef(10), bst.GetRef(65))->data<<std::endl;
    std::cout<<"Level : "<<bst.GetLevel(bst.GetRef(20))<<" "<<bst.GetLevel(bst.GetRef(80))<<std::endl;
    std::cout<<"Parent : "<<bst.GetParent(bst.GetRef(20))->data<<" "<<bst.GetParent(bst.GetRef(80))->data<<std::endl;
    if(bst.FindCousin(bst.GetRef(65), bst.GetRef(80)) )
        std::cout<<"Cousin"<<std::endl;
    else
        std::cout<<"Not Cousin"<<std::endl;\
    bst.PathFinder(68);
    std::cout<<"BST Size: "<<bst.Size(bst.GetRoot())<<std::endl;
    std::cout<<"Successor: "<<bst.FindSuccessor(68)<<std::endl;
    std::cout<<"Predecessor: "<<bst.FindPredecessor(62)<<std::endl;
    std::cout<<"Nth Max: "<<bst.FindNthMaximum(bst.GetRoot(), 3)<<std::endl;
    std::cout<<"Nth Min: "<<bst.FindNthMinimum(bst.GetRoot(), 3)<<std::endl;
    bst.Remove(70);
    bst.Remove(40);
    bst.Remove(63);
    bst.Show(bst.GetRoot());
}
