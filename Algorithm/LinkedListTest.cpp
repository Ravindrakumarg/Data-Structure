#include "LinkedListTest.h"

LinkedListTest::LinkedListTest()
{

}

LinkedListTest::~LinkedListTest()
{

}

void LinkedListTest::Test()
{
    LinkedList<int> linkedList;
    linkedList.Add(10);
    linkedList.Add(20);
    linkedList.Add(30);
    linkedList.Add(40);
    linkedList.Add(50);
    linkedList.AddAtBegining(60);
    linkedList.AddAtMiddle(70);
    linkedList.AddAtMiddle(80);
    linkedList.AddAtNthPosition(90, 3);
    linkedList.AddAtNthPosition(90, 17);

    linkedList.Show(linkedList.GetHead());
    std::cout<<std::endl;
    linkedList.Find(70);

    linkedList.Remove();
    linkedList.Remove();
    linkedList.Show(linkedList.GetHead());
    std::cout<<std::endl;

}
